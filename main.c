#include <stdio.h>
#include <stdlib.h>

#define NB_PIOCHE 6

// Variables globales
int NB_HEROS_COMMUNS = 0;
int NB_HEROS_RARES = 0;
int NB_HEROS_EPIQUES = 0;
int NB_CHANCES = 0;
int NB_PIEGES = 0;
int NB_VILAINS = 0;



void choix_nombre_carte(int* nombre, char* phrase) {
	while (*nombre <= 0) {
        	        printf("Combien y a-t-il de cartes %s: ", phrase);
                	scanf("%d", nombre);
	        }
}

void tirer_carte() {
	int choix = 0;

	while (choix < 1 || choix > NB_PIOCHE) {
		printf("Quelle type de pioche utiliser?\n1°) Pioche commune\n2°) Pioche rare\n3°) Chance\n4°) Piège\n5°) Pioche d'ennemis\nVotre choix: ");
	}
}

void remplissage_liste(int heros_hq[], int heros_force[], int heros_deter[], int heros_chari[], int chances[], int pieges[], int vilains[]) {
	/*int nb_cartes_pioches[2][NB_PIOCHE] = {{heros_hq, NB_HEROS_COMMUNS}, {herosNB_HEROS_RARES, NB_HEROS_EPIQUES, NB_CHANCES, NB_PIEGES, NB_VILAINS};

	// Permet de parcourir toutes les pioches
	for (int i = 0; i < NB_PIOCHE; i++) {
		// Parcour la pioche en cour pour ajouter les numéros
		for (int j = 1; j <= nb_cartes_pioches[i]; j++) {
			
		}
	}*/
}

// Le but de ce programme est de faire des tableaux avec des numéros, mélangés, et des listes différentes
int main() {

	// L'utilisateur choisi le nombre de chaque carte
	choix_nombre_carte(&NB_HEROS_COMMUNS, "héros communs");
	choix_nombre_carte(&NB_HEROS_RARES, "héros rares");
	choix_nombre_carte(&NB_HEROS_EPIQUES, "héros épiques");
	choix_nombre_carte(&NB_CHANCES, "chance");
	choix_nombre_carte(&NB_PIEGES, "piège");
	choix_nombre_carte(&NB_VILAINS, "vilains");

	// Création des tableaux
	// Héros uniquement obtenables dans le HQ/QG
	int heros_communs[NB_HEROS_COMMUNS];

	// Héros obtenables dans les villes (1 chacne sur 10 d'avoir une épique)
        int heros_rare_force[NB_HEROS_RARES];
        int heros_rare_deter[NB_HEROS_RARES];
        int heros_rare_chari[NB_HEROS_RARES];
        int heros_epique_force[NB_HEROS_EPIQUES];
        int heros_epique_deter[NB_HEROS_EPIQUES];
        int heros_epique_chari[NB_HEROS_EPIQUES];

	// Cartes chance, piège et vilains
	int chances[NB_CHANCES];
	int pieges[NB_PIEGES];
	int vilains[NB_VILAINS];

	// Ajout des numéros aléatoires
	remplissage_listes(heros_hq, heros_force, heros_deter, heros_chari, chances, pieges, vilains);

	// A enlever  à la fin -- Test
	printf("Commun: %d\nRare: %d\nEpique: %d\nChance: %d\nPiege: %d\nEnnemi: %d\n", NB_HEROS_COMMUNS, NB_HEROS_RARES, NB_HEROS_EPIQUES, NB_CHANCES, NB_PIEGES, NB_VILAINS);

	// Boucle pour tirer les cartes
	while (!fini) {

		// Choix de l'utilisateur
		printf("Que voulez-vous faire?\n1°) Piocher un héros commun\n2°) Piocher un héros rare/force");
		int choix = 0, nb_choix = 3;

		while (choix < 1 || choix > nb_choix) {
			if (choix != 0)
				printf("Veuillez choisir un choix entre 1 et %d\n", nb_choix);

			scanf("%d", &choix);
		}

		// Lance le choix de l'utilisateur
		switch (choix) {
			case 1: tirer_carte();
				break;
			default: break;
		}

	}
	return 0;
}
