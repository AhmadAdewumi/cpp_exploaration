#include <algorithm>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <ios>
#include <iostream>
#include <ostream>
#include <random>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

//-- static member var and fnxtns for auto id generation

enum class EventType { Transaction, Login, Logout, Error, COUNT };

enum class Status { Pending, Successful, Failed };

class Event {
  constexpr std::string_view status_to_string(Status status) const {
    switch (status) {
    case Status::Failed:
      return "Failed";
    case Status::Pending:
      return "Pending";
    case Status::Successful:
      return "Successful";
    }

    return "Unknown";
  }

private:
  std::uint64_t id;
  int value;
  EventType eventType;
  Status status;

  inline static std::unordered_set<std::uint64_t> existing_ids{};
  inline static std::mt19937 rando_number_gen{std::random_device{}()};

  static std::uint64_t generate_unique_id() {
    std::uniform_int_distribution<int> dist{100000, 999999};
    std::uint64_t new_id{};

    do {
      new_id = dist(rando_number_gen);
    } while (existing_ids.count(new_id)); // we retry if collision occurs

    existing_ids.insert(new_id);
    return new_id;
  }

  static int validate_value(int val) {
    if (val < 0) {
      throw std::invalid_argument("Value can't be negative");
    }

    return val;
  }

public:
  Event(EventType suppliedEventType, int initialValue)
      : id{generate_unique_id()}, eventType{suppliedEventType},
        status{Status::Pending}, value{validate_value(initialValue)} {}

  Event(EventType suppliedEventType, Status initialStatus, int initialValue)
      : Event{suppliedEventType, initialValue} {
    status = initialStatus;
  };

  //-- Custom  copy constructor, to take care of id not being duplicated when we
  // copy 2 objects
  // -- we have to force a new id generation during copy and also copy the other
  // stuffs
  Event(const Event &other) {

    if (this !=
        &other) { //-- to protect against self assignment like eventA = eventA
      id = generate_unique_id();
      eventType = other.eventType;
      status = other.status;
      value = other.value;
      // std::cout << "Generate a new unique ID for the object copy with ID: "
      //           << std::to_string(other.id)
      //           << "and the new generated ID is: " << this->id;
    }
  }

  // clean up id after object destruction
  ~Event() { existing_ids.erase(id); }

  //-- define how equality us checked, needed for remove conditions
  bool operator==(const Event &other) const { return id == other.id; }

  // in case we need state equality, say we have a copy of an object, and we
  // need t delete it also that means id equality won't be sufficient
  bool hasSameStateAs(const Event &other) {
    return eventType == other.eventType && status == other.status &&
           value == other.value;
  }

  std::uint64_t getID() const { return id; }
  int getValue() const { return value; }
  EventType getEventType() const { return eventType; }
  Status getStatus() const { return status; }

  void setStatus(Status newStatus) { status = newStatus; }

  void setValue(int newValue) {
    if (newValue < 0) {
      std::cout << "Value can't be negative" << "\n";
      return; //-- to protect against self assignment like eventA = eventA
    }

    value = newValue;
  }

  constexpr std::string_view event_type_to_string(EventType eventType) const {
    switch (eventType) {
    case EventType::Transaction:
      return "Transaction";
    case EventType::Login:
      return "Login";
    case EventType::Logout:
      return "Logout";
    case EventType::Error:
      return "Error";
    }

    return "Unknown";
  }

  std::string to_string() const {
    return "Event{ ID: " + std::to_string(id) +
           ", Status: " + std::string(status_to_string(status)) +
           ", Event Type: " + std::string(event_type_to_string(eventType)) +
           ", Value: " + std::to_string(value);
  }

  friend std::ostream &operator<<(std::ostream &out, const Event &event) {
    return out << event.to_string();
  }
};

template <typename T, typename Compare>
void selection_sort(std::vector<T> &events, Compare compare) {
  for (std::size_t i{0}; i < events.size(); ++i) {
    std::size_t smallest{i};

    for (std::size_t j{i + 1}; j < events.size(); ++j) {
      if (compare(events[j], events[smallest])) {
        smallest = j;
      }
    }

    if (smallest != i) {
      std::swap(events[i], events[smallest]);
    }
  }
}

template <typename T> class EventStore {
private:
  std::vector<T> events;

  //-- add, remove, check if it is empty, access the evenets in there
public:
  class Iterator {
  private:
    typename std::vector<T>::iterator current;

  public:
    Iterator(typename std::vector<T>::iterator it) : current{it} {}
    T &operator*() { return *current; }

    Iterator &operator++() {
      ++current;
      return *this;
    }

    bool operator!=(const Iterator &other) const {
      return current != other.current;
    }
  };

  void add(const T &event) { events.push_back(event); }
  std::size_t size() const { return events.size(); }
  bool isEmpty() { return events.empty(); }

  auto begin() { return Iterator(events.begin()); }
  auto end() { return Iterator(events.end()); }

  void remove(const T &event) {
    //   // std::remove doesn't remove the object, it just point the end to a
    //   new
    //   // logical end
    auto newLogicalEnd = std::remove(events.begin(), events.end(), event);

    //-- erasure happens here
    events.erase(newLogicalEnd, events.end());
  }

  template <typename Compare> void sort(Compare compare) {
    selection_sort(events, compare);
  }

  //-- a bit on pointer arithmetic

  void inspectEventUsingPointers() {
    if (events.empty()) {
      return;
    }

    T *begin =
        events
            .data(); //-- returns a driect pointer to the beginnig of the vector
    T *end = begin + events.size();

    for (T *current = begin; current != end;
         ++current) {                //++current, moves pointer forward
      std::cout << *current << "\n"; //-- we get the T being pointed at
    }
  }
};

//-- forward refencing --woo hoo
template <typename Func> auto benchmark(Func &&func) {
  auto start = std::chrono::steady_clock::now();

  func();

  auto end = std ::chrono::steady_clock::now();

  return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

int main() {
  EventStore<Event> eventStore;

  std::cout << "Check if it's empty: " << std::boolalpha << eventStore.isEmpty()
            << "\n";
  std::cout << "Checking the size: " << eventStore.size() << "\n";

  Event event1{EventType::Transaction, 5000};
  Event event2{EventType::Login, 0};
  Event event3{EventType::Logout, 1};
  Event event4{EventType::Error, Status::Failed, 1000};

  //-- deliberate crash
  // Event event3{EventType::Error, Status::Failed, -1};

  eventStore.add(event1);
  eventStore.add(event2);
  eventStore.add(event3);
  eventStore.add(event4);

  //-- use selection sort here later

  std::cout << "\nAfter adding events: \n";
  std::cout << "Check if it's empty: " << std::boolalpha << eventStore.isEmpty()
            << "\n";
  std::cout << "Checking the size: " << eventStore.size() << "\n";

  //-- before removal
  for (const auto &event : eventStore) {
    std::cout << event << "\n";
  }

  eventStore.remove(event3);

  //-- now iteration
  std::cout << "\nEvents in Store: \n";

  for (const auto &event : eventStore) {
    std::cout << event << "\n";
  }

  //---- BENCHMARKING AND SORTING DEMO ----
  for (int i{0}; i < 1000; ++i) {
    eventStore.add(Event(EventType::Transaction, i));
  }

  std::vector<Event> events;
  for (const auto &event : eventStore) {
    events.push_back(event);
  }

  auto selectionSortTime = benchmark([&]() {
    selection_sort(events, [](const Event &a, const Event &b) {
      return a.getID() < b.getID();
    });
  });

  std::cout << "Selction sort benchmark: " << selectionSortTime.count()
            << " microsecond(us) \n";

  return 0;
}
