#include <cstddef>
#include <iostream>
#include <string_view>
enum class Status{
    Pending, Successful, Failed
};

class Transaction{
    private:
        int id;
        int amount;
        Status status;

    public:
        // a constructor that can be called with one arg can act as a converting constructor
        //-- it is advisable to mark a single arg passing constructor explicit,or a multi param constructor, with one with a default
        // -- value, as it can behave like a constructo called with one arg
        // -- so, that the compiler won't perform uninteded implict auto type convesions
        
        Transaction(int txnId, int txnAmount, Status txnStatus) : id{txnId}, amount{txnAmount}, status{txnStatus}{}
        Transaction() : Transaction(0, 0, Status::Pending) {}

        //-- copy constructor
        Transaction(const Transaction& other) : id{other.id}, amount{other.amount}, status{other.status} {}

        // getters
        int getId() const{
            return id;
        }

        int getAmount() const{
            return amount;
        }

        Status getStatus() const{
            return status;
        }

        //-- pass by refernce when dealing with large object types
        // -- when dealing with small object types or normal primitives, pass by value directly. so it can be
        // -- directly copied into register
        bool processStatus(){
            if (status == Status::Pending) {
                status = Status::Successful;
                return true;
            }

            return false;
        }

        // demonstrate copy constructor stuff
};

constexpr std::string_view status_to_string(Status status){
    switch (status) {
        case Status::Pending: return "Pending";
        case Status::Successful: return "Successful";
        case Status::Failed: return "Failed";
    }
    return "Unknown";
}


int main(){
    Transaction txnA{1001, 5000, Status::Pending};
    Transaction txnB{txnA};

    bool isSuccess = txnA.processStatus();
    std::cout << "Txn A ststus after processing: " << status_to_string(txnA.getStatus()) << " and is success is: " << isSuccess << "\n";
    
    return 0;
}


//-----------------------------
// -- mini practice of template member functions
template<typename T, int Size>
class Repository{
    private:
        T objectType[Size];

    public:
        T& operator[](std::size_t index);
};

//-- without template args passed to the Repositry class, err --> Use of class template 'Repository' requires template arguments (clang template_missing_args)
// --after
template<typename T, int Size>
T& Repository<T, Size>::operator[](std::size_t index){
    return objectType[index];
}

//-----------------------------
