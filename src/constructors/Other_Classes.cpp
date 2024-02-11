#include "../../inc/class/Other_Classes.h"

// Setting Default Constructors
Matiere::Matiere()
{
    idMat = "";
    NomMat = "";
    Coef = 0;
    Ens;
}

NOTE::NOTE()
{
    Mat;
    Etu;
    Note = 0;
    Type = "";
}
// Setting Parametric Constructors
Matiere::Matiere(string idMat, string NomMat, float Coef, Enseignant Ens)
{
    this->idMat = idMat;
    this->NomMat = NomMat;
    this->Coef = Coef;
    this->Ens = Ens;
}
NOTE::NOTE(Matiere Mat, Etudiant Etu, float Note, string Type)
{

    this->Mat = Mat;
    this->Etu = Etu;
    this->Note = Note;
    this->Type = Type;
}
