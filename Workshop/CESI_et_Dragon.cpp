#include <iostream>
//Workshop 1 et 2 (Partie 3)

/*Question :
1. On va créer constructeur par copie, destructeur dans le Class Creature. On va ajouter un attribut static compteur qui vont ajouter ou enlever 1.*/
class Creature{
    public:
    int pv;
    int pa;
    int niveau;
    static int cpt;

    Creature(){
        pv = 0;
        pa = 0;
        niveau = 0;
        cpt++;
    }

    Creature(int pv1, int pa1, int niv1){
        pv = pv1;
        pa = pa1;
        niveau = niv1;
        cpt +=1;
    }
    Creature(const Creature &c){
        cpt +=1;
    }
    
    ~Creature(){
        cpt -=1;
    }
    void affiche(){
        std::cout<< "Stat de la Creature :" <<std::endl;
        std::cout<<"PV :" << pv <<std::endl;
        std::cout<<"PA :" << pa <<std::endl;
        std::cout<<"Niveau :" << niveau << "\n"<<std::endl;
    }

    double attaque(){
        std ::srand(time(NULL));
        int min = 0;
        int max = 1;
        return (std::rand() % (max - min + 1)+ min) * pa;
    }

    void subitDegat(int degat){
        pv=pv-degat;
    }

    bool estVivant(){
        if (pv > 0) {
            return true;
        }
        return false;
    }

}; 

int Creature::cpt = 0;

class Hero{
    public:
    int pv;
    int pa;
    int niv;
    std::string nom;

    Hero(){
        pv = 1;
        pa = 1;
        nom = "Hero";
        niv=1;
    }

    Hero( std::string nom1, int pv1, int pa1, int niv1){
        pv = pv1;
        pa = pa1;
        nom = nom1;
        niv = niv1;
    }

    void affiche(){
        std::cout<< "Stat du hero, "<< nom << ": " <<std::endl;
        std::cout<<"PV :" << pv <<std::endl;
        std::cout<<"PA :" << pa <<std::endl;
        std::cout<<"Niveau :" << niv << "\n"<<std::endl;
    }

    double attaque(){
        std ::srand(time(NULL));
        int min = 0;
        int max = 1;
        return (std::rand() % (max - min + 1)+ min) * pa;
    }

    void subitDegat(int degat){
        pv=pv-degat;
    }

    bool estVivant(){
        if (pv > 0) {
            return true;
        }
        return false;
    }

}; 

void foo() {
  Creature c3;
  std::cout << "Nombre de créatures: " << Creature::cpt << std::endl;
}
/*
3. Test 1: 
    Nombre de créatures: 2
    Nombre de créatures: 3
    Nombre de créatures: 2
*/
void test1() {
  std::cout << "Test 1: \n";
  Creature c1;
  Creature c2(10, 2, 2);
  std::cout << "Nombre de créatures: " << Creature::cpt << std::endl;
  foo();
  std::cout << "Nombre de créatures: " << Creature::cpt << std::endl;
}

void bar(Creature c1) {
  Creature c2;
  std::cout << "Nombre de créatures: " << Creature::cpt << std::endl;
}

/*3. Test 2:
    Nombre de créatures: 2
    Nombre de créatures: 4
    Nombre de créatures: 2
*/
void test2() {
  std::cout << "Test 2: \n";
  Creature c1;
  Creature c2(10, 2, 2);
  std::cout << "Nombre de créatures: " << Creature::cpt << std::endl;
  bar(c2);
  std::cout << "Nombre de créatures: " << Creature::cpt << std::endl;
}

int main(){
    /*
    std ::srand(time(NULL));
    Hero Hrun ("Hrun",10,10,8);
    Creature Samy(10,10,5);
    Hrun.affiche();
    Samy.affiche();
    int degat = Hrun.attaque();
    Samy.subitDegat(degat);
    degat = Samy.attaque();
    Hrun.subitDegat(degat);
    Samy.affiche();
    Hrun.affiche();
    */
    test1();
    test2();
}
