#include "../include/fonctions.h"
#include "../include/variables.h"

// Le but de ce programme est de faire des tableaux avec des numéros, mélangés, et des listes différentes
int main() {
        srand(time(NULL));

//	int fini = 0;
  //      char saisie_fin;

	int* heros_communs = NULL;

        // Création des tableaux
        // Héros uniquement obtenables dans le HQ/QG
        //int heros_communs[NB_HEROS_COMMUNS];

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


	printf("Début dans le main\n\n");
	// Appelle du fichier permettant de remplir automatiquement le nombre de carte dans chaque pioche
	lecture_fichier(nb_cartes_pioches, "../include/liste.txt");

	printf("Fin dans le main\n\n");

        int i = 0;
        for (i = 0; i < NB_PIOCHE; i++)
		printf("Taille pioche %d: %d\n", i + 1, *(nb_cartes_pioches[i][1]));

	if ((heros_communs = malloc(sizeof(int) * *(nb_cartes_pioches[0][1]))) != NULL)
		printf("Allocation OK\n\n");
	else
		printf("Allocation ratée\n\n");

        // Ajout des numéros aléatoires
        remplissage_listes(nb_cartes_pioches);

	// Mélange tous les tableaux
        for (i = 0; i < NB_PIOCHE; i++)
                shuffle(nb_cartes_pioches[i][0], *(nb_cartes_pioches[i][1]));

        for (i = 0; i < NB_PIOCHE; i++)
                afficher_tableau(nb_cartes_pioches[i][0], *(nb_cartes_pioches[i][1]));

	free(heros_communs);
	return 0;
}

// Nothing to see
