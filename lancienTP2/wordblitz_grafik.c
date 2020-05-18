/******************************************************************************/
/*                                                                            */
/******************************************************************************/
#include "wordblitz_grafik.h"
/*
static void stringToLowerCase(char * c) {
    size_t l = strlen(c);
    for (size_t i = 0; i < l; i++)
    {
        c[i] = tolower(c[i]);
    }
    
}
*/
/******************************************************************************/
/* genereMatrice - génère une matrice de jeu aléatoire                        */
/******************************************************************************/
void genereMatrice(char m[4][4])
    {
    char alea16[16];
    int i;

    main_aleatoire(alea16, 16);
    for(i=0; i!=4; i++)
        {
        memcpy(m[i],alea16+4*i,4);
/*         m[i][4] = '\0'; */
        }
    }


/******************************************************************************/
/* afficheChemin - affiche à l'écran graphique un mot donné                   */
/******************************************************************************/
void afficheChemin(char *ch, int prof)
    {
/*     int i; */
    static Point p = {310,0};

/*     int val = calculeValeur(ch,prof); */

    ch[prof+1] = '\0';
    afficher_texte(ch, 15, p, blanc);
    p.y += 15;
    if(p.y>585)
        {
        p.y=0;
        p.x += 150;
        }
    actualiser();
/*     printf("%s\n",ch); */
/*     for(i=0; i<=prof; i++) */
/*         fprintf(stderr,"%c",ch[i]); */
/*     fprintf(stderr," %d\n",val); */
    }

/******************************************************************************/
/* chemin - visite tous les mots possibles de la grille                       */
/******************************************************************************/
int chemins(char m[4][4],  Noeud *racine, Cellule ** tabh, unsigned int taille)
    {
    posDamier d;
    int nbchemins=0;
    char chemin[16]; // le mot constitué au fur et à mesure du parcours
    memset(chemin, 0, 16);

/******************************************************************************/
/* A VOUS DE COMPLETER - APPEL(S) A LA FONCTION REC                           */
/******************************************************************************/

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            m[i][j] = tolower(m[i][j]);
        }
    }

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            d.c = i;
            d.l = j;
            int matvisite[4][4]={{0}}; // matrice des positions visitées (1 ou 0)
            int n = recChemins(d, m, matvisite, 0, chemin, NULL, tabh, taille);
            nbchemins += n;
            memset(chemin, 0, 16);
        }
        
    }

    return nbchemins;
    }


/******************************************************************************/
/* recChemins - fonction récursive appelée par chemins                        */
/******************************************************************************/
int recChemins(posDamier d, char m[4][4], int matvisite[4][4], int prof, char *chemin, Noeud *n, Cellule ** tabh, unsigned int taille)
{
    int nbChemins = 1;

    posDamier leVoisin = d;

    chemin[prof] = m[d.l][d.c];
    chemin[prof+1] = '\0';

    unsigned long long int hash = hachage(chemin) % taille;
    int exist = chercheMotLC(tabh[hash], chemin);

    if(exist > 0)
        afficheChemin(chemin, prof);

    matvisite[d.l][d.c] = 1;

    for (leVoisin.l = d.l - 1; leVoisin.l <= d.l + 1; leVoisin.l++)
    {
        if (leVoisin.c >= 0 && leVoisin.c < 4)
        {
            for (leVoisin.c = d.c - 1; leVoisin.c <= d.c + 1; leVoisin.c++)
            {
                if( matvisite[leVoisin.l][leVoisin.c]==0 && leVoisin.l >= 0 && leVoisin.l < 4 )
                    {
                        if(leVoisin.c != d.c || leVoisin.l != d.l )
                        {
                            nbChemins += recChemins(leVoisin, m, matvisite, prof+1, chemin, n, tabh, taille);
                        }

                    }
            }
        }  
    }

    matvisite[d.l][d.c] = 0;
    return nbChemins;
}