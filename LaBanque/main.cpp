#include <iostream>
#include "menu.h"
#include "comptebancaire.h"

using namespace std;

/**
  @file main.cpp
 * @brief main
 * @return
 * @details Programme principal
 * @author Maëva Soulard
 * @date 08/10/2020
 * @version 1
 */
int main()
{
    int choix;
    float montant;
    float solde;
    bool possibilite;
    Menu unMenu("compteBancaire.txt");
    CompteBancaire *unCompteBancaire;

    ///Demander s'il y a un solde initiale du compte bancaire
    cout << "Voulez vous créez un compte avec un solde ? (1 = oui / 2 = non) ";
    cin >> choix;
    ///Si le choix est oui alors on initialise le compte bancaire avec le solde donné
    if(choix == 1){
        cout << "Donnez le solde initiale de votre compte bancaire : ";
        cin >> solde;
        unCompteBancaire = new CompteBancaire(solde);
    }
    ///Sinon le solde initiale est de 0
    else{
        solde = 0;
        unCompteBancaire = new CompteBancaire(solde);
    }
    ///Demander le choix à l'utilisateur le temps qu'il n'est pas 4
    do {
        ///Afficher le menu et attendre le choix de l'utilisateur
        choix = unMenu.Afficher();
        ///Différent choix possible de l'utilisateur
        switch (choix) {
        ///Si le choix est 1, on affiche le solde du compte bancaire
        case 1 :
            solde = unCompteBancaire->ConsulterSolde();
            cout << "Le solde de votre compte bancaire est de " << solde << "€" << endl;
            break;
        ///Si le choix est 2, on demande le montant du dépôt et on fait appel à la fonction Deposer de la classe CompteBancaire
        case 2 :
            cout << "Donnez le montant de votre dépôt : ";
            cin >> montant;
            unCompteBancaire->Deposer(montant);
            break;
        ///Si le choix est 3, on demande le montant du retrait, on fait appel à la fonction Retirer de la classe CompteBancaire et on dit à l'utilisateur si son retrait est possible ou non
        case 3 :
            cout << "Donnez le montant de votre retrait : ";
            cin >> montant;
            possibilite = unCompteBancaire->Retirer(montant);
            if(possibilite == false){
                cout << "Votre solde n'est pas assez important poour pouvoir effectuer ce retrait" << endl;
            }
            else{
                cout << "Votre retrait est bien accepté" << endl;
            }
            break;
        }
    } while (choix != 4);
    return 0;
}
