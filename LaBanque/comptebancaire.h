#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

/**
  @file comptebancaire.h
 * @brief The CompteBancaire class
 * @details Déclaration de la classe CompteBancaire
 * @author Maëva Soulard
 * @date 08/10/2020
 * @version 1
 */
class CompteBancaire
{
public:
    CompteBancaire(const float _solde = 0);
    void Deposer(const float _montant);
    bool Retirer(const float _montant);
    float ConsulterSolde();
protected:
    float solde;
};

#endif // COMPTEBANCAIRE_H
