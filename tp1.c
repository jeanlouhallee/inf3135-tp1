#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// ---------- //
// Constantes //
//------------//

#define CARACTERE_VIDE '-'
#define HAUTEUR_MAX 15
#define LARGEUR_MAX 20

// ---------- //
//            //
//------------//

bool verifieNbArguments(int nbArg);


int main(int argc, char *argv[]){
    if(verifieNbArguments(argc) == true){
         printf("test tp1 okay\n");
    }
}

int longeurString(char* str){
    int longueur;
    longueur = strlen(str);
    return longueur; 
}

bool verifieNbArguments(int nbArg){
    if(nbArg < 4 || nbArg > 4){
        printf("Nombre d'arguments invalides : il en faut 3\n");
        return false;
     }else{
        return true;
    }    
}

int* StringToIntTab(int valeurArgc, char *valeurArgv[]){
    char *reponse;
    int i=0;
    int tab[valeurArgc - 1];

    reponse = strtok(tab[1],",");
    while(reponse != NULL && i < valeurArgc){
        tab[i] = atoi(reponse);
        reponse = strtok(NULL,",");
        printf("%d \n", tab[i]);
        i++;
    }
    return tab;
}
