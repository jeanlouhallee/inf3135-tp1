# Travail pratique 1

## Description

Premier TP dans le cadre du cours Construction et maintenance de logiciels.
INF3135, Université du Québec à Montréal. Remise le 7 octobre à 23h59.

## Auteur

Jean-Lou Hallée (HALJ05129309)

## Fonctionnement

Ce programme prend en entrée deux caractères distincts (un pour la terre, et un pour l'eau), ainsiqu'une suite de nombres (séparés par des virgules) représentant des hauteurs. La sortie représente l'affichage d'une montagne sous forme de caractères. Les sections où l'eau devrait s'accumuler est également représentée par un caractère.

Voici quelques exemples d'entrées et de sorties:

**Entrée:**
~~~~
./tp1 X E 1,2,5,2,0,1,3
~~~~
**Sortie:**
~~~~
--X----  
--X----   
--XEEEX   
-XXXEEX   
XXXXEXX   
~~~~
**Entrée:**
~~~~
./tp1 X E 1,2,3,4,5,6
~~~~
**Sortie:**
~~~~
-----X   
----XX   
---XXX   
--XXXX   
-XXXXX   
XXXXXX   
~~~~
**Entrée:**
~~~~
./tp1 A Z 5,1,1,1,5,9
~~~~
**Sortie:**
~~~~
-----A  
-----A   
-----A   
-----A  
AZZZAA   
AZZZAA  
AZZZAA  
AZZZAA   
AAAAAA   
~~~~
## Contenu du projet

*   tp1.c: Fichier source du projet contenant le code.
*   README.md: Fichier décrivant la totalité du projet.
*   makefile: Fichier générant la compilation à l'aide de la commande "make" et nettoyage des fichiers non désirés à l'aide de la commande "make clean".
*   .gitignore: Permet d'ignorer ...
*   test.bats & .gitlab.yml: Ces fichiers permettent d'exécuter automatiquement une suite de tests lors d'un ajout sur Gitlab.

## Références

Un grand merci à https://www.stackoverflow.com pour le soutien. 

## Statut

Projet complété : aucun bogue reconnu pour l'instant.
