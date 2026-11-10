#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

class Texte {
    public :
    std::string texte;

    std::string Lire(const std::string& chemin){
        std::ifstream fichier(chemin);
        if (!fichier.is_open()) {
            throw std::runtime_error("Impossible d'ouvrir : " + chemin);
        };
        std::stringstream contenu;
        contenu << fichier.rdbuf();
        std::cout << contenu.str() << std::endl; 
        fichier.close();
        return contenu.str();
    }
    void Ecrire (const std::string& chemin, const std::string& texte) {
        std::ofstream fichier(chemin, std::ios::app);

        if (!fichier.is_open()) {
            throw std::runtime_error("Impossible d'ouvrir : " + chemin);
        };
        fichier << texte;
        fichier.close();
    };
    
};

int main(){
    Texte t;
    std::string texte;
    std::cout << "Entre le message que vous voulez mettre dans le fichier :";
    std::getline (std::cin, texte);
    t.Ecrire("corbeille_1.txt", texte + "\n");
    t.Lire("corbeille_1.txt");
    return 0;
};