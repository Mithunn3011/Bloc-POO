#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
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

class Cesar{
    public :
    int decalage;
    char alphabet_clair[27];
    char alphabet_crypte[27];

    void initialiserAlphabets() {
        for (int i = 0; i < 26; i++) {
            alphabet_clair[i] = static_cast<char>('A' + i);
            alphabet_crypte[i] = static_cast<char>('A' + (i + decalage) % 26);
        }
        // On ajoute le caractère nul à la fin pour fermer la chaîne
        alphabet_clair[26] = '\0';
        alphabet_crypte[26] = '\0';
    }
    Cesar(int deca){
        decalage = deca;
        initialiserAlphabets();
    }
    Cesar(){
        decalage = 1;
        initialiserAlphabets();
    }
    std::string Crypter(std::string message_i){
        std::string message_n;
        for (char lettre : message_i){
            int code = int(lettre);
            if (code == 32 ){
                message_n += static_cast<char>(42);
            }
            else {
                message_n += static_cast<char>((code-65+decalage)%26+65);
            }    
        }
        return message_n;
    }

    std::string Decrypter(std::string message_i){
        std::string message_n;
        for (char lettre : message_i){
            int code = int(lettre);
            if (code == 42 ){
                message_n += static_cast<char>(32);
            }
            else {
                message_n += static_cast<char>((code - 65 - decalage + 26) % 26 + 65);
            }
        }
        return message_n;
    }
};

class XOR {
    public :

    std::string crypte (std::string message, std::string cle){
        int len_mess = message.size();
        int len_cle = cle.size();
        for (int i=0; i < len_mess; i++){
            message[i]=message[i] ^ cle[i % len_cle];
        }
        return message;
    }
};
int main() {
    /*
    Texte t;
    std::string texte;
    std::cout << "Entre le message que vous voulez mettre dans le fichier : ";
    std::getline(std::cin, texte);
    int taille = texte.size();
    
    t.Ecrire("corbeille_1.txt", taille, texte);
    
    std::string contenuLu = t.Lire("corbeille_1.txt", taille);
    std::cout << "Lu depuis le fichier : " << contenuLu << std::endl;
    */
    Cesar secret;
    std::string new_mess = secret.Crypter("ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    std::cout << new_mess << std::endl;
    std::string new_mess_2 = secret.Decrypter(new_mess);
    std::cout << new_mess_2 << std::endl;
    std::cout <<secret.alphabet_clair << std::endl;
    std::cout <<secret.alphabet_crypte << std::endl;
    XOR test;
    std::string mess_3 = test.crypte("ABCDEFGHIJKLMNOPQRSTUVWXYZ ", "ABC");
    std::string mess_4 = test.crypte(mess_3, "ABC");
    std::cout << mess_3 << std::endl;
    std::cout << mess_4 << std::endl;
    return 0;
}