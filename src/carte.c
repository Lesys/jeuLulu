void afficher_carte(Pioche* carte) {
	Carte* prec;

	if (!carte_get_prec(carte, &prec)) {
		char* nom;
		int check;
		check = carte_get_nom(carte, nom);

		if (!check)
		        printf("Carte actuelle: %s\n", nom);

		if (!carte_null(prec)) {
			check = carte_get_nom(prec, nom);

			if (!check)
			        printf("Carte précédente: %s\n", nom);
		}
		else
			fprintf(stderr, "La carte précédente est NULL\n");
	}
	else
		fprintf(stderr, "Affichage carte: Problème lors de la récupération de la carte précédente\n");
}

/*struct carte {
        char* nom_carte;
        Effet effet;
        Utilisation utilisation; 
        Chara* chara;
};
*/

int carte_null(Carte* c) {
	return (c == NULL);
}

int carte_get_nom(Carte* c, char* nom) {
	int retour = 0;

	if (!carte_null(c))
		nom = c->nom_carte;
	else
		retour = 1;

	return retour;
}

int carte_set_nom(Carte* c, char* nom) {
	int retour = 0;

	if (!carte_null(c))
		/* Si le nom à donner n'est pas "corrompu" (non NULL et contient au moins un caractère) */
		if (nom != NULL && strlen(nom) > 0)
			strcpy(c->nom_carte, nom);
		else
			retour = 2;
	else
		retour = 1;

	return retour;
}

int carte_get_prec(Carte* c, Carte** prec) {
	int retour = 0;

	if (!carte_null(c)) {
		*prec = c->prec;
	}
	else
		retour = 1;

	return retour;
}

int carte_set_prec(Carte* c, Carte* prec) {
	int retour = 0;

	if (!carte_null(c)) {
		if (!carte_null(prec)
			c->prec = prec;
		else
			retour = 2;
	}
	else
		retour = 1;

	return retour;
}
