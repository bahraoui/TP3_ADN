/******************************************************************************/
/* Fonctions de hachage                                                       */
/******************************************************************************/
#include "fxhash.h"



/******************************************************************************/
/* hachage                                                                    */
/******************************************************************************/
unsigned long long int hachage(char *mot)
{
    unsigned long long int som, base = 1;

    int i = 0;
    som = 0;

    while(mot[i] != '\0') {
        int ascii = (int)mot[i];
        int ascii_alphabet = ascii - (int)'a' + 1;
        som += ascii_alphabet * base;
        base *= 26;
        i++;
    }

    return som;
}