
#include <iomanip>
#include <iostream>
#include <ostream>
#include <random>
#include <utility>

class Tile {
private:
  int m_num;

public:
  // Tile() = default;
  explicit Tile(int num) : m_num{num} {}

  bool is_empty() const { return m_num == 0; }

  int getNum() const { return m_num; }

  friend std::ostream &operator<<(std::ostream &out, const Tile &tile) {
    if (tile.is_empty()) {
      out << "    ";
    } else {
      out << std::setw(3) << tile.getNum();
    }

    return out;
  }
};

class Direction {
  //-- first time moving the member atttributes down, cinvetion broke, wasn't
  // really followingit sha,hahhahaha

public:
  enum Type { Up, Down, Left, Right, maxDirectionCount };

  Direction(Type type) : m_type{type} {}

  Type getType() const { return m_type; }

  //-- tog et adjacent direction
  Direction operator-() const {
    switch (m_type) {
    case Up:
      return Direction::Down;
    case Down:
      return Direction::Up;
    case Left:
      return Direction::Right;
    case Right:
      return Direction::Left;
    default:
      break;
    }

    return Direction::Up;
  }

  static Direction getRandomDirection() {
    static std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution(0, maxDirectionCount - 1);
    return Direction(static_cast<Type>(
        distribution(generator))); // mapping it to the 4 valid directions
  }

private:
  Type m_type;

  friend std::ostream &operator<<(std::ostream &out,
                                  const Direction &direction);
};

std::ostream &operator<<(std::ostream &out, const Direction &direction) {
  switch (direction.getType()) {
  case Direction::Up:
    return (out << "up");
  case Direction::Down:
    return (out << "down");
  case Direction::Left:
    return (out << "left");
  case Direction::Right:
    return (out << "right");
  default:
    break;
  }

  return out << "Unknown direction";
}

class Point {
  //-- this operates as x-> represents column and y-> represents row, just like
  // the co ordinates on a graph
private:
  int m_x;
  int m_y;

public:
  Point(int x, int y) : m_x{x}, m_y{y} {}

  int getX() const { return m_x; }

  int getY() const { return m_y; }

  bool operator==(const Point &other) const {
    return m_x == other.m_x && m_y == other.m_y;
  }

  //-- fir the not equals, we can use the overloaded ==  there
  bool operator!=(const Point &other) const { return !(*this == other); }

  Point getAdjacentPoint(const Direction &direction) const {
    switch (direction.getType()) {
    case Direction::Up:
      return Point{m_x, m_y - 1};
    case Direction::Down:
      return Point{m_x, m_y + 1};
    case Direction::Left:
      return Point{m_x - 1, m_y};
    case Direction::Right:
      return Point{m_x + 1, m_y};
    default:
      break;
    }

    return Point{0, 0};
  }
};

class Board {
private:
  Tile m_tiles[4][4]; //-- y --> rows and x --> cols

public:
  Board()
      : m_tiles{
            {Tile{1}, Tile{2}, Tile{3}, Tile{4}},
            {Tile{5}, Tile{6}, Tile{7}, Tile{8}},
            {Tile{9}, Tile{10}, Tile{11}, Tile{12}},
            {Tile{13}, Tile{14}, Tile{15}, Tile{0}},
        } {}

  friend std::ostream &operator<<(std::ostream &out, const Board &board);

  Point getEmptyTilePosition() const {
    for (int y{0}; y < 4; ++y) {
      for (int x{0}; x < 4; ++x) {
        if (m_tiles[y][x].is_empty()) {
          return Point{x, y};
        }
      }
    }

    return Point{-1, -1};
  }

  static bool isValidTilePosition(Point point) {

    //--todo: fix the bug ehre, wanna see what the error looks like first
    return (point.getX() >= 0 && point.getX() < 4) &&
           (point.getY() >= 0 && point.getY() < 4);
  }

  bool moveTile(const Direction &direction) {
    Point emptyTilePos = getEmptyTilePosition();
    Point adjacentTilePos = emptyTilePos.getAdjacentPoint(-direction);

    if (!isValidTilePosition(adjacentTilePos)) {
      std::cout << "Invalid move";
      return false;
    }

    std::swap(m_tiles[emptyTilePos.getY()][emptyTilePos.getX()],
              m_tiles[adjacentTilePos.getY()][adjacentTilePos.getX()]);

    return true;
  }

  void shuffle() {
    int moves{0};

    while (moves < 1000) {
        Direction direction{Direction::getRandomDirection()};
        if (moveTile(direction)) {
          ++moves;
        }
    }
  }
  
};

std::ostream &operator<<(std::ostream &out, const Board &board) {
  for (auto const &row : board.m_tiles) {
    for (auto const &tile : row) {
      out << tile;
    }

    out << "\n";
  }
  return out;
}

// namespace UserInput {
// char getCommand() {
//   char ch;
//   bool isValid = false;
//
//   while (!isValid) {
//
//     std::cin >> ch;
//     if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd' || ch == 'q') {
//       isValid = true;
//       if (ch == 'q') {
//         std::cout << "Bye!!!" << '\n';
//       } else {
//         std::cout << "Valid command: " << ch << '\n';
//       }
//       return ch;
//     } else {
//       std::cout << "Invalid character! Please, try again!!!" << '\n';
//     }
//   }
//
//   return ch;
// }
namespace UserInput {
char getCommand() {
  char ch;
  while (true) {

    std::cin >> ch;
    if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd' || ch == 'q') {
      return ch;
    } else {
      std::cout << "Invalid command! Use w, a, s, d, q! " << '\n';
    }
  }
}

Direction charToDirection(char ch) {
  switch (ch) {
  case 'w':
    return Direction{Direction::Up};
  case 'a':
    return Direction{Direction::Left};
  case 's':
    return Direction{Direction::Down};
  case 'd':
    return Direction{Direction::Right};
  }

  return Direction{Direction::Up};
}
} // namespace UserInput

int main() {
  Board board{};

  board.shuffle();
  int moves{0};
  // std::cout << board;

  while (true) {
    //-- clear terminal and move cursor to top left
    std::cout << "\033[2J\033[H";

    std::cout << "====================\n";
    std::cout << "Yo!!! It's 15 PUZZLE\n";
    std::cout << "====================\n";

    std::cout << board << "\n";

    std::cout << "Moves: " << moves << "\n";

    std::cout << "[w] Up\n";
    std::cout << "[a] Left\n";
    std::cout << "[s] Down\n";
    std::cout << "[d] Right\n";
    std::cout << "[q] Quit\n";

    std::cout << "Your move: ";

    char command = UserInput::getCommand();

    if (command == 'q') {
      std::cout << "Bye!!!";
      break;
    }

    Direction direction{UserInput::charToDirection(command)};

    if (board.moveTile(direction)) {
        ++moves;
    }

    else {
        std::cout << "\nInvalid Move!!";
        std::cin.get();
    }
  }
}
