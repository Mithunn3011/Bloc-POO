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
    std::string cle;
    XOR(std::string n_cle ){
        cle = n_cle;
    }

    std::string Crypter (std::string message){
        int len_mess = message.size();
        int len_cle = cle.size();
        for (int i=0; i < len_mess; i++){
            message[i]=message[i] ^ cle[i % len_cle];
        }
        return message;
    }
};

int main(){
    int chiffrement;
    std::string chemin;
    int taille;
    int choix;
    std::cout << "Chiffrement / Déchiffrement de Fichier" << std::endl;
    std::cout << "Qu'est ce que tu veux faire ? \n 1. Chiffrement \n 2. Dechiffrement" << std::endl;
    std::cin >> chiffrement;
    std::cout << "Entrez le chemin vers le ficher + le nom fichier et sa taille" << std::endl;
    std::cout << "Chemin :" <<std::ends;
    std::cin >> chemin;
    std::cout << "Taille du fichier :" <<std::ends;
    std::cin >> taille;
    std::cout << "Quel type de chiffrement/dechiffrement vous voulez faire ? \n 1.Cesar \n 2.XOR \n 3.Les deux" <<std::endl;
    std::cin >> choix;
    std::string cle;
    int decalage;
    if (choix==1){
        std::cout << "Décalage :" <<std::ends;
        std::cin >> decalage;
        Cesar codage(decalage);
        if (chiffrement== 1){
            std::string message= codage.Crypter(message);
        }
        else{
            std::string message= codage.Decrypter(message);
        }
    }
    else if (choix==2){
        std::cout << "Clé :" <<std::ends;
        std::cin >> cle;
        XOR codage(cle);
        std::string message= codage.Crypter(message);
    }
    else if (choix==3){
        std::cout << "Décalage :" <<std::ends;
        std::cin >> decalage;
        std::cout << "Clé :" <<std::ends;
        std::cin >> cle;
        Cesar codage_Cesar(decalage);
        XOR codage_XOR(cle);
        if (chiffrement== 1){
            std::string message= codage_Cesar.Crypter(message);
        }
        else{
            std::string message= codage_Cesar.Decrypter(message);
        }
        std::string message= codage_XOR.Crypter(message);
    }
    Texte Fichier;
    std::string message=Fichier.Lire(chemin,taille);  
    std::cout << message << std::endl;
    return 0;

}