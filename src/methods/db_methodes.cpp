
#include "../../inc/methods.h"

// ------------------------->checks<--------------------------------
bool DataBase::Person_Exists(int Person_ID)
{

    // if an "Etudiant" or "Enseignant" possesses that ID then we cant create a new item with that ID
    return (Etudiants[Person_ID][0] != "" || Enseignants[Person_ID].get_ID() != 0) ? true : false;
};

// <------------->

bool DataBase::Etudiant_Exists(int Student_ID, int num_insc)
{
    if (Person_Exists(Student_ID))
    {
        return true;
    }

    // to check for num_insc we need to iterate through the map since its not key

    for (auto element : Etudiants)
    {
        // key=>(structure of values) :: id=>(num_insc,idGRP)
        // element.first (keys)   element.second (values)
        // num_insc is located in the first element of the vector
        if (element.second[0] == to_string(num_insc))
        {
            return true;
        }
    }

    return false;
};

// <------------->

bool DataBase::Enseignant_Exists(int Enseignant_ID, int CNSS)
{
    if (Person_Exists(Enseignant_ID))
    {
        return true;
    }
    for (auto element : Enseignants)
    {
        // key=>(structure of values) :: id=>(Enseignant)
        // element.first (keys)   element.second (values)

        if (element.second.get_CNSS() == CNSS)
        {
            return true;
        }
    }
    return false;
};

// <------------->

bool DataBase::Matiere_Exists(string Matiere_ID)
{
    return Matieres[Matiere_ID].get_idMat() == Matiere_ID ? true : false;
};

// <------------->

bool DataBase::Groupe_Exists(string Groupe_ID)
{
    return Groupes[Groupe_ID].get_idGRP() == Groupe_ID;
};
;

// <------------->

bool DataBase::GroupesModule_Exists(string GroupesModules_ID)
{
    return GroupesModules[GroupesModules_ID].get_idGM() == GroupesModules_ID;
};
;

// <-------------------------------------------------------------------->

//------------------------->Add<--------------------------------
bool DataBase::DB_Add_Etudiant(Etudiant etu, string Grp_ID)
{

    int etu_ID = etu.get_ID(),
        etu_numINSC = etu.get_numINSC();
    if (Etudiant_Exists(etu_ID, etu_numINSC))
    {
        return false;
    }
    else
    {

        // key=>(structure of values) :: id=>(num_insc,idGRP)
        Etudiants[etu_ID] = {to_string(etu_numINSC), Grp_ID};

        //!! IMPORTANT : DONT FORGET TO ADD TO GROUPES MAP

        return true;
    }
};

// <------------->

bool DataBase::DB_Add_Enseignant(Enseignant ens)
{
    int ens_ID = ens.get_ID(),
        ens_CNSS = ens.get_CNSS();
    if (Enseignant_Exists(ens_ID, ens_CNSS))
    {
        return false;
    }
    else
    { // key=>(structure of values) :: id=>(enseignant)
        Enseignants[ens_ID] = ens;
        return true;
    }
}

// <------------->

bool DataBase::DB_Add_Matiere(Matiere mat)
{

    string mat_id = mat.get_idMat();
    if (Matiere_Exists(mat_id))
    {
        return false;
    }
    else
    {
        Matieres[mat_id] = mat;
        return true;
    }
};

// <------------->

bool DataBase::DB_Add_GroupeModule(GroupeModule groupModule)
{

    string GM_id = groupModule.get_idGM();
    if (GroupesModules[GM_id].get_idGM() == GM_id)
    {
        return false;
    }
    else
    {
        GroupesModules[GM_id] = groupModule;

        //!! DONT FORGET TO ADD TO GROUPE

        return true;
    }
}

// <------------->

bool DataBase::DB_Add_Groupe(Groupe grp)
{

    string GRP_id = grp.get_idGRP();
    if (Groupes[GRP_id].get_idGRP() == GRP_id)
    {
        return false;
    }

    else
    {
        Groupes[GRP_id] = grp;
        return true;
    }
};

// <------------->

void DataBase::DB_Add_Note(NOTE note)
{

    string id_etu = to_string(note.get_Etu().get_ID());
    string id_mat = note.get_Mat().get_idMat();
    // key=>(strucutre of values) :: (idMat,idEtu)=>(Nombre des notes)
    vector<string> info_pair = {id_mat, id_etu};
    Notes_Number[info_pair]++;

    // key=>(strucutre of values) :: (idMat,idEtu,num_note)=>(Note)
    vector<string> info_trio = {id_mat, id_etu, to_string(Notes_Number[info_pair])};
};

// <------------->

void DataBase::Grp_Operations(string grp_id, string operation)
{

    if (operation == "add")
    {
    }
    else if (operation == "")
    {
        /* code */
    }
}