#include "../../inc/class/Person_Classes.h"

// Setting Default Constructors
Personne::Personne()
{
    id = 0;
    nom = "";
    prenom = "";
    mail = "";
}

Etudiant::Etudiant() : Personne(), num_insc(0){};

Enseignant::Enseignant() : Personne(), CNSS(0){};

// Setting Parametric Constructors

Personne::Personne(int id, string nom, string prenom, string mail)
{
    // we use this->attribute_name since we the params and attributes have similar names
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
}

Etudiant::Etudiant(int num_insc, int id, string nom, string prenom, string mail) : Personne(id, nom, prenom, mail), num_insc(num_insc){};

Enseignant::Enseignant(int CNSS, int id, string nom, string prenom, string mail) : Personne(id, nom, prenom, mail), CNSS(CNSS){};
