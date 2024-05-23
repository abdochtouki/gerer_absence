
#include<iostream>
#include<string>
#include<vector>
#include"gererabsence.h"
using namespace std;
 void GestionnaireAbsences::marquerAbsence(int code_cours, int CNE_ET) {
        absences.push_back({code_cours, CNE_ET});
    }
          void GestionnaireAbsences::afficher(){
            for(int i=0;i<absences.size();i++){
                 cout<<"code cours est :"<<absences[i].code_cours<<" "<<" code etudient"<<absences[i].CNE_ET;

            }
          }

    vector<int> GestionnaireAbsences::obtenirAbsences(int code_cours) const {
        vector<int> liste_absence;
        for (const auto& r : absences) {
            if (r.code_cours == code_cours) {
                liste_absence.push_back(r.CNE_ET);
            }
        }
        return liste_absence;
    }

    void GestionnaireAbsences::imprimerAbsences(const cours& cours) const {
        int code_cours = cours.getCode();
        vector<int> etudiantsAbsents = obtenirAbsences(code_cours);
        vector<etudient> etudiants = cours.getEtudiants();
        cout << "Absences pour le cours " << cours.getTitre() << " :" << endl;
        for (int CNE : etudiantsAbsents) {
            for (const etudient& etudiant : etudiants) {
                if (etudiant.get_CNE() == CNE) {
                    cout << "CNE : " << CNE << ", Prénom : " << etudiant.get_prenom() << ", Nom : " << etudiant.get_nom() << endl;
                }
            }
        }
    }
