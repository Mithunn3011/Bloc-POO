#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstdio>

class Texte {
public:
    std::string texte;

    std::string Lire(const std::string& chemin, int taille) {
        FILE* fichier = fopen(chemin.c_str(), "rb");
        if (fichier == nullptr) {
            throw std::runtime_error("Impossible d'ouvrir : " + chemin);
        }
        fseek(fichier, 0, SEEK_SET);
        std::string message = "";
        
        for (int i = 0; i < taille; i++) {
            int c = fgetc(fichier);
            if (c == EOF) {
                break;
            }
            message += static_cast<char>(c);
        }
        fclose(fichier);
        return message;
    }

    void Ecrire(const std::string& chemin, int taille, const std::string& texte) {
        FILE* fichier = fopen(chemin.c_str(), "wb");

        if (fichier == nullptr) {
            throw std::runtime_error("Impossible d'ouvrir : " + chemin);
        }

        for (int i = 0; i < taille && i < static_cast<int>(texte.size()); i++) {
            fprintf(fichier, "%c", texte[i]);
        }
        fclose(fichier);
    }
};

int main() {
    Texte t;
    std::string texte;
    std::cout << "Entre le message que vous voulez mettre dans le fichier : ";
    std::getline(std::cin, texte);
    int taille = texte.size();
    
    t.Ecrire("corbeille_1.txt", taille, texte);
    
    std::string contenuLu = t.Lire("corbeille_1.txt", taille);
    std::cout << "Lu depuis le fichier : " << contenuLu << std::endl;

    return 0;
}