#include <iostream>

class BankAccount {

private:
   double balance;

public :
    BankAccount(double balance) : balance(balance) {}

    bool retirer(double montant){
        double old_balance = balance;
        balance -= montant;
        if (old_balance > balance){
            return true;
        }
        return false;
    }

    bool deposer(double montant){
        double old_balance = balance;
        balance += montant;
        if (old_balance < balance){
            return true;
        }
        return false;
    }

    double getBalance(){
        return balance;
    }

    void setBalance(const double n_balance){
        balance = n_balance;
    }
};

class Transaction {
private:
 BankAccount* from;
 BankAccount* to;
 double amount;
public:
 Transaction(BankAccount* from, BankAccount* to, double amount) : from(from), to(to), amount(amount) {}
 
 bool execute() {
 from->retirer(amount);
 if (from->getBalance() > 0) {
 to->deposer(amount);
 return true;
 }

 return false;
 }
};


int main() {
 BankAccount* account1 = new BankAccount(1000.0);
 BankAccount* account2 = new BankAccount(500.0);


 Transaction* transaction = new Transaction(account1, account2, 500.0);
 bool res = transaction->execute();
 if (res) {
 std::cout << "Transaction successful" << std::endl;
 } else {
 std::cout << "Transaction failed" << std::endl;
 }
 
 std::cout << account1 << std::endl;
 std::cout << account2 << std::endl;
 delete account1;
 delete account2;
 
 account1 = new BankAccount(1000.0);
 account2 = new BankAccount(500.0);
 transaction = new Transaction(account1, account2, 5000.0);

 res = transaction->execute();
 if (res) {
 std::cout << "Transaction successful" << std::endl;
 } else {
 std::cout << "Transaction failed" << std::endl;
 }
 
 std::cout << account1->getBalance() << std::endl;
 std::cout << account2->getBalance() << std::endl;
 
 return 0;
}