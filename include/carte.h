#ifndef CARTE_H
#define CARTE_H

typedef enum effet{RIEN = 0, SOIN, TP, DEGAT, CHANGE_CHARA/*, ... */} Effet;

typedef enum utilisation{RIEN = 0, INSTANT, CONTINUE, EQUIPEMENT, UNIQUE} Utilisation;

typedef enum type_chara{RIEN = 0, FORCE, DETER, CHARISME, FORCE_DETER, FORCE_CHARISME, DETER_CHARISME, FORCE_DETER_CHARISME} Type_Chara;

typedef enum type_carte{COMMUN = 0, RARE_FORCE, RARE_DETER, RARE_CHARISME, EPIQUE_FORCE, EPIQUE_DETER, EPIQUE_CHARISME, CHANCE, MALUS, VILAIN} Type_Carte;


/* Structure de pile */
typedef struct carte Carte;

typedef struct pioche Pioche;

typedef struct characteristiques Chara;

typedef struct liste_pioche {
	Pioche* p;
	Pioche* first;
} Liste_Pioche;

struct pioche {
//	char* nom_pioche;
	Type_Carte type; /** < Type de la pioche */
	Carte* carte; /** < Liste des cartes de la pioche (pile) */
};

struct carte {
	/* Informations de la carte */
	char* nom_carte;
	Effet effet; /** < Effet de la carte. */
	Utilisation utilisation; /** < Moment de l'utilisation de l'effet. */
	Chara* chara; /** < Pointeur vers les charactéristiques de la carte (NULL si pas une carte de combat). Si carte de bonus, bien remplir les champs avec le svaleurs à ajouter. */

	Carte* prec; /** < Carte précédente (Carte appartient à une pile, donc la carte directement en dessous (NULL si cette carte est la dernière). */
};

struct characteristiques {
	Type_Chara chara_princ; /** < Le type de charactéristique(s) principale(s) de la carte **/
	int force; /** < Valeur de force de la carte */
	int deter; /** < Valeur de détermination de la carte */
	int charisme; /** < Valeur de charisme de la carte */
};



#endif
