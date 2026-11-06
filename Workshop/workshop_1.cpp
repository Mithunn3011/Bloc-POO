#include <iostream>
#include <cmath>
/*
// Partie 1 du Workshop
class Circle {
    public:
    //Position of the center
    double x;
    double y;

    double r; // radius

    // Set the position of the center
    void set_pos(double new_x, double new_y) {
        x = new_x;
        y = new_y;
    };
    // Calculate the perimeter of the circle
    double perimeter() {
        return 2 * M_PI * r;
    };
    double area(){
        return M_PI * r * r;
    };
};

class Rectangle
{
    public:
    //Position of the top left corner
    double x;
    double y;

    double w; //width
    double h; //height

    // Set the position of the top left corner
    void set_pos(double new_x, double new_y) {
        x = new_x;
        y = new_y;
    };
    
    // Calculate the perimeter of the rectangle
    double perimeter() {
        return 2 *(w + h);
    };

    double area(){
        return w*h;
    };
};


int main() {
    Circle c{0, 0, 1};
    std::cout << c.perimeter() << std::endl;
    std::cout << c.area() << std::endl;
    c.set_pos(1, 1);
    std::cout << "Coordinates of the center: (" << c.x << ", " << c.y << ")" << std::endl;

    Rectangle r{0, 0, 1, 2};
    std::cout << r.area() << std::endl;
    r.set_pos(-1, -1);
    std::cout << "Coordinates of the top left corner: (" << r.x << ", " << r.y << ")" << std::endl;
    return 0;
}
*/


// Partie 2 du Workshop
using namespace std;

class Fraction {
private:
    int numerateur;
    int denominateur;

public:
    // Constructeur par défaut (1/1)
    Fraction() {
        numerateur = 1;
        denominateur = 1;
    }

    // Constructeur avec paramètres
    Fraction(int num, int den) {
        numerateur = num;
        denominateur = den;
    }
    //Setters
    void SetNum(double n) {
        numerateur=n;
    }
    void SetDenum(double d){
        if (d!=0){
            denominateur = d;
        }
    }
    // Getters
    int getNumerateur(){
        return numerateur;
    }

    int getDenominateur(){
        return denominateur;
    }

    void afficher(){
        std::cout<<numerateur<<"/" << denominateur <<std::endl;
    }

    Fraction addition(Fraction& autre){
        int nv_num = (numerateur * autre.denominateur) + (denominateur * autre.numerateur);
        int nv_den = denominateur * autre.denominateur;
        return Fraction(nv_num, nv_den);
    }
    Fraction soustraction(Fraction& autre){
        int nv_num = (numerateur * autre.denominateur) - (denominateur * autre.numerateur);
        int nv_den = denominateur * autre.denominateur;
        return Fraction(nv_num, nv_den);
    }
    Fraction multiplication(Fraction& autre){
        int nv_num = numerateur * autre.numerateur;
        int nv_den = denominateur * autre.denominateur;
        return Fraction(nv_num, nv_den);
    }

    Fraction division(Fraction& autre){
        int nv_num = numerateur * autre.denominateur;
        int nv_den = denominateur * autre.numerateur;
        return Fraction(nv_num, nv_den);
    }
};

int main(){
    Fraction f1;
    f1.afficher();
    Fraction f2(1,0);
    f2.afficher();
    Fraction f3(15,13);
    f3.afficher();
    Fraction somme;
    somme = f1.addition(f3);
    somme.afficher();
    Fraction diff;
    diff = f1.soustraction(f3);
    diff.afficher();
    Fraction produit;
    produit = f1.multiplication(f3);
    produit.afficher();
    Fraction quotient;
    quotient = f1.division(f3);
    quotient.afficher();
}
