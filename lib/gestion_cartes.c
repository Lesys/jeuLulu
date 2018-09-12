#include "../include/fonctions.h"

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

