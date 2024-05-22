#include "etudient.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class cours {
private:
    int code;
    string titre;
    vector<etudient> etudients;
public:
    cours(int c, const string& t) ;
    void ajouterEtudiant(const etudient& et) ;
    int getCode() const ;
    string getTitre() const ;
    vector<etudient> getEtudiants() const;
};
