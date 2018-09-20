#include "fonctions.h"

// Variables globales
int NB_HEROS_COMMUNS = 0; // Nombre total de cartes communes

int NB_HEROS_RARES_FORCE = 0; // Nombre total de cartes rares de type force
int NB_HEROS_RARES_DETER = 0; // Nombre total de cartes rares de type détermination
int NB_HEROS_RARES_CHARI = 0; // Nombre total de cartes rares de type charisme

int NB_HEROS_EPIQUES_FORCE = 0; // Nombre total de cartes épiques de type force
int NB_HEROS_EPIQUES_DETER = 0; // Nombre total de cartes épiques de type détermination
int NB_HEROS_EPIQUES_CHARI = 0; // Nombre total de cartes épiques de type charisme

int NB_CHANCES = 0; // Nombre total de cartes chances
int NB_PIEGES = 0; // Nombre total de cartes pièges
int NB_VILAINS = 0; // Nombre total de vilains dans le jeu

char* FILENAME = "../include/liste.txt"; // Nom du fichier à lire avec les quantités de cartes dans chaque pioche

// Nom des pioches avec leur numéro
const char* Pioches[NB_PIOCHE][2] = {{"héros communs", "1"}, {"héros rares force", "2"}, {"héros rares détermination", "3"}, {"héros rares charisme", "4"},
	{"héros épiques force", "5"}, {"héros épiques détermination", "6"}, {"héros épiques charisme", "7"}, {"chances", "8"}, {"pièges", "9"},
	{"vilains", "10"}};

