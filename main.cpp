
#include<iostream>
#include<string>
#include<vector>
#include"gererabsence.cpp"
#include<algorithm>
using namespace std;


void afficherMenu() {
    cout << "1. Ajouter un etudiant" << "\n"
         << "2. Ajouter un cours" << "\n"
         << "3. Ajouter une absence" << "\n"
         << "4. Afficher les absences" << "\n"
         << "5. Quitter" << "\n"
         << "6. affichage"<<"\n"
         << "7. affichage cours"<<"\n"
         << "Choisissez une option : ";
}
   void   affichage(vector<etudient>listeEtudiants){
       int i;
       for(i=0;i<listeEtudiants.size();i++){
        cout<<"Nom"<<listeEtudiants[i].get_nom()<<endl;
        cout<<"prenom"<<listeEtudiants[i].get_prenom()<<endl;
        cout<<"CNE"<<listeEtudiants[i].get_CNE()<<endl;

       }

   }
   void   affichage1(vector<cours>listeEtudiants){
       int i;
       for(i=0;i<listeEtudiants.size();i++){
        cout<<"code  :"<<listeEtudiants[i].getCode()<<endl;
        cout<<"titre  :"<<listeEtudiants[i].getTitre()<<endl;

       }

   }
// Fonction pour vérifier le mot de passe
bool verifierMotDePasse() {
    const string motDePasseCorrect = "admin123"; // Définir votre mot de passe ici
    string motDePasseEntre;
    cout << "Entrez le mot de passe : ";
    cin >> motDePasseEntre;
    return motDePasseEntre == motDePasseCorrect;
}

int main() {
    bool continuer = true;

    while (continuer) {
        vector<etudient> listeEtudiants;
        vector<cours> listeCours;
        GestionnaireAbsences gestionnaireAbsences;
        int choix;

        if (verifierMotDePasse()) {
            do {
                afficherMenu();
                cin >> choix;

                switch (choix) {
                    case 1: {
                        int CNE;
                        string nom, prenom;
                        cout << "Entrez CNE de le etudiant : ";
                        cin >> CNE;
                        cout << "Entrez le nom de le etudiant : ";
                        cin >> nom;
                        cout << "Entrez le prenom de le etudiant : ";
                        cin >> prenom;

                        auto it = find_if(listeEtudiants.begin(), listeEtudiants.end(), [CNE](const etudient& et) {
                            return et.get_CNE() == CNE;
                        });

                        if (it == listeEtudiants.end()) {
                            etudient e(CNE, nom, prenom);
                            listeEtudiants.push_back(e);
                        } else {
                            cout << "etudiant avec ce CNE existe deja." << endl;
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
                        int code_cours, CNE_etudiant;
                        cout << "Entrez le code du cours : ";
                        cin >> code_cours;
                        cout << "Entrez CNE de le etudiant : ";
                        cin >> CNE_etudiant;
                        gestionnaireAbsences.marquerAbsence(code_cours, CNE_etudiant);
                        break;
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
                        cout << "Quitter le programme." << endl;
                        break;
                    case 6:
                           affichage(listeEtudiants);
                           break;
                    case 7:
                         gestionnaireAbsences.afficher();
                         break;
                    
                    default:
                        cout << "Choix invalide. Reessayez." << endl;
                        break;
                }
            } while (choix != 5);
        } else {
            cout << "Erreur de mot de passe!" << endl;
        }

        char redemarrer;
        cout << "Voulez-vous redemarrer le programme ? (o/n) : ";
        cin >> redemarrer;
        if (redemarrer != 'o' && redemarrer != 'O') {
            continuer = false;
        }
    }

    return 0;
}
