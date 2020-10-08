#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include <string>
#include <iostream>
#include "comptebancaire.h"
#include "compteepargne.h"

using namespace std;

/**
  @file compteclient.h
 * @brief The CompteClient class
 * @details Déclaration de la classe CompteClient
 * @author Maëva Soulard
 * @date 08/10/2020
 * @version 1
 */
class CompteClient
{
public:
    CompteClient(const string _nom, const int _numero, CompteBancaire *_unCompteBancaire, CompteEpargne *_unCompteEpargne);
    ~CompteClient();
    void OuvrirCompteEpargne();
    void GererCompteBancaire();
    void GererCompteEpargne();
private :
    string nom;
    int numero;
    CompteBancaire *unCompteBancaire;
    CompteEpargne *unCompteEpargne;
};

#endif // COMPTECLIENT_H
