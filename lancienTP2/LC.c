/******************************************************************************/
/* LC.c                                                                       */
/******************************************************************************/
#include"./LC.h"


/******************************************************************************/
/* nouvelleCellule                                                            */
/******************************************************************************/
Cellule * nouvelleCellule(char *mot)
{
   Cellule *c = (Cellule *) malloc(sizeof(Cellule)); // allocation cellule
   c->suiv = NULL; // par sécurité, la cellule n'a pas de suivant
   c->mot = (char *)malloc(strlen(mot)+1); // allocation mot
   strcpy(c->mot, mot); // copie du mot
   return c;
}

/******************************************************************************/
/* ajouteMotLC                                                                */
/******************************************************************************/
Cellule * ajouteEnTeteLC(Cellule *l, char *mot)
{
	Cellule *c = nouvelleCellule(mot);
	c->suiv = l;
	return c;
}

/******************************************************************************/
/* afficheLC                                                                  */
/******************************************************************************/
void afficheLC(Cellule *l)
{
   if(l) {
      printf("cellule : %s\n", l->mot);
      afficheLC(l->suiv);
   }
}

/******************************************************************************/
/* chercheMotLC - renvoie nb comparaison, >0 si trouvé, <=0 sinon             */
/******************************************************************************/
int  chercheMotLC(Cellule *l, char *mot)
{
   Cellule * p = l;
   int c = 0;

   while(p != NULL) {
      c++;

      if(strcmp(p->mot, mot) == 0)
         return c;
         
      p = p->suiv;
   }

   return 0-c;
}
