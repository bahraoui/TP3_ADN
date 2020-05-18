/******************************************************************************/
/* WT.C                                                                       */
/******************************************************************************/

#include "WT.h"



/******************************************************************************/
/* nouveauNoeud                                                               */
/******************************************************************************/
Noeud *nouveauNoeud()
{
    Noeud * n = (Noeud *) malloc(sizeof(Noeud));
    int i;

    for(i=0;i!=26;i++)
        n->fils[i] = NULL;
    n->term = 0;

    return n;
}



/******************************************************************************/
/* ajouteMotArbre                                                             */
/******************************************************************************/
void ajouteMotArbre(Noeud *racine,char *str)
{
    int x =0;
    Noeud *courant = racine;
    while (str[x] != '\0'){
        int indice = str[x] - 'a';
        if (courant->fils[indice] == NULL){
            courant->fils[indice] = nouveauNoeud();
            }
        courant= courant->fils[indice];
        x +=1;
        }
    courant->term = 1;
    }



/******************************************************************************/
/* chercheMotArbre                                                            */
/******************************************************************************/
int chercheMotArbre(Noeud *racine,char *str)
{

    Noeud *courant = racine;
    int indice = *str -'a';

    if (( *(str)  == '\0') && (courant->term == 1))
        return 1;

    else if (courant->fils[indice] != NULL)
        return chercheMotArbre(courant->fils[indice], str+1);

    return 0;
}

