#include <iostream>

/*
//Partie 1
class BankAccount {

private:
   double balance;

public :
    BankAccount(double balance) : balance(balance) {}

    bool retirer(double montant){
        const double old_balance = balance;
        balance -= montant;
        if (old_balance > balance){
            return true;
        }
        return false;
    }

    bool deposer(double montant){
        const double old_balance = balance;
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
*/

//Partie 2
/*
Question : Donnez l'affichage produit par les codes ci-dessous en les évaluant analytiquement puis vérifiez votre réponse en les exécutant

Code 1 : 
A creature has been duplicated
before foo
A creature has been duplicated
foo
A Creature has been destroyed
after foo
A Creature has been destroyed
A Creature has been destroyed

Code 2 :
before foo
foo
A creature has been duplicated
A Creature has been destroyed
after foo
A Creature has been destroyed

Code 3 :
A creature has been duplicated
before bar
bar
A Creature has been destroyed
after bar
A Creature has been destroyed


Code 4 : 
before foo
A creature has been duplicated
A creature has been duplicated
A Creature has been destroyed
foo
after foo
A Creature has been destroyed   
*/

using namespace std;

class Creature {
public:
  Creature() {} // Constructeur par défaut sans paramètre
  Creature(const Creature &c) {
    // Constructeur par copie
    cout << "A creature has been duplicated" << endl;
  }
  ~Creature() {
    // Destructeur
    cout << "A Creature has been destroyed" << endl;
  }
};
/*
//Code 1 
void foo(Creature c) {
  cout << "foo" << endl;
}

int main(int argc, char const *argv[])
{
  Creature ogre;
  Creature shrek = ogre;
  cout << "before foo" << endl;
  foo(shrek);
  cout << "after foo" << endl;
  return 0;
}
*/
/*
//Code 2
void foo(Creature &c) {
  cout << "foo" << endl;
  Creature a = c;
}

int main(int argc, char const *argv[])
{
  Creature ogre;
  cout << "before foo" << endl;
  foo(ogre);
  cout << "after foo" << endl;
  return 0;
}
*/
/*
//Code 3
void bar(Creature* c) {
  cout << "bar" << endl;
  delete c;
}

int main(int argc, char const *argv[])
{
  Creature ogre;
  Creature *shrek = new Creature(ogre);
  cout << "before bar" << endl;
  bar(shrek);
  cout << "after bar" << endl;
  return 0;
}
*/

//Code 4
Creature foo(Creature &c) {
  cout << "foo" << endl;
  Creature local = c;
  return c;
}

int main(int argc, char const *argv[])
{
  Creature ogre;
  cout << "before foo" << endl;
  Creature shrek = foo(ogre);
  cout << "after foo" << endl;
  return 0;
}

/*Questions :
1. Comment fonctionne le passage par valeur ? Quels sont les avantages et inconvénients de ce mode de passage ?
Il est plus facile mais il crée des copie.
2.Comment fonctionne le passage par référence ? Quels sont les avantages et inconvénients de ce mode de passage ?
Il ne crée pas de copie mais il peut entrainer des effets de bord non intentionnels(modif involontaire, manque de visibilité).*/
