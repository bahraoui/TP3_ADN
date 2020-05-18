/******************************************************************************/
/* WT.H                                                                       */
/******************************************************************************/

#ifndef WT_H
#define WT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_WT 0

int convert[26] = {0,-1,1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,-1};

/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/
typedef struct noeud {
    struct noeud *fils[4];
    char          tab[5];
    } Noeud;





/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/
/* Crée un nouveau noeud                                                      */
Noeud *nouveauNoeud();
/* Ajoute un mot dans l'arbre                                                 */
void ajouteMotArbre(Noeud *racine,char *str);
/* Cherche un mot dans l'arbre                                                */
int chercheMotArbre(Noeud *racine,char *str);




#endif

