
#include "../../inc/methods.h"

#include <fstream>

// <--------------------------------------------->
// getters

// Personne
int Personne::get_ID() { return id; }
string Personne::get_nom() { return nom; }
string Personne::get_prenom() { return prenom; }
string Personne::get_mail() { return mail; }

// Etudiant
int Etudiant::get_numINSC() { return num_insc; }

// Enseignant
int Enseignant::get_CNSS() { return CNSS; }

// Matiere
string Matiere::get_idMat() { return idMat; }
string Matiere::get_nomMat() { return NomMat; }
float Matiere::get_coef() { return Coef; }
Enseignant Matiere::get_ens() { return Ens; }

// Note
float NOTE::get_Note() { return Note; }
string NOTE::get_Type() { return Type; }
Etudiant NOTE::get_Etu() { return Etu; }
Matiere NOTE::get_Mat() { return Mat; }
// Groupe Module

string GroupeModule::get_idGM() { return idGM; }
string GroupeModule::get_nomGM() { return nomGM; }
float GroupeModule::get_CoefGM() { return CoefGM; }

// Groupe

string Groupe::get_idGRP() { return idGRP; }
string Groupe::get_niveau() { return Niveau; }
string Groupe::get_diplome() { return Diplome; }
string Groupe::get_specialite() { return Specialite; }
int Groupe::get_numG() { return Num_G; }

// <--------------------------------------------->
vector<string> Create_Personne(string person_type)
{
    int id_holder;

    cout << "Vous Etes en train de creer un/une nouveau/nouvelle " << person_type << "..." << endl;
    //----->ID constraint exist : UNIQUE
    do
    {
        /* Error Handling
        if id_holder is not 0 than the user already tried to
        choose an id but already exists
        */
        if (id_holder != 0)
        {
            cout << "Cet ID est deja utilise par un Etudiant/Enseignant..." << endl;
        }

        //
        cout << "Choisissez un ID pour cette personne :" << endl;
        cin >> id_holder;
    } while (db.Person_Exists(id_holder) || id_holder == 0);

    string nom_holder, prenom_holder;
    cout << "Quel est le prenom de cette personne ?" << endl;
    cin >> prenom_holder;
    cout << "Quel est le nom de cette personne ? " << endl;
    cin >> nom_holder;

    //------>Mail constraint exist : SPECIAL FORMAT
    string mail_handler;
    do
    {
        // Error handling :
        if (mail_handler != "")
        {
            cout << "Cet mail ne respecte pas le format axyz@xx.zz" << endl;
        }

        cout << "Donner le mail de cette personne :";
        cin >> mail_handler;
    } while (!Valid_Mail(mail_handler));

    vector<string> info_holder = {to_string(id_holder), nom_holder, prenom_holder, mail_handler};

    return info_holder;
};

void Groupe::Create_Etudiant()
{

    vector<string> info_holder = Create_Personne("Etudiant");

    int num_insc_handler;
    do
    {
        // ERROR handing: UNIQUE
        if (num_insc_handler != 0)
        {
            cout << "Le numero d'inscrption utilise existe deja dans notre base..." << endl;
        }

        cout << "Donner le numero d'inscription de cet/cette etudiant/e" << endl;
        cin >> num_insc_handler;
    } while (db.Etudiant_Exists(num_insc_handler, stoi(info_holder[0])));

    // Creating a temp object of Etudiant
    Etudiant etu = Etudiant(num_insc_handler, stoi(info_holder[0]), info_holder[1], info_holder[2], info_holder[3]);
    if (!db.DB_Add_Etudiant(etu, idGRP))
    {
        cout << "Erreur, Impossible d'ajouter cet Etudiant !!!" << endl;
    }
    else
    {

        int ListEtu_size = ListeEtudiant.size();
        ListeEtudiant.push_back(etu);
    }
};

void DataBase::Grp_Operations(string Grp_ID, string operation)

{
    if (operation == "add")
    {
        Groupes[Grp_ID].Create_Etudiant();
        // cout<<Groupes[Grp_ID];
        Groupes[Grp_ID].show_etud();
    }
}
