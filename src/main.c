#include "../include/fonctions.h"
#include "../include/variables.h"

// Le but de ce programme est de faire des tableaux avec des numéros, mélangés, et des listes différentes
int main() {
        srand(time(NULL));

//	int fini = 0;
  //      char saisie_fin;

        // Création des tableaux
        // Héros uniquement obtenables dans le HQ/QG
	int* heros_communs = NULL;

        // Héros obtenables dans les villes (1 chacne sur 10 d'avoir une épique)
        int* heros_rare_force = NULL;
        int* heros_rare_deter = NULL;
        int* heros_rare_chari = NULL;
        int* heros_epique_force = NULL;
        int* heros_epique_deter = NULL;
        int* heros_epique_chari = NULL;

        // Cartes chance, piège et vilains
        int* chances = NULL;
        int* pieges = NULL;
        int* vilains = NULL;

	// Déclaration du tableau contenant les pioches et leur quantité
	int* nb_cartes_pioches[NB_PIOCHE][2] = {{heros_communs, &NB_HEROS_COMMUNS}, {heros_rare_force, &NB_HEROS_RARES_FORCE}, {heros_rare_deter, &NB_HEROS_RARES_DETER}, {heros_rare_chari, &NB_HEROS_RARES_CHARI},
		{heros_epique_force, &NB_HEROS_EPIQUES_FORCE}, {heros_epique_deter, &NB_HEROS_EPIQUES_DETER}, {heros_epique_chari, &NB_HEROS_EPIQUES_CHARI}, {chances, &NB_CHANCES}, {pieges, &NB_PIEGES}, {vilains, &NB_VILAINS}};


	// Appelle du fichier permettant de remplir automatiquement le nombre de carte dans chaque pioche
	lecture_fichier(nb_cartes_pioches, FILENAME);

        int i = 0;

	// Allocation des pioches
	for (i = 0; i < NB_PIOCHE; i++) {
		if ((nb_cartes_pioches[i][0] = malloc(sizeof(*(nb_cartes_pioches[i][0])) * *(nb_cartes_pioches[i][1]))) == NULL) {
			printf("Allocation ratée pour la pioche %s\n\n", Pioches[i][0]);
			exit(1);
		}
	}

        // Ajout des numéros aléatoires
        remplissage_listes(nb_cartes_pioches);

	// Mélange tous les tableaux
        for (i = 0; i < NB_PIOCHE; i++)
                shuffle(nb_cartes_pioches[i][0], *(nb_cartes_pioches[i][1]));

	// Affiche les pioches et les numéros dans l'ordre
        for (i = 0; i < NB_PIOCHE; i++)
                afficher_tableau(nb_cartes_pioches[i][0], *(nb_cartes_pioches[i][1]));

	// Libère toutes les pioches
	for (i = 0; i < NB_PIOCHE; i++)
		free(nb_cartes_pioches[i][0]);

	return 0;
}

// Nothing to see
