#include <iostream>
#include <string>

class Date{
    public:
    int j;
    int m;
    int a;

    Date(){
        j=0;
        m=0;
        a=0;
    }
    Date(int n_j,int n_m,int n_a){
        j= n_j;
        m= n_m;
        a= n_a;
    }
    static void affiche_jj_mm_aaaa(int j, int m, int a){
        std::cout << j << "/" << m << "/" << a << std::endl;
    }

    static void affiche_mm_jj_aaaa(int m, int j, int a){
        std::cout << m << "/" << j << "/" << a << std::endl;
    }
};
class Livre{
    public:
    std::string Auteur;
    std::string Titre;
    Date Date_publication;

    Livre(){
        Auteur = "Samy";
        Titre = "Tchoupi";
        Date_publication.j = 29;
        Date_publication.m = 11;
        Date_publication.a = 2007;
    }

    Livre(std::string n_Auteur, std::string n_Titre, Date n_Date_public){
        Auteur = n_Auteur;
        Titre = n_Titre;
        Date_publication = n_Date_public;
    }
    Livre(const Livre &l){
        Auteur = l.Auteur;
        Titre = l.Titre;
        Date_publication = l.Date_publication;
    }

    //Getters
    std::string GetAuteur(){
        return Auteur;
    }
    std::string GetTitre(){
        return Titre;
    }
    Date GetDate_publication(){
        return Date_publication;
    }

    //Setters
    void SetAuteur(std::string nv_Auteur){
        Auteur=nv_Auteur;
    }
    void SetTitre(std::string nv_Titre){
        Titre=nv_Titre;
    }
    void SetDate_Publication(Date nv_Date){
        Date_publication=nv_Date;
    }

    void afficher_Livre(){
        std::cout << "Présentation du Livre " << std::endl;
        std::cout << "Auteur : " << Auteur << std::endl;
        std::cout << "Titre : " << Titre << std::endl;
        Date_publication.affiche_jj_mm_aaaa(Date_publication.j,Date_publication.m,Date_publication.a);
    }
}