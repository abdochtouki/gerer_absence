#ifndef ETUDIENT_H
#define ETUDIENT_H

#include <string>
using namespace std;

class etudient {
private:
    int CNE;
    string nom;
    string prenom;

public:
    etudient(int id, const string& nom, const string& prenom);
    int get_CNE() const;
    string get_nom() const;
    string get_prenom() const;
};

#endif
