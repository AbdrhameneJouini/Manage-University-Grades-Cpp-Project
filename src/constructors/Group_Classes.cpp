

#include "../../inc/class/Group_Classes.h"

// Setting Default Constructors
GroupeModule::GroupeModule()
{
    idGM = "";
    nomGM = "";
    CoefGM = 0;
}
Groupe::Groupe()
{
    idGRP = "";
    Niveau = "";
    Diplome = "";
    Specialite = "";
    Num_G = 0;
}

// Setting Parametric Constructors
GroupeModule::GroupeModule(string idGM, string nomGM, float CoefGM, vector<Matiere> ListeMat)
{
    this->idGM = idGM;
    this->nomGM = nomGM;
    this->CoefGM = CoefGM;
    this->ListeMat = ListeMat;
}
Groupe::Groupe(string idGRP, string Niveau, string Diplome, string Specialite, int Num_G, vector<GroupeModule> ListeModules, vector<Etudiant> ListeEtudiant)
{

    this->idGRP = idGRP;
    this->Niveau = Niveau;
    this->Diplome = Diplome;
    this->Specialite = Specialite;
    this->Num_G = Num_G;
    this->ListeModules = ListeModules;
    this->ListeEtudiant = ListeEtudiant;
}
