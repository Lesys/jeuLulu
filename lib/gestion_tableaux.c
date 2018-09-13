#include "../include/fonctions.h"

void lecture_fichier(int* nb_cartes_pioches[NB_PIOCHE][2], char* filename) {
	FILE* file;

	printf("nom fichier: %s\n\n", filename);

	if (fopen("../include/liste.txt", "r")) {
	char ligne[30] = "héros communs;39";
	int taille = 0, i = 0, j = 0, num_pioche = 0, nb_cartes = 0;

	printf("Début de la lecture:\n\n");

	// Lecture de toutes les lignes dans le fichier
//	while (fscanf(file, "%s", ligne)){//, &nb_cartes)) {
		printf("Lecture ligne: %s\n\n", ligne);
		taille = strlen(ligne);
		i = taille;
		nb_cartes = 0;
		num_pioche = 0;

		// Recherche l'endroit de la séparation
		while (ligne[--i] != ';');

		while (j < i) {
			// Regarde quel nom correspond à quelle pioche, puis donne le numéro à la pioche
			for (j = 0; j < i && ligne[j] == (Pioches[num_pioche][0])[j]; j++);

			num_pioche += j != i? 1 : 0;
		}

		printf("La ligne %s correspond à %s\n\n", ligne, Pioches[num_pioche][0]);

		while (++i < taille)
			nb_cartes = nb_cartes * 10 + ligne[i] - '0';

		printf("Il y a %d cartes\n\n", nb_cartes);

		// Ajoute le nombre de cartes dans la pioche correspondante
		*(nb_cartes_pioches[num_pioche][1]) = nb_cartes;
	}
	printf("fin de la lecture dans la fonction\n\n");
	fclose(file);
//	}
//	else
//		printf("Fichier non ouvert\n\n");

}

// Permet de remplir les listes avec les numéros de toutes les cartes de chaque catégorie
void remplissage_listes(int* nb_cartes_pioches[NB_PIOCHE][2]) {

        int i = 0, j = 0;
        // Permet de parcourir toutes les pioches
        for (i = 0; i < NB_PIOCHE; i++) {
                // Parcour la pioche en cours pour ajouter les numéros
                for (j = 1; j <= *(nb_cartes_pioches[i][1]); j++) {
                        // Ajoute les numéros de 1 à X dans le tableau correspondant
                        (*(nb_cartes_pioches[i]))[j - 1] = j;
                }
        }
}

// Permet d'afficher une pioche
void afficher_tableau(int* pioche, int nb_cartes) {
        int i = 0;
        for (i = 0; i < nb_cartes; i++)
                printf("Carte %d: %d\n", i + 1, pioche[i]);

        printf("\n\n");
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

