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

    for(i=0;i!=4;i++)
        n->fils[i] = NULL;

    for(i=0;i!=5;i++)
        n->lesSeq[i] = 0;

    return n;
}



/******************************************************************************/
/* ajouteMotArbre                                                             */
/******************************************************************************/
void ajouteMotArbre(Noeud *racine,char *str,int numSeq)
{
    int x = 0;
    int indice;
    Noeud *courant = racine;
    int convert[26] = {0,-1,1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,-1};
    while (str[x] != '\0'){
        indice = convert[str[x] - 'A'];
        if (courant->fils[indice] == NULL){
            courant->fils[indice] = nouveauNoeud();
            }
        courant = courant->fils[indice];
        x += 1;
    }
    courant->lesSeq[numSeq] = 1;
}


//deprecated
/******************************************************************************/
/* chercheMotArbre                                                            */
/******************************************************************************/
int chercheMotArbre(Noeud *racine,char *str,int numSeq)
{

    Noeud *courant = racine;
    int convert[26] = {0,-1,1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,-1};
    int indice = convert[*str -'A'];
    if (( *(str)  == '\0') && (courant->lesSeq[numSeq] == 1))
        return 1;

    else if (courant->fils[indice] != NULL)
        return chercheMotArbre(courant->fils[indice], str+1,numSeq);

    return 0;
}

/******************************************************************************/
/* MotsSimilaires                                                             */
/******************************************************************************/
int MotsSimilaires(Noeud *racine,char *str,int prof)
{
    int full[5] = {1,1,1,1,1};
    int convert[4] = {0,2,6,19};

    if(racine == NULL)
        return;

    if(prof == 5 && memcmp(full,racine->lesSeq,5*sizeof(int)) == 0){
        str[prof] = '\0';
        printf("- %s\n", str);
        return;
    }

    for(int i=0; i<4; i++){
        str[prof] = convert[i]+ 'A';
        motCommun(racine->fils[i], prof+1, mot);
    }
}

