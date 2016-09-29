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

//-----------------------//
// Structures de donnees //
//-----------------------//

struct tabHauteurs {

    int largeur;
    int contenu[LARGEUR_MAX];

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
bool verifierHauteurs(char *valeurArgv[],struct tabHauteurs *h);
void construireMontagne(char terre, struct tabHauteurs *hauteur, struct Montagne *montagne);
void afficherMontagne(struct Montagne *montagne);
int trouverHauteur(struct tabHauteurs *hauteur);
//
//
//
//
//
//--------------------------------------
int main(int argc, char *argv[]){
    char eau;
    char terre;
    struct tabHauteurs hauteurs;
    struct Montagne montagne;

    if(verifieNbArguments(argc) == true){
         printf("test\n");                                                  ///////
        if(sontCaracteresAcceptables(argv) == true){
            terre = argv[1][0];
            eau = argv[2][0];
            if(verifierHauteurs(argv,&hauteurs)== true){
                printf("Largeur est : %d\n",hauteurs.largeur);                  ////////
                construireMontagne(terre, &hauteurs, &montagne);
                afficherMontagne(&montagne);    
            }
        }
    }
}
//--------------------------------------
//
//
//
//
//
//
int trouverHauteur(struct tabHauteurs *hauteurs){
   int i = 0;
   int max = 0;
   int temp;

    for(i = 0 ; i<= hauteurs->largeur - 1 ; i++){
        temp = hauteurs->contenu[i];
        if(temp > max) max = hauteurs->contenu[i];
    }
    return max;
}

void afficherMontagne(struct Montagne *montagne){

}

void construireMontagne(char terre, struct tabHauteurs *hauteur, struct Montagne *montagne){
    montagne->hauteur = trouverHauteur(hauteur);
    printf("%d\n",montagne->hauteur);                                   ////////////////////
    montagne->largeur = hauteur->largeur;
    printf("%d\n",montagne->largeur);                                           ///////////////////
    :
}

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

bool verifierHauteurs(char *valeurArgv[], struct tabHauteurs *hauteurs){
    char *rep;
    int i = 0;
    int nombre;
    bool resultat = true;

    rep = strtok(valeurArgv[3],",");
    while(rep != NULL && i <= LARGEUR_MAX){
    
        nombre =(int) strtol(rep,NULL,10);
        
        if(nombre >= 0 && nombre <= HAUTEUR_MAX){
            hauteurs->contenu[i] = nombre;
           // printf("%d\n",h.contenu[i]);
            i++;
        }else{
            resultat = false;
            printf("Hauteur invalide : la hauteur doit etre un nombre entre 0 et 15\n");
        }
        rep = strtok(NULL,",");
        if(i > LARGEUR_MAX){
            resultat = false;
            printf("Largeur invalide : le nombre de hauteurs doit etre entre 1 et 20\n");
        }else{
            hauteurs->largeur = i;
        }
    }
    return resultat;
}
