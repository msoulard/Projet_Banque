/**
  @file compteclient.cpp
  @details Définition et déclaration des fonctions de la classe CompteClient
  @author Maëva Soulard
  @date 08/10/2020
  @version 1
*/

#include "compteclient.h"
#include "comptebancaire.h"
#include "compteepargne.h"
#include "menu.h"

/**
  @file compteclient.cpp
 * @brief CompteClient::CompteClient
 * @param _nom
 * @param _numero
 * @details Constructeur de la classe CompteClient
 */
CompteClient::CompteClient(const string _nom, const int _numero, CompteBancaire *_unCompteBancaire, CompteEpargne *_unCompteEpargne) :
    nom(_nom),
    numero(_numero),
    unCompteBancaire(_unCompteBancaire),
    unCompteEpargne(_unCompteEpargne)
{
    unCompteEpargne = nullptr;
    unCompteBancaire = new CompteBancaire(0);
}

/**
  @file compteclient.cpp
 * @brief CompteClient::~CompteClient
 * @details Destructeur de la classe CompteClient
 */
CompteClient::~CompteClient()
{
    delete unCompteBancaire;
    if(unCompteEpargne != nullptr){
        delete unCompteEpargne;
    }
}

/**
  @file compteclient.cpp
 * @brief CompteClient::OuvrirCompteEpargne
 * @details Fonction qui permet à l'utilisateur de créer un compte épargne s'il n'en existe pas encore
 */
void CompteClient::OuvrirCompteEpargne()
{
    float solde;
    float taux;
    ///Vérification de l'inexistance du compte épargne
    if(unCompteEpargne == nullptr){
        cout << "Quel est le solde et le taux du compte épargne ? ";
        cin >> solde >> taux;
        unCompteEpargne = new CompteEpargne(solde, taux);
        unCompteEpargne->ModifierTaux(taux);
    }
    ///S'il existe, on prévient l'utilisateur
    else{
        cout << "Un compte épargne existe déjà" << endl;
    }
}

/**
  @file compteclient.cpp
 * @brief CompteClient::GererCompteBancaire
 * @details Focntion qui permet de gérer le compte bancaire du client
 */
void CompteClient::GererCompteBancaire()
{
    int choix;
    float montant;
    float solde;
    bool possibilite;
    Menu unMenu("compteBancaire.txt");

    ///Demander s'il y a un solde initiale du compte bancaire
    cout << "Voulez vous créez un compte bancaire avec un solde ? (1 = oui / 2 = non) ";
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
}

/**
  @file compteclient.cpp
 * @brief CompteClient::GererCompteEpargne
 * @details Focntion qui permet de gérer le compte épargne
 */
void CompteClient::GererCompteEpargne()
{
    int choix;
    float montant;
    float solde;
    bool possibilite;
    float interets;
    Menu unMenu("compteEpargne.txt");

    ///Demander le choix à l'utilisateur le temps qu'il n'est pas 5
    do {
        ///Afficher le menu et attendre le choix de l'utilisateur
        choix = unMenu.Afficher();
        ///Différent choix possible de l'utilisateur
        switch (choix) {
        ///Si le choix est 1, on affiche le solde du compte épargne
        case 1 :
            solde = unCompteEpargne->ConsulterSolde();
            cout << "Le solde de votre compte bancaire est de " << solde << "€" << endl;
            break;
        ///Si le choix est 2, on demande le montant du dépôt et on fait appel à la fonction Deposer de la classe CompteBancaire
        case 2 :
            cout << "Donnez le montant de votre dépôt : ";
            cin >> montant;
            unCompteEpargne->Deposer(montant);
            break;
        ///Si le choix est 3, on demande le montant du retrait, on fait appel à la fonction Retirer de la classe CompteBancaire et on dit à l'utilisateur si son retrait est possible ou non
        case 3 :
            cout << "Donnez le montant de votre retrait : ";
            cin >> montant;
            possibilite = unCompteEpargne->Retirer(montant);
            if(possibilite == false){
                cout << "Votre solde n'est pas assez important poour pouvoir effectuer ce retrait" << endl;
            }
            else{
                cout << "Votre retrait est bien accepté" << endl;
            }
            break;
        case 4 :
            interets = unCompteEpargne->CalculerInterets();
            cout << "Vos intérêts seront de " << interets << "€ au bout de un an" << endl;
            break;
        }
    } while (choix != 5);
}

