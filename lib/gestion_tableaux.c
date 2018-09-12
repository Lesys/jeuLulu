#include "../include/fonctions.h"

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

