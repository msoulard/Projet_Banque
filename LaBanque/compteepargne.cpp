/**
  @file compteepargne.cpp
  @details Définition et déclaration des fonctions de la classe CompteEpargne
  @author Maëva Soulard
  @date 08/10/2020
  @version 1
*/

#include "compteepargne.h"

/**
  @file compteepargne.cpp
 * @brief CompteEpargne::CompteEpargne
 * @param _solde
 * @param _tauxInterets
 * @details Construteur de la classe CompteEpargne héritant de la classe CompteBancaire
 */
CompteEpargne::CompteEpargne(const float _solde, const float _tauxInterets) :
    CompteBancaire(_solde),
    tauxInterets(_tauxInterets)
{

}

/**
  @file compteepargne.cpp
 * @brief CompteEpargne::CalculerInterets
 * @return solde
 * @details Fonction qui calcule le taux d'intérêts sur le compte épargne
 */
float CompteEpargne::CalculerInterets()
{
    //solde = solde + solde * tauxInterets;
    return solde * tauxInterets;
}

/**
  @file compteepargne.cpp
 * @brief CompteEpargne::ModifierTaux
 * @param _taux
 * @details Fonction qui permet de changer le taux d'intérêts
 */
void CompteEpargne::ModifierTaux(const float _taux)
{
    tauxInterets = _taux;
}

