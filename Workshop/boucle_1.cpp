#include <iostream>

class Date {
    public:
    int j;
    int m;
    int a;

    void afficher(){
        std::cout << j <<"/"<< m <<"/" << a << std::endl;

    }
    void incr(){
        
    }
};

int main(){
    Date a;
    a.j = 06;
    a.m = 11;
    a.a = 2026;
    a.afficher();
    return 0;
}