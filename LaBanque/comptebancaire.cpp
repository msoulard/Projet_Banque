/**
  @file comptebancaire.cpp
  @details Définition et déclaration des fonctions de la classe CompteBancaire
  @author Maëva Soulard
  @date 08/10/2020
  @version 1
*/

#include "comptebancaire.h"

/**
  @file comptebancaire.cpp
 * @brief CompteBancaire::CompteBancaire
 * @param _solde
 * @details Constructeur de la classe CompteBancaire
 */
CompteBancaire::CompteBancaire(const float _solde) :
    solde(_solde)
{

}

/**
  @file comptebancaire.cpp
 * @brief CompteBancaire::Deposer
 * @param _montant
 * @details Fonction qui permet de déposer le montant souhaité sur le compte bancaire
 */
void CompteBancaire::Deposer(const float _montant)
{
    ///On crédite le solde
    solde = solde + _montant;
}

/**
  @file comptebancaire.cpp
 * @brief CompteBancaire::Retirer
 * @param _montant
 * @return
 * @details Fonction qui permet de savoir si on peut retirer le montant souhaité et le fait si cela est possible
 */
bool CompteBancaire::Retirer(const float _montant)
{
    bool retour = false;
    ///Vérification du solde (s'il est supérieur ou égale au montant à retirer)
    if(solde >= _montant){
        ///retour devient vrai
        retour = true;
        ///on débite le solde
        solde = solde - _montant;
    }
    ///Si la vérification n'est pas bonne
    else{
        ///retour devient false
        retour = false;
    }
    return retour;
}

/**
  @file comptebancaire.cpp
 * @brief CompteBancaire::ConsulterSolde
 * @return
 * @details Fonction qui permet de consulter le solde de son compte bancaire
 */
float CompteBancaire::ConsulterSolde()
{
    return solde;
}
