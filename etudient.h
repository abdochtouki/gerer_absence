#include "etudient.h"

etudient::etudient(int id, const string& nom, const string& prenom) : CNE(id), nom(nom), prenom(prenom) {}

int etudient::get_CNE() const {
    return CNE;
}

string etudient::get_nom() const {
    return nom;
}

string etudient::get_prenom() const {
    return prenom;
}
