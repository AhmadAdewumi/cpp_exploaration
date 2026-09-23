#include <ostream>
#include <string_view>
#include <iostream>

enum class Status{
    PENDING,
    SUCCESSFUL,
    FAILED
};

struct Transaction{
    int id;
    int amount;
    Status status;
};

constexpr std::string_view status_to_string(Status status){
    switch (status) {
        case Status::PENDING : return "Pending";
        case Status::SUCCESSFUL : return "Successful";
        case Status::FAILED : return "Failed";
    }

    return "Unknown";
}

void printTransaction(const Transaction& transaction){
    std::cout << "TXN ID: " << transaction.id << "\n";
    
    std::cout << "TXN AMOUNT: " << transaction.amount << "\n";
    
    std::cout << "TXN STATUS: " << status_to_string(transaction.status)<< "\n";
    
}

void markSuccessful(Transaction& transaction){
    transaction.status = Status::SUCCESSFUL;
}

bool isSuccessful(const Transaction& transaction){
    return transaction.status == Status::SUCCESSFUL;
}

Transaction* findTransaction(Transaction* transactions, int count, int id){
    for(int i{0}; i < count; i++){
        if (transactions[i].id == id) {
            return &transactions[i];        
        }
    }

    return nullptr;
}

//-- overloaded stream
std::ostream& operator<<(std::ostream& out, const Transaction& transaction){
    out << "ID: " << transaction.id << " Amount: " << transaction.amount << " Status: " << status_to_string(transaction.status);
    return out;
}

int main(){
    Transaction txn = {
       10001, 5000, Status::PENDING 
    };

    printTransaction(txn);
    markSuccessful(txn);
    std::cout << "Is successful? " << isSuccessful(txn) << "\n";

    Transaction txnArr[]{
        {10001, 5000, Status::PENDING},
        {10002, 12000, Status::FAILED} ,
        {10003, 8500, Status::SUCCESSFUL} ,
        {10004, 4200, Status::FAILED }
    };

    Transaction* result = findTransaction(txnArr, 4, 10004);

    if (result != nullptr) {
        std::cout << "Status of Transaction with ID: " << result->id << " before modification = " << status_to_string(result->status) << "\n";
    }else {
        std::cout << "Transaction not found!!!" << "\n";
        return 1;
    }
    
    result->status = Status::SUCCESSFUL;

    std::cout << "Status of Transaction with ID: " << result->id << " after modification = " << status_to_string(result->status) << "\n";

    std::cout << "TESTING OVERLOADED OUTPUT STREAM FOR THE TRANSACTION TYPE " << "\n";
    std::cout << txn << "\n";
    return 0;
}