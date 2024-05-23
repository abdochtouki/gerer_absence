





#include<iostream>
#include<string>
#include<vector>
#include"cours.cpp"
#include"absence.h"

using namespace std;



class GestionnaireAbsences {
private:
    vector<Absence> absences;

public:
     void afficher();
    void marquerAbsence(int code_cours, int );
    vector<int> obtenirAbsences(int code_cours) const ;
     void imprimerAbsences(const cours& cours) const ;
};



