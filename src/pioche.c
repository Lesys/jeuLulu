#include "../include/pioche.h"
#include "../include/carte.h"

int pioche_vide(Pioche* p) {
	return (p->sommet == NULL);
}

int pioche_null(Pioche* p) {
	return (p == NULL);
}

int pioche_sommet(Pioche* p, Carte** c) {
	int retour = 0; /* Si retour != 0, c ne pourra pas être utilisé */

	/* Si la pioche est ni NULL, ni VIDE: On récupère la carte */
	if (!pioche_null(p)) {
		if (!pioche_vide(p))
			*c = p->sommet;
		else
			retour = 2;
	}
	else
		retour = 1;

	return retour;
}

int pioche_empiler(Pioche* p, Carte* c) {
	int retour = 0;

	if (!pioche_null(p)) {
		if (!carte_null(c)) {
			/* Affectation de l'ancien sommet au précédent du nouveau sommet + affectation du nouveau sommet */
			c->prec = p->sommet;
			p->sommet = c;
		}
		else
			retour = 2; /* Carte à empiler NULL */
	}
	else
		retour = 1; /* Pioche NULL */

	return retour;
}

int pioche_depiler(Pioche* p, Carte** c) {
	int retour = 0;

	if (!pioche_null(p)) {
		if (!pioche_vide(p))
			if (pioche_sommet(p, c))
				retour = 3; /* La carte n'est pas utilisable depuis le paramètre (pour la fonction d'appel) */
			else /* Si tout s'est bien déroulé, on "enlève" la carte du dessus (elle existe toujours) */
				retour = carte_get_prec(p->sommet, &(p->sommet));
		else
			retour = 2; /* Pioche VIDE */
	}
	else
		retour = 1; /* Pioche NULL */

	return retour;
}

int pioche_init(Pioche** p, Type_Pioche tp) {
	int retour = 0;

	/* Détruit la pioche pour la refaire si elle n'est pas NULL */
	if (!pioche_null(*p))
		retour = pioche_detruire(p);

	/* Si la destruction s'est bien passée (si elle a été faite) */
	if (!retour) {
		/* Si le malloc n'a pas abouti */
		if (pioche_null(*p = malloc(sizeof(**p))))
			retour = 1;
		else {
			*p->carte = NULL;
			*p->type = tp;
		}
	}

	return retour;
}

int pioche_detruire(Pioche** p) {
	int retour = 0;

	if (!pioche_null(*p)) {
		Carte* c;

		/* Destruction de toutes les cartes tant qu'il n'y a pas d'erreur */
/*		while (!carte_null((*p)->carte) && retour == 0) {
			retour = carte_get_prec((*p)->carte, &c);

			if (retour == 0) {
				retour = detruire_carte(&((*p)->carte));

				if (retour == 0)
					(*p)->carte = c;
			}
		}
*/

		/* Tant que la fonction ne retourne pas d'erreur */
		while (!pioche_depiler(p, &c)) {
			free(c);
			c = NULL;
		}

		/*Si la pioche a bien été vidée */
		if (pioche_vide(p)) {
			free(*p);
			*p = NULL;
		}
		else
			retour = 2; /* La pioche n'a pas été vidée entièrement */
	}

	return retour;
}
