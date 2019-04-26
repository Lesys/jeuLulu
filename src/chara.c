#include <stdio.h>
#include <stdlib.h>
#include "../include/chara.h"

char* type_chara_tostring(Type_Chara type) {
	//RIEN = 0, FORCE, DETER, CHARISME, FORCE_DETER, FORCE_CHARISME, DETER_CHARISME, FORCE_DETER_CHARISME
	switch (type) {
		case RIEN_CHARA: return "Aucune charactéristique";
			break;
		case FORCE: return "Force";
			break;
		case DETER: return "Deter";
			break;
		case CHARISME: return "Charisme";
			break;
		case FORCE_DETER: return "Force/Deter";
			break;
		case FORCE_CHARISME: return "Force/Charisme";
			break;
		case DETER_CHARISME: return "Deter/Charisme";
			break;
		case FORCE_DETER_CHARISME: return "Force/Charisme";
			break;
		default: return "Problème type_chara inexistant";
			break;
	}
}

void chara_afficher(Chara* c) {
	if (!chara_null(c)) {
		printf("Charactéristique de la carte: %s\n", type_chara_tostring(c->chara_princ));

		printf("Force: %d\nDéter: %d\nCharisme: %d\n", c->force, c->deter, c->charisme);
	}
	else
		printf("Aucune charactéristique\n");
}

int chara_null(Chara* c) {
	return (c == NULL);
}

/* Accesseurs et mutateurs */
int chara_get_type(Chara* c, Type_Chara* tc) {
	int retour = 0;

	if (!chara_null(c))
		*tc = c->chara_princ;
	else
		retour = 1;

	return retour;
}

int chara_set_type(Chara* c, Type_Chara tc) {
	int retour = 0;

	if (!chara_null(c))
		c->chara_princ = tc;
	else
		retour = 1;

	return retour;
}

int chara_get_force(Chara* c, int* force) {
	int retour = 0;

	if (!chara_null(c))
		*force = c->force;
	else
		retour = 1;

	return retour;
}

int chara_set_force(Chara* c, int force) {
	int retour = 0;

	if (!chara_null(c))
		if (force >= 0)
			c->force = force;
		else
			retour = 2;
	else
		retour = 1;

	return retour;
}

int chara_get_deter(Chara* c, int* deter) {
	int retour = 0;

	if (!chara_null(c))
		*deter = c->deter;
	else
		retour = 1;

	return retour;
}

int chara_set_deter(Chara* c, int deter) {
	int retour = 0;

	if (!chara_null(c))
		if (deter >= 0)
			c->deter = deter;
		else
			retour = 2;
	else
		retour = 1;

	return retour;
}

int chara_get_charisme(Chara* c, int* charisme) {
	int retour = 0;

	if (!chara_null(c))
		*charisme = c->charisme;
	else
		retour = 1;

	return retour;
}

int chara_set_charisme(Chara* c, int charisme) {
	int retour = 0;

	if (!chara_null(c))
		if (charisme >= 0)
			c->charisme = charisme;
		else
			retour = 2;
	else
		retour = 1;

	return retour;
}
/* Fin accesseurs et mutateurs */

int chara_detruire(Chara** c) {
	int retour = 0;

	if (!chara_null(*c)) {
		free(*c);
		*c = NULL;
	}

	return retour;
}

int chara_init(Chara** c, Type_Chara type, int force, int deter, int charisme) {
	int retour = 0;

	if (!chara_null(*c))
		chara_detruire(c);

	if ((*c = malloc(sizeof(**c))) != NULL) {
		retour = chara_set_type(*c, type);

		if (!retour) {
			retour = chara_set_force(*c, force);

			if (!retour) {
				retour = chara_set_deter(*c, deter);

				if (!retour)
					retour = chara_set_charisme(*c, charisme);
			}
		}

		if (retour)
			chara_detruire(c);
	}


	return retour;
}
