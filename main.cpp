
// #include <iomanip>
// #include <windows.h>

#include "inc/methods.h"
// #include "constructors/Person_Class.cpp"

int main()
{

    // Setting Background Color to Grey(8) and Text color to black(0)
    // system("Color 80");
    // cout << setfill('_') << setw(50);
    Etudiant etu;
    string grp_id;
    int Grp_operation;
    cout << "BienvenuX" << endl;
    cout << "Gestion des Groupes :" << endl;
    cout << "List des operations possibles : " << endl
         << "1. Ajout d'un nouvel groupe "
         << endl
         << "2. Suppression d'un groupe"
         << endl
         << "3. Gestion d'un groupe existant"
         << endl;

    cin >> Grp_operation;
    switch (Grp_operation)
    {
    case 1:
        cout << "Donner le numero de Groupe a modifié";
        cin >> grp_id;
        break;

    default:
        break;
    }
    // db.Grp_Operations(grp_id, "add");

    // return grp["dd"]
    // int X;
    // cin >> X;
    return 0;
}