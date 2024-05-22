#ifndef ELEVE_H
#define ELEVE_H
#include<string>
#include<iostream>
using namespace std;

class etudient {
private:
    int CNE;
    std::string nom;
    std::string prenom;

public:
    etudient(int id, const std::string& nom, const std::string& prenom);

    int get_CNE() const;

    std::string get_nom() const;

    std::string get_prenom() const;
};

#endif // ELEVE_H