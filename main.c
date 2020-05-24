#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WT.h"

int main(int argc, char const *argv[])
{

// 5 séquences de 300 bases
char seq[5][301]={
"CAGTTAGCCCTAATGCCTCCGGGGTTGTGAAAAGTTTAACCACAATTTGCTGGCTTGGGTTACACCATAGATTTAGACCACTCACCTGATTTTGGGTGAGCGATATGCGTGTGTGTTATGGGAGTAGATTGAATCTCATAGTCTGATACAAGAACTCCCTTCTACATCGCTTGATTTAAGGTTGTTACCCTGACCTGGCATGGCGCGGAGACGAGACGAACTGGGGAGAGATTGTCAAAAGTGAGGGTACGCTGCAGGTAGGTTTTAACATGAGCGAACTTGGACATCTAGACGGGAACG",
"TTCCACTTGGAGCAACCCGAACACGTGTACAGACATAACTATCGATCTATGCCCGGTATCTGGGGATGGCTCAATGCGCGAGACTACTTTTAAAGCGGCATAACTCTTGAGAAGCTCCTTCTACAGTGCCCGCTGCCTGCGTGCTCCCCACCTGCGCTGCATAGGTCGGCGCATGCGCGCCTATGAGAAACAAGAAAATCGGGTTTCTGTGCAACAGCTTGATTGATGTACGGCCCCTACGCTTATGGAGCATCATCGCGAGCCAAATCAATATCACGGGAATACGATACGGTACGACCA",
"GCGGCTACGTATTCTGTCGGAGTAGCGGCCGTCTGCCCAGACGACCTATAGAAAGCGGCGGACAGGCTGAGCGAGGTACTACTTCTACAAATACTGTCGATGGTAATCTCCTACCGCACGGCGTCTAAAGCATGGTAAAGAAAATCTCTAGTCTCTGATTCAGCATCTGTGCCGTGTATTAGAACCGTGGGGCCCCCGGAGGTTTCATACCAGTTCGACTATCCGAGATGATCTCCATATCGTCTAATACACTCATCTAGACAGTGCCATAGTGAAAATAGACTAACGGCCCGCCCTTGA",
"AGCAAGAATTGCCATCCCCCTCTTGCCACACTCACATTATTGGATGTCTACGGACATGATAAATTCGCTCCTATCAATGTACTCCATATGTCTAGACATTATCGGTTGTGAGATTCGGACCCCCACCCGATTGGGTATAGAGAGTATTATATTAGTCGGACTCCGCATTAATATCTCGTGTATAGTGTACCGGTCTATGCGCTTGGGGGGTGATACTCGATTGCGCATTGTTGGAAACTGCCAACTAGAATAGATTTACTTCTACATATTCTGGGCAGCTTGGGGTCTTAGGTCCGAATG",
"CCTGGGTTGATGTATAATTTTAGTACGGGAGACGTGTGTGTTCGCGCCGCAAGAAGGTCTCTGCAAAAAACCTGTCTCTTCTACACACTGGAAAGTGAAGGGTGAGCGGCGGACATAGGTGTGTCTTGCCTATACGACAGGCGGTTTTGGAACATGCGGCCCCATGTAGCCTGGCCCACAGCCTTTAAAATGGCTTAGCAAAAATGGTACGGCCCTGCCTGAAGTTCGGAGGAGTACCGCCGGGTCGATTTGTGATGTGGTTTCGGGTGTACTTGTGTCAATTGGATTCCGCGAAACCCA"
};
    char str[20];
    char strTemp[310];

    // creation de l'arbre
    Noeud * racine = nouveauNoeud();
    
    // parcours des 5 séquences
    for(int laSeq = 0; laSeq != 5; laSeq++){
        // parcours par caractère par suffixe (en "enlevant" un caractère préfixe à chaque fois) des séquences
        for(int base=0; base != 301; base++){
            // parcours du mot à ajouter
            for(int i = 0; i != 301 - base; i++){
                strTemp[i] = (char)seq[laSeq][base  + i];
            }
            strTemp[301 - base  + 1]='\0';
            ajouteMotArbre(racine, strTemp, laSeq);
        }
    }

    int a = MotsSimilaires(racine,str,0);

    printf("%d\n",a);

    return 0;
}