#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

// ---------- //
// Constantes //
//------------//

#define CARACTERE_VIDE '-'
#define HAUTEUR_MAX 15
#define LARGEUR_MAX 20

//----------------------//
// Structures de donnes //
//----------------------//

struct tabHauteurs {

    int largeur;
    int contenu[LARGEUR_MAX + 1];

};

struct Montagne {
    int hauteur;
    int largeur;
    char contenu[LARGEUR_MAX][HAUTEUR_MAX];
};

// ---------- //
// Prototypes //
//------------//

bool verifieNbArguments(int nbArg);
bool sontCaracteresAcceptables(char *valeurArgv[]);
void creerTableauHauteurs(char *valeurArgv[]);
//
//
//--------------------------------------
int main(int argc, char *argv[]){
    char *eau;
    char *terre;

    if(verifieNbArguments(argc) == true){
         printf("test\n");
        if(sontCaracteresAcceptables(argv) == true){
            eau = argv[1];
            terre = argv[2];
        }
    }
    creerTableauHauteurs(argv);
}
//--------------------------------------
//
//
bool verifieNbArguments(int nbArg){
    if(nbArg < 4 || nbArg > 4){
        printf("Nombre d'arguments invalides : il en faut 3\n");
        return false;
     }else{
        return true;
    }    
}

bool sontCaracteresAcceptables(char *valeurArgv[]){
   bool resultat = true;
    if(strlen(valeurArgv[1]) == 1){
        if(strlen(valeurArgv[2]) == 1){
             if(strcoll(valeurArgv[1],valeurArgv[2]) == 0){
                 resultat = false;
                 printf("Les codes doivent etre distincts\n");
             }
        }else{
            printf("Code %s invalide : il doit etre un caractere unique\n",valeurArgv[2]);
            resultat = false;
        }     
    }else{
        printf("Code %s invalide : il doit etre un caractere unique\n",valeurArgv[1]);
        resultat = false;
    }
        return resultat;
}

void creerTableauHauteurs(char *valeurArgv[]){
    char *rep;
    int i = 0;
    int tab[LARGEUR_MAX];
    int nombre;
    
    rep = strtok(valeurArgv[3],",");
    while(rep != NULL && i < LARGEUR_MAX){
        nombre =(int) strtol(rep,NULL,10);
        
        if(nombre >= 0 && nombre <= 15){
            tab[i] = nombre;
            printf("%d\n",tab[i]);
            i++;
        }else{
            printf("Hauteur invalide : la hauteur doit etre un nombre entre 0 et 15\n");
        }
        rep = strtok(NULL,",");
    }
}
