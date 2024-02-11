#include <iostream>
#include <string>
#pragma once
using namespace std; // we use namespace std to make code more READABLE by not typing std:: everytime we use a methode

//<----------->
class Personne
{
    // Personne atributs are "Protected" instead of "Private" since we are going to need them in Derived Classes like "Enseignant" and "Etudiant"
protected:
    int id; // Unique
    string nom;
    string prenom;
    string mail; // Special Format
public:
    // Constructors
    Personne();
    Personne(int, string, string, string);
    // Getters
    int get_ID();
    string get_nom();
    string get_prenom();
    string get_mail();
};

//<----------->

class Etudiant : public Personne
{
private:
    int num_insc; // Unique
public:
    // Constructors

    Etudiant();
    Etudiant(int, int, string, string, string);
    // Getters
    int get_numINSC();
    // methods
    void afficher() { cout << num_insc; };
};

//<----------->

class Enseignant : public Personne
{

private:
    int CNSS;

public:
    // Constructors
    Enseignant();
    Enseignant(int, int, string, string, string);
    // Getters
    int get_CNSS();
};
