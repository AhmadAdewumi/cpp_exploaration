#include <iostream>
#include <string>
#include <string_view>

class BankAccount {
private:
  int balance;
  std::string owner;

public:
  // BankAccount() : balance{0}, owner{"Unknown"} {}

  // BankAccount(std::string ownerName) : balance(0), owner(ownerName) {}

  // BankAccount(int balance, std::string ownerName): balance(balance), owner(ownerName){}
  // 

  //-- wanna play with delegating constructors
  BankAccount(std::string ownerName, int initialBalance) : owner{ownerName}, balance{initialBalance}{}
  BankAccount(std::string ownerName): BankAccount(ownerName, 0){}
  BankAccount(): BankAccount("Unknown", 0){}

  int deposit(int amount){
      if (balance <= 0){
          std::cout << "Amount can't be negative." << "\n";
      }
      return balance+=amount;
  }

  bool withdraw(int amount){
      if (amount <= 0) {
          std::cout << "Withdrawal must be positive." << "\n";
          return false;
      }

      if ( amount > balance) {
          std::cout << "Insufficient funds";
          return false;
      }
      balance-=amount;
      return true;
  }

  int getBalance() const{
      return balance;
  }

  const std::string& getOwner() const{
      return owner;
  }

  // --- friend keyword --- to give access to a specific fnctn or class to our private entities
  // -- say, in our bank custoomers can't go in to view thier account details, but we could give an auditor
  // --- access, so he could check and get back to them
  friend class Auditor;
};

//--- then we define the class outside, and it could access the private members of the BankAccount class
class Auditor{
    public:
        void checkAccDetails(const BankAccount& account){
            std::cout << "Account owner: " << account.owner << "\n";
            std::cout << "Account balance: " << account.balance << "\n";
        }
};