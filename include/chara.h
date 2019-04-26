#ifndef CHARA_H
#define CHARA_H

typedef enum type_chara{RIEN_CHARA = 0, FORCE, DETER, CHARISME, FORCE_DETER, FORCE_CHARISME, DETER_CHARISME, FORCE_DETER_CHARISME} Type_Chara;

typedef struct characteristiques Chara;

struct characteristiques {
	Type_Chara chara_princ; /** < Le type de charactéristique(s) principale(s) de la carte **/
	int force; /** < Valeur de force de la carte */
	int deter; /** < Valeur de détermination de la carte */
	int charisme; /** < Valeur de charisme de la carte */
};

int chara_init(Chara**, Type_Chara, int, int, int);

int chara_detruire(Chara**);

int chara_null(Chara*);

void chara_afficher(Chara*);

#endif
