/******************************************************************************/
/* WT.H                                                                       */
/******************************************************************************/

#ifndef WT_H
#define WT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_WT 0



/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/

typedef struct noeud {
    struct noeud *fils[4]; // A = 0 / C = 1 / G = 2 / T = 3
    int          lesSeq[5];
    } Noeud;





/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/
/* Crée un nouveau noeud                                                      */
Noeud *nouveauNoeud();
/* Ajoute un mot dans l'arbre                                                 */
void ajouteMotArbre(Noeud *racine,char *str,int numSeq);
/* Cherche un mot dans l'arbre                                                */
int chercheMotArbre(Noeud *racine,char *str,int numSeq); // deprecated
/* Trouve des mots similaires aux sequences                                   */
int MotsSimilaires(Noeud *racine,char *str,int prof);




#endif

