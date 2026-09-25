#include <cstddef>
#include <iostream>
#include <optional>
#include <ostream>
#include <random>
#include <string>
#include <string_view>


enum  class Status{ // don't know, have to leave it uncoped to make it compatible with usage in uniform_int_distro
    //-- i can actually do tha, but i have to cast it to int
    PENDING, SUCCESSFUL, FAILED,
    COUNT //-- Just a trick to get the totlal number of enums there
};

constexpr std::string_view status_to_string(Status status);

struct Transaction{
    int id;
    int amount;
    Status status;

    const std::string to_string() const{
        return "Transaction{ ID: " + std::to_string(id) + ", Amount: " + std::to_string(amount) 
        + ", Status: " + std::string(status_to_string(status)) + " }";
    }
};

Status getRandomStatus(){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, static_cast<int>(Status::COUNT) - 1);

    // cating the int to enum and returning
    return static_cast<Status>(distr(gen));
}

constexpr std::string_view status_to_string(Status status){
    switch (status) {
        case Status::PENDING: return "PENDING";
        case Status::SUCCESSFUL: return "SUCCESSFUL";
        case Status::FAILED: return "FAILED";
    }

    return "UNKNOWN";
};

// template<typename T1, typename T2>
// struct Object{
//     int id;
//     T1 firstMember;
//     T2 secondMember;
// };

template<typename T, int Size>
struct Repository{
    // fnxtns
    // -- find an object by ID
    // -- find an object, but read only (by id also)
    // -- print an object by overloading --> operator<<
    // -- after finding an object, the object should be modified using the return pointer
    // -- making the repostiory work with another type, say Repository<Student> or Repository<Player>

    T objectType[Size];
    // int id;
    // 
    T& operator[](std::size_t index){ //-- using size_t, coz it is unsigned here nstead of int, as we are not expecting any -ve
        return objectType[index];
    }

    //-- modifiable search
    T* findObjById(int id){
        for(int i{0}; i < Size; ++i){
            if (objectType[i].id == id) {
                return &objectType[i];
            }
        }
        
        return nullptr;
    }

    // -- read only search , just like the one down there
    const T* findObjById(int id) const{
        for(int i{0}; i < Size; ++i){
            if (objectType[i].id == id) {
                return &objectType[i];
            }
        }
        
        return nullptr;
    }

    // find a read only object
    const T* findReadOnly(const T* obj, int count, int id) const{
        const T* objPtr = findObjById(obj, count , id);
        if (objPtr != nullptr) {
            return objPtr;
        }
        return nullptr;
    }
};

// to print an object by overloading operato<<
// -- the error Overloaded 'operator<<' must be a binary operator (has 3 parameters) occurs becausewe already defined one
// -- in another folder, quite surpised, coz i thougth it will apply if they were in the same class
// -- friend keyword is use to symbolize that it is independent or free fnxtn
// 
// -- will have to write difernt overloade operator for different types, wasn't able to concoct a genric one
std::ostream& operator<<(std::ostream& out, const Transaction& transaction){
    //out << "ID: " << obj.id << " Amount: " << obj.amount << " Status: " << status_to_string(obj.status);
    
    return out << transaction.to_string();
}

int main(){
    Repository<Transaction, 10> txnRepo;

    int initAmount{2000};
    for(int i = 0; i < 10; ++i){
        initAmount += 125;
        txnRepo[i] = {1000+i, initAmount, getRandomStatus()};
    }
    
    Transaction* txn = txnRepo.findObjById(10003);

    if (txn != nullptr) {
        std::cout << "Status of Transaction with ID: " << txn->id << " before modification = " << status_to_string(txn->status) << "\n";
    }else {
        std::cout << "Transaction not found!!!" << "\n";
        return 1;
    }
    
    if (txn) {
        txn->status =Status::PENDING;
    }

    std::cout << "Status of Transaction with ID: " << txn->id << " after modification = " << status_to_string(txn->status) << "\n";


    std::cout << "OVERLOADED OUTPUT STREAM FOR THE TXN OBJECT" << "\n";
    std::cout << *txn << "\n";
}