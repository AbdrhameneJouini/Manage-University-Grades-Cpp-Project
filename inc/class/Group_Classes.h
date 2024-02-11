#pragma once
#include "Other_Classes.h"
#include <vector>
//<----------->

class GroupeModule
{
private:
    string idGM;
    string nomGM;
    float CoefGM;
    vector<Matiere> ListeMat;

public:
    // constructors
    GroupeModule();
    GroupeModule(string, string, float, vector<Matiere>);
    // getters
    string get_idGM();
    string get_nomGM();
    float get_CoefGM();
};

//<----------->

class Groupe
{
private:
    string idGRP;      // UNIQUE
    string Niveau;     // INPUT CONSTRAINTS ("Premiere","Deuxieme"...)
    string Diplome;    // INPUT CONSTRAINTS ("ING","Master","LMD"...)
    string Specialite; // INPUT CONSTRAINTS ("INF","INDUS","MATHS"...)
    int Num_G;         // INPUT CONSTRAINTS (1,2,3)
    vector<GroupeModule> ListeModules;
    vector<Etudiant> ListeEtudiant;

public:
    // constructors
    Groupe();
    Groupe(string, string, string, string, int, vector<GroupeModule>, vector<Etudiant>);
    // getters
    string get_idGRP();
    string get_niveau();
    string get_diplome();
    string get_specialite();
    int get_numG();
    // methods
    //----->Add
    void Create_Etudiant();
    //----->Show
    void show_etud()
    {
        ListeEtudiant[0].afficher();
    };
};
