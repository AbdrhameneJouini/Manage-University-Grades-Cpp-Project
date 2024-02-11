#include "../../inc/class/DataBase_Classes.h"

// Building Constructors
DataBase::DataBase()
{
    cout << "hi";
}
DataBase::DataBase(map<int, vector<string>> Etudiants, map<int, Enseignant> Enseignants, map<string, Matiere> Matieres, map<string, GroupeModule> GroupesModules, map<string, Groupe> Groupes)
{
    this->Etudiants = Etudiants;
    this->Enseignants = Enseignants;
    this->Matieres = Matieres;
    this->Groupes = Groupes;
    this->GroupesModules = GroupesModules;
}
