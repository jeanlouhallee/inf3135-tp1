/**
 *
 * TP1 du cours Construction et maintenance de logiciels.
 *
 * Sigle du cours :INF3135
 *
 * Université du Québec à Montréal
 *
 * Auteur : Jean-Lou Hallée HALJ05129309
 *
 * Dernières modifications : 6 octobre 2016.
 *
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

// ---------- //
// Constantes //
//------------//

#define SEPARATEUR "," // Le caractère délimiteur dans la chaine de caractère des hauteurs.

#define CARACTERE_VIDE '-' // Le caractère vide de la montagne (Ce n'est pas de l'eau ni de la terre).

#define HAUTEUR_MAX 15 // Le nombre maximal accepté pour une hauteur.

#define LARGEUR_MAX 20 // Le nombre de hauteurs maximal accepté.

//-----------------------//
// Structures de donnees //
//-----------------------//

/**
 *
 * Structure représentant un tableau de hauteurs, avec une largeur.
 *
 */
struct tabHauteurs {

    int largeur;
    int contenu[LARGEUR_MAX];

};

/**
 *
 * Structure représentant un tableu deux dimensions de caractères,
 * ainsi qu'une largeur et une hauteur.
 *
 */
struct Montagne {
    int hauteur;
    int largeur;
    char contenu[LARGEUR_MAX][HAUTEUR_MAX];
};

// ---------- //
// Prototypes //
//------------//

/**
 * Cette fonction vérifie le nombre d'arguments passés en paramètres.
 *
 * @param nbArg, le nombre d'arguments (argc).
 *
 * @return vrai si le nombre d'arguments est 3, faux sinon.
 */
bool verifieNbArguments(int nbArg);

/**
 * Cette fonction vérifie que les caractères 'terre' et 'eau' soient acceptables.
 *
 * @param valeurArgv, un "tableau de tableaux" contenant des caractères (pointeurs).
 *
 * @return vrai si les caractères sont acceptables, faux sinon.
 */
bool sontCaracteresAcceptables(char *valeurArgv[]);

/**
 * Cette fonction s'assure que les hauteurs respectent les conditions 
 * (1 à 20 hauteurs entre 0 et 15).
 *
 * @param valeurArgv, un tableau de tableaux contenant des caratères.
 * @param tabHauteurs, un pointeur vers une structure représentant un tableau de hauteurs.
 *
 * @return true si les hauteurs remplissent les conditions, faux sinon.
 */
bool verifierHauteurs(char *valeurArgv[],struct tabHauteurs *h);

/**
 * Cette fonction construit la montagne; "caractères terre" et "caractères vide" seulement.
 *
 * @param terre, le caractère représentant la terre de la montagne.
 * @param tabHauteurs, un pointeur vers une structures représentant un tableau de hauteurs.
 * @param montagne, un pointeur vers une structure représentant les caractéristiques
 *  de la montagne.
 *
 * @return void.
 */
void construireMontagne(char terre, struct tabHauteurs *hauteur, struct Montagne *montagne);

/**
 * Cette fonction sert à afficher la montagne.
 *
 * @param montagne, un pointeur vers une structure représentant la montagne à afficher.
 *
 * @return void.
 */
void afficherMontagne(struct Montagne *montagne);

/**
 * Cette fonction trouve la plus grande hauteur de la montagne.
 *
 * @param tabHauteurs, un pointeur vers une structure représentant un tableau de hauteurs.
 *
 * @return un entier: la hauteur maximale (plus grande valeur).
 */
int trouverHauteur(struct tabHauteurs *hauteur);

/**
 * Cette fonction vérifie si une position doit contenir de l'eau.
 *
 * @param terre, le caractère terre.
 * @param montagne, un pointeur vers une structure représentant la montagne.
 * @param i, la position horizontale dans le tableau de caractères.
 * @param j, la position veritcale de le tableau de caractères.
 *
 * @return vrai si la position doit contenir de l'eau, faux sinon.
 */
bool devraitContenirEau(char terre, struct Montagne *montagne, int i, int j);

/**
 * Cette fonction ajoute l'eau dans la montagne.
 *
 * @param terre, le caractère terre.
 * @param eau, le caractère eau.
 * @param montagne, un pointeur vers la structure représentant la montagne.
 *
 * @return void.
 */
void ajouterEau(char terre, char eau, struct Montagne *montagne);

int main(int argc, char *argv[]){
    char eau;
    char terre;
    struct tabHauteurs hauteurs;
    struct Montagne montagne;

    if(verifieNbArguments(argc)){
        if(sontCaracteresAcceptables(argv)){
            terre = argv[1][0];
            eau = argv[2][0];
            if(verifierHauteurs(argv,&hauteurs)){
                construireMontagne(terre, &hauteurs, &montagne);
                ajouterEau(terre, eau, &montagne);
                afficherMontagne(&montagne);    
            }
        }
    }
}

bool devraitContenirEau(char terre, struct Montagne *montagne, int i, int j){
    bool droite = false;
    bool gauche = false;
    int copieI = i;
    int copieJ = j;
    if(montagne->contenu[i][j] == CARACTERE_VIDE){ 
         for(; copieI <= montagne->largeur ; copieI++ ){
             if(montagne->contenu[copieI][copieJ] == terre){
             droite = true;
            } 
        }
        for(; i >= 0 ; i--){
             if(montagne->contenu[i][j] == terre){
             gauche = true;
            } 
        }
    }

    return droite && gauche;
}

void ajouterEau(char terre, char eau,struct Montagne *montagne){
    int i;
    int j;
    for(i = 1; i <= montagne->largeur - 1; i++){
        for(j = 0; j <= montagne->hauteur; j++){
            if(devraitContenirEau(terre, montagne, i , j)){
                montagne->contenu[i][j] = eau;
            }
        }
    }

}

int trouverHauteur(struct tabHauteurs *hauteurs){
   int i;
   int max = 0;
   int temp;

    for(i = 0 ; i<= hauteurs->largeur - 1 ; i++){
        temp = hauteurs->contenu[i];
        if(temp > max) max = hauteurs->contenu[i];
    }
    return max;
}

void afficherMontagne(struct Montagne *montagne){
    int i;
    int j;
    for(i = montagne->hauteur ; i>= 0 ; i--){
        for(j = 0 ; j <= montagne->largeur ; j++){
            printf("%c",montagne->contenu[j][i]); 
            if(j == montagne->largeur){
                printf("\n");
            }
        }
    }
}

void construireMontagne(char terre, struct tabHauteurs *hauteur, struct Montagne *montagne){
    int i;
    int j;
    montagne->hauteur = trouverHauteur(hauteur) - 1;
    montagne->largeur = hauteur->largeur - 1;
    
    for(i = 0; i <= montagne->largeur ; i++){
        for(j = 0 ; j <= montagne->hauteur ; j++){
            if(j < hauteur->contenu[i] ){
                montagne->contenu[i][j] = terre;
            }else{
                montagne->contenu[i][j] = CARACTERE_VIDE;
            }
        }
    }
}

bool verifieNbArguments(int nbArg){
    if(nbArg < 4 || nbArg > 4){
        printf("Nombre d'arguments invalides: il en faut 3\n");
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
            printf("Code %s invalide: il doit etre un caractere unique\n",valeurArgv[2]);
            resultat = false;
        }     
    }else{
        printf("Code %s invalide: il doit etre un caractere unique\n",valeurArgv[1]);
        resultat = false;
    }
        return resultat;
}

bool verifierHauteurs(char *valeurArgv[], struct tabHauteurs *hauteurs){
    char *rep;
    int i = 0;
    int nombre;
    bool resultat = true;

    rep = strtok(valeurArgv[3],SEPARATEUR);
    while(rep != NULL && i <= LARGEUR_MAX){
    
        nombre =(int) strtol(rep,NULL,10);
        
        if(nombre >= 0 && nombre <= HAUTEUR_MAX){
            hauteurs->contenu[i] = nombre;
            i++;
        }else{
            resultat = false;
            printf("Hauteur invalide: la hauteur doit etre un nombre entre 0 et 15\n");
        }
        rep = strtok(NULL,",");
        if(i > LARGEUR_MAX){
            resultat = false;
            printf("Largeur invalide: le nombre de hauteurs doit etre entre 1 et 20\n");
        }else{
            hauteurs->largeur = i;
        }
    }
    return resultat;
}
