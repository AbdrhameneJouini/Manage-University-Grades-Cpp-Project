#include "Group_Classes.h"
#pragma once
#include <map>

/* Choosing maps to keep track for individual class data will make
checking if an item EXSITS already much easier.
for each map the key is the id of the element
and the others values are storred in a vector

*/
class DataBase
{
private:
    // key=>(structure of values) :: id=>(num_insc,idGRP)
    /* if only included num_insc and idGRP as values because we cant fetch the other
values from that "Groupe"
*/
    map<int, vector<string>> Etudiants;

    // key=>(structure of values) :: id=>(Enseignant)
    map<int, Enseignant> Enseignants;

    // key=>(structure of values) :: idMat=>(Matiere)
    map<string, Matiere> Matieres;

    /* key=>(structure of values) :: idGM=>(GroupeModule)*/
    map<string, GroupeModule> GroupesModules;

    /* key=>(structure of values) :: idGRP=>(Groupes)*/
    map<string, Groupe> Groupes;

    // key=>(strucutre of values) :: (idMat,idEtu)=>(Nombre des notes)
    /*since a student can have multiple marks in the same subject we need to keep track of how
    many did he receive (n) . */
    map<vector<string>, int> Notes_Number;
    // key=>(strucutre of values) :: (idMat,idEtu,num_note)=>(Note)
    // num_note is varies from 1...n;
    map<vector<string>, NOTE> Notes;

public:
    // constructors
    DataBase();
    DataBase(map<int, vector<string>>, map<int, Enseignant>, map<string, Matiere>, map<string, GroupeModule>, map<string, Groupe>);
    // Methods
    // ---->Check
    bool Person_Exists(int);
    bool Etudiant_Exists(int, int);
    bool Enseignant_Exists(int, int);
    bool Matiere_Exists(string);
    bool GroupesModule_Exists(string);
    bool Groupe_Exists(string);

    //  ---->Add (db exclusive)

    bool DB_Add_Etudiant(Etudiant, string);
    bool DB_Add_Enseignant(Enseignant);
    bool DB_Add_Matiere(Matiere);
    bool DB_Add_GroupeModule(GroupeModule);
    bool DB_Add_Groupe(Groupe);
    void DB_Add_Note(NOTE);

    // ---->Add (to execute other classes methods)
    void Grp_Operations(string, string);
};
