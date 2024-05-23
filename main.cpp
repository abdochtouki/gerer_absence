#include<iostream>
#include<string>
#include<vector>
#include"gererabsence.cpp"
#include<algorithm>
using namespace std;

void afficherMenu() {
      cout<<"         Menu              \n";
    cout << "1. Ajouter un etudiant" << "\n"
         << "2. Ajouter un cours" << "\n"
         << "3. Ajouter une absence" << "\n"
         << "4. Afficher les absences" << "\n"
         << "5. Afficher les etudients" << "\n"
         << "6. Afficher les cours" << "\n"
         << "7. Quitter " << "\n"
         << "Choisissez une option : ";
}

void affichage(vector<etudient> listeEtudiants) {
            cout<<"*******************************************************************************************\n";
            cout<<"la liste des etudient :\n";
    for (int i = 0; i < listeEtudiants.size(); i++) {
        cout << "Nom: " << listeEtudiants[i].get_nom() <<" " << "Prenom: " << listeEtudiants[i].get_prenom() <<" "<< "CNE: " << listeEtudiants[i].get_CNE() << endl;
    }
            cout<<"*******************************************************************************************\n";

}

void affichage1(vector<cours> listeCours) {
            cout<<"*******************************************************************************************\n";
           cout<<"la liste des cours :";
    for (int i = 0; i < listeCours.size(); i++) {
        cout << "Code: " << listeCours[i].getCode() <<" "<< "Titre: " << listeCours[i].getTitre() << endl;
    }
            cout<<"*******************************************************************************************\n";

}


bool verifierMotDePasse() {
    const string motDePasseCorrect = "ESTSB"; 
    string motDePasse;
    cout << "Entrez le mot de passe : ";
    cin >> motDePasse;

    return motDePasse == motDePasseCorrect;
}

int main() {
    bool continuer = true;

    vector<etudient> listeEtudiants;
    vector<cours> listeCours;
    GestionnaireAbsences gestionnaireAbsences;

    while (continuer) {
        int choix;

        if (verifierMotDePasse()) {
            do {
                afficherMenu();
                cin >> choix;

                switch (choix) {
                    case 1: {
                        int CNE;
                        string nom, prenom;
                        cout << "Entrez le CNE de l'etudiant : ";
                        cin >> CNE;
                        cout << "Entrez le nom de l'etudiant : ";
                        cin >> nom;
                        cout << "Entrez le prenom de l'etudiant : ";
                        cin >> prenom;

                        auto it = find_if(listeEtudiants.begin(), listeEtudiants.end(), [CNE](const etudient& et) {
                            return et.get_CNE() == CNE;
                        });

                        if (it == listeEtudiants.end()) {
                            etudient e(CNE, nom, prenom);
                            listeEtudiants.push_back(e);
                        } else {
                            cout << "Etudiant avec ce CNE existe deja." << endl;
                        }
                        break;
                    }
                    case 2: {
                        int code;
                        string titre;
                        cout << "Entrez le code du cours : ";
                        cin >> code;
                        cout << "Entrez le titre du cours : ";
                        cin.ignore(); // Ignorer le caractère de nouvelle ligne résiduel
                        getline(cin, titre);
                        cours c(code, titre);
                        listeCours.push_back(c);
                        
                        break;
                    }
                    case 3: {
                        
                    }
                    case 4: {
                        int code_cours;
                        cout << "Entrez le code du cours pour afficher les absences : ";
                        cin >> code_cours;

                        auto it = find_if(listeCours.begin(), listeCours.end(), [code_cours](const cours& cours) {
                            return cours.getCode() == code_cours;
                        });

                        if (it != listeCours.end()) {
                            gestionnaireAbsences.imprimerAbsences(*it);
                        } else {
                            cout << "Cours non trouve." << endl;
                        }
                        break;
                    }
                    case 5:
                        affichage(listeEtudiants);
                        break;
                    case 6:
                        affichage1(listeCours);
                        break;
                    case 7: 
                        cout << "Quitter le programme." << endl;
                        break;
                    default:
                        cout << "Choix invalide. Reessayez." << endl;
                        break;
                }
            } while (choix != 7);
        } else {
            cout << "Erreur de mot de passe!" << endl;
        }

        char redemarrer;
        cout << "Pour redemarrer le programme saisir (o) : ";
        cin >> redemarrer;
        if (redemarrer != 'o' && redemarrer != 'O') {
            continuer = false;
        }
    }

    return 0;
}
