#pragma once
#include "Person_Classes.h"

//<----------->

class Matiere
{
private:
    string idMat; // Unique
    string NomMat;
    float Coef;
    Enseignant Ens;

public:
    // Constructors
    Matiere();
    Matiere(string, string, float, Enseignant);
    // Getters
    string get_idMat();
    string get_nomMat();
    float get_coef();
    Enseignant get_ens();
};

//<----------->
class NOTE
{
private:
    // The couple (Mat,Etu) MUST BE UNIQUE
    Matiere Mat;
    Etudiant Etu;
    float Note;
    string Type;

public:
    // Constructors
    NOTE();
    NOTE(Matiere, Etudiant, float, string);
    // Getters
    float get_Note();
    string get_Type();
    Matiere get_Mat();
    Etudiant get_Etu();
};
