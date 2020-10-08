#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H

#include "comptebancaire.h"

/**
  @file compteepagne.h
 * @brief The CompteEpargne class
 * @details Déclaration de la classe CompteEpargne
 * @author Maëva Soulard
 * @date 08/10/2020
 * @version 1
 */
class CompteEpargne : public CompteBancaire
{
public:
    CompteEpargne(const float _solde = 0, const float _tauxInterets = 0.5);
    float CalculerInterets();
    void ModifierTaux(const float _taux);
private :
    float tauxInterets;
};

#endif // COMPTEEPARGNE_H
