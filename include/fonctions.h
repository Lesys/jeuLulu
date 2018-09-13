#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define NB_PIOCHE 10

const char* Pioches[NB_PIOCHE][2];/* = {{"héros communs", "1"}, {"héros rares force", "2"}, {"héros rares détermination", "3"}, {"héros rares charisme", "4"},
        {"héros épique charisme", "7"}, {"chances", "8"}, {"pièges", "9"}, {"vilains", "10"}};*/

// Déclarations des fonctions au préalable
void afficher_tableau(int*, int);

void choix_nombre_carte(int*, char*);

int prendre_carte(int*, int);

int tirer_carte(int* nb_cartes_pioches[NB_PIOCHE][2], int);

void remplissage_listes(int* nb_cartes_pioches[NB_PIOCHE][2]);

void shuffle(int*, int);

void lecture_fichier(int* nb_cartes_pioches[NB_PIOCHE][2], char*);
