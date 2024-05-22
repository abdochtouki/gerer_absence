
#include "etudient.h"
#include<iostream>
#include<string>
#include<vector>
#include"cours.h"
using namespace std;
cours::cours(int c, const string& t) : code(c), titre(t) {}

    void cours::ajouterEtudiant(const etudient& et) {
        etudients.push_back(et);
    }

    int cours::getCode() const {
        return code;
    }

    string cours::getTitre() const {
        return titre;
    }

    vector<etudient> cours::getEtudiants() const {
        return etudients;
    }