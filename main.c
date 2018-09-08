// A ajouter à Zotero https://stackoverflow.com/questions/6127503/shuffle-array-in-c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_PIOCHE 10

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

const char* Pioches[NB_PIOCHE][2] = {{"héros communs", "1"}, {"héros rares force", "2"}, {"héros rares détermination", "3"}, {"héros rares charisme", "4"}, {"héros épique force", "5"}, {"héros épique détermination", "6"},
	{"héros épique charisme", "7"}, {"chances", "8"}, {"pièges", "9"}, {"vilains", "10"}};

// Permet d'afficher une pioche
void afficher_tableau(int* pioche, int nb_cartes) {
	int i = 0;
	for (i = 0; i < nb_cartes; i++)
		printf("Carte %d: %d\n", i + 1, pioche[i]);

	printf("\n\n");
}

//
void choix_nombre_carte(int* nombre, char* phrase) {
	while (*nombre <= 0) {
        	        printf("Combien y a-t-il de cartes %s: ", phrase);
                	scanf("%d", nombre);
	        }
}

// Tire la 1ère carte de la liste et range la liste
int prendre_carte(int* liste_cartes, int nb_cartes) {

	// Récupère le numéro de la carte
	int carte = liste_cartes[0];
	int i = 1;

	// D2cale toutes les cartes de 1 cran vers la gauche du tableau
	for (i = 1; i < nb_cartes && liste_cartes[i]; i++)
		liste_cartes[i - 1] = liste_cartes[i];

	// Ajoute un 0 à la fin du tableau
	liste_cartes[--i] = 0;

	// La dernière carte vient d'être piochée

	// Si carte == 0, alors il n'y a plus de carte dans cette pioche (== pioche vide)
	return carte;
}

// Permet de tirer une carte en fonction de la carte à tirer
int tirer_carte(int* nb_cartes_pioches[NB_PIOCHE][2], int choix) {

	int carte = 0;
	int chance = 0;

	// En fonction de la pioche choisie, un traitement différent s'oppère
	switch (choix) {
		case 1: /*int chance = rand() % 10;
			// Rare à la palce de commune
			if (chance == 1) {
				chance = (rand() % 3) + 1;
				carte = prendre_carte(nb_cartes_pioches[chance][0], *(nb_cartes_pioches[chance][1]));
			}
			else // Carte commune
				carte = prendre_carte(nb_cartes_pioches[choix][0], *(nb_cartes_pioches[choix][1]));
			break;*/
		case 2:
		case 3:
		case 4: chance = rand() % 10;
			// Rang au dessus
			if (chance == 1) {
				printf("\n-------------------\nCHANCE!! La rareté de la carte passe à %s.\n", (choix == 1? "rare" : "épique"));
				chance = (choix == 1? (rand() % 3) + (choix == 1? 1 : 4) : choix + 2);
				printf("Type de la pioche: %s\n-------------------\n\n", (chance % 3 - 1 == 0? "Force" : (chance % 3 - 1 == 1? "Détermination" : "Charisme")));
				carte = prendre_carte(nb_cartes_pioches[chance][0], *(nb_cartes_pioches[chance][1]));
                        }
			else // Rang normal de la carte
				carte = prendre_carte(nb_cartes_pioches[choix - 1][0], *(nb_cartes_pioches[choix - 1][1]));
			break;

		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10: carte = prendre_carte(nb_cartes_pioches[choix - 1][0], *(nb_cartes_pioches[choix - 1][1]));
			break;

		default: printf("Cette pioche n'existe pas\n\n");
			break;
	}

	// Affiche si la pioche est vide
	if (!carte)
		printf("La pioche \"%s\" est vide\n\n", Pioches[choix - 1][0]);

	// Renvoie la carte sélectionnée
	return carte;
}

// Permet de remplir les listes avec les numéros de toutes les cartes de chaque catégorie
void remplissage_listes(int* nb_cartes_pioches[NB_PIOCHE][2]) {

	int i = 0, j = 0;
	// Permet de parcourir toutes les pioches
	for (i = 0; i < NB_PIOCHE; i++) {
		// Parcour la pioche en cour pour ajouter les numéros
		for (j = 1; j <= *(nb_cartes_pioches[i][1]); j++) {
			// Ajoute les numéros de 1 à X dans le tableau correspondant
			(*(nb_cartes_pioches[i]))[j - 1] = j;
		}
	}
}

// Mélange les éléments d'un tableau
void shuffle(int* pioche, int nb_cartes)
{
	if (nb_cartes > 1)
	{
		int i;
		for (i = 0; i < nb_cartes - 1; i++)
		{
			int j = i + rand() / (RAND_MAX / (nb_cartes - i) + 1);
			int t = pioche[j];
			pioche[j] = pioche[i];
			pioche[i] = t;
		}
	}
}

// Le but de ce programme est de faire des tableaux avec des numéros, mélangés, et des listes différentes
int main() {
	srand(time(NULL));

	// L'utilisateur choisi le nombre de chaque carte
	choix_nombre_carte(&NB_HEROS_COMMUNS, "héros communs");
	choix_nombre_carte(&NB_HEROS_RARES_FORCE, "héros rares force");
	choix_nombre_carte(&NB_HEROS_RARES_DETER, "héros rares détermination");
	choix_nombre_carte(&NB_HEROS_RARES_CHARI, "héros rares charisme");
	choix_nombre_carte(&NB_HEROS_EPIQUES_FORCE, "héros épiques force");
	choix_nombre_carte(&NB_HEROS_EPIQUES_DETER, "héros épiques détermination");
	choix_nombre_carte(&NB_HEROS_EPIQUES_CHARI, "héros épiques charisme");
	choix_nombre_carte(&NB_CHANCES, "chance");
	choix_nombre_carte(&NB_PIEGES, "piège");
	choix_nombre_carte(&NB_VILAINS, "vilains");

	int fini = 0;
	char saisie_fin;
	// Création des tableaux
	// Héros uniquement obtenables dans le HQ/QG
	int heros_communs[NB_HEROS_COMMUNS];

	// Héros obtenables dans les villes (1 chacne sur 10 d'avoir une épique)
        int heros_rare_force[NB_HEROS_RARES_FORCE];
        int heros_rare_deter[NB_HEROS_RARES_DETER];
        int heros_rare_chari[NB_HEROS_RARES_CHARI];
        int heros_epique_force[NB_HEROS_EPIQUES_FORCE];
        int heros_epique_deter[NB_HEROS_EPIQUES_DETER];
        int heros_epique_chari[NB_HEROS_EPIQUES_CHARI];

	// Cartes chance, piège et vilains
	int chances[NB_CHANCES];
	int pieges[NB_PIEGES];
	int vilains[NB_VILAINS];

	int* nb_cartes_pioches[NB_PIOCHE][2] = {{heros_communs, &NB_HEROS_COMMUNS}, {heros_rare_force, &NB_HEROS_RARES_FORCE}, {heros_rare_deter, &NB_HEROS_RARES_DETER}, {heros_rare_chari, &NB_HEROS_RARES_CHARI},
		{heros_epique_force, &NB_HEROS_EPIQUES_FORCE}, {heros_epique_deter, &NB_HEROS_EPIQUES_DETER}, {heros_epique_chari, &NB_HEROS_EPIQUES_CHARI}, {chances, &NB_CHANCES}, {pieges, &NB_PIEGES}, {vilains, &NB_VILAINS}};

	// Ajout des numéros aléatoires
	remplissage_listes(nb_cartes_pioches);

//	afficher_tableau((nb_cartes_pioches[0][0]), *(nb_cartes_pioches[0][1]));

	// Mélange tous les tableaux
	int i = 0;
	for (i = 0; i < NB_PIOCHE; i++)
		shuffle(nb_cartes_pioches[i][0], *(nb_cartes_pioches[i][1]));

	for (i = 0; i < NB_PIOCHE; i++)
		afficher_tableau(nb_cartes_pioches[i][0], *(nb_cartes_pioches[i][1]));
	// A enlever  à la fin -- Test
//	printf("Commun: %d\nRare Force: %d\nRare DéterminationEpique: %d\nChance: %d\nPiege: %d\nEnnemi: %d\n", NB_HEROS_COMMUNS, NB_HEROS_RARES, NB_HEROS_EPIQUES, NB_CHANCES, NB_PIEGES, NB_VILAINS);

	// Boucle pour tirer les cartes
	while (!fini) {

		// Choix de l'utilisateur

		printf("Quel type de carte voulez-vous piocher?\n");

		for (i = 0; i < NB_PIOCHE; i++) {
			printf("%s°) %s\n", Pioches[i][1], Pioches[i][0]);
}/*
		printf("Quel type de carte voulez-vous piocher?\n1°) Héros commun\n2°) Héros rare/force\n3°) Héros rare/détermination\n4°) Héros rare/charisme\n5°) Héros épique/force\n");
		printf("6°) Héros épique/détermination\n7°) Héros épique/charisme\n8°) Carte chance\n9°) Carte piège\n10°) Vilain\n\nVotre choix: ");*/

		int choix = -1;
		printf("0°) Arrêter le programme\nVotre choix: ");

		while ((choix < 1 || choix > NB_PIOCHE) && (choix != 0)) {
			if (choix != -1)
				printf("Veuillez choisir un choix entre 1 et %d\n", NB_PIOCHE);

			scanf("%d", &choix);
		}

		if (choix) {
			// Tire la carte de la pioche du joueur
			int carte = tirer_carte(nb_cartes_pioches, choix);

			if (carte)
				printf("\n-------------------\nVous avez tiré la carte %d de la pioche %s\n-------------------\n\n", carte, Pioches[choix - 1][0]);
			else
				printf("\n-------------------\nIl n'y a plus de carte dans le paquet %s\n-------------------\n\n", Pioches[choix - 1][0]);

			printf("Pour arrêter le jeu, saisissez \"n\" ou \"N\", sinon appuyez sur ENTER\n");
			scanf("%c", saisie_fin);
			scanf("%c", saisie_fin);
		}
		else
			fini = 1;

	}
	return 0;
}
