#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ---------- //
// Constantes //
//------------//

#define CARACTERE_VIDE '-'
#define HAUTEUR_MAX 15
#define LARGEUR_MAX 20

// ---------- //
//            //
//------------//

int main(int argc, char *argv[]){
    if(argc < 4 || argc > 4){
        printf("Nombre d'arguments invalides: il en faut 3\n");
    }else{
        printf("test tp1 okay\n");
    }
}

int longeurString(char* str){
    int longueur;
    longueur = strlen(str);
    return longueur; 
}
