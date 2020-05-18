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
    char strTemp[5];

    // creation de l'arbre
    Noeud * racine = nouveauNoeud();
    
    for(int laSeq = 0; laSeq != 5; laSeq++){
        for(int base=0; base != 296; base++){
            for(int i = 0; i != 5; i++){
                strTemp[i] = (char)seq[laSeq][base + i];
            }
            ajouteMotArbre(racine, strTemp, laSeq);
        }
    }

    MotsSimilaires(racine,str,0);    

    return 0;
}