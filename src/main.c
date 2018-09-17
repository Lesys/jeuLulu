// A ajouter à Zotero https://stackoverflow.com/questions/6127503/shuffle-array-in-c

#include "../include/fonctions.h"
#include "../include/variables.h"

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
		}
		else
			fini = 1;

	}
	return 0;
}
