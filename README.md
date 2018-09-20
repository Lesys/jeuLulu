Bonjour à tous/toutes et merci d'être sur la page de ce projet.

Pour faire simple, ce programme a pour but d'assister un jeu de carte de plateau, ce dernier étant composé de pioches.
Ces pioches sont donc simulées dans et par le programme, avec le nombre de cartes de chaque catégorie dans le fichier "include/liste.txt".

Le jeu est composé de plusieurs pioches:
    - Les pioches de héros: Les héros sont des cartes que les joueurs possèderont et qui leur permettront de combattre.
    Il en existe plusieurs:
        - Les héros COMMUNS: Il y a 1 chance sur 4 que la carte se transforme en héros RARE de caractéristique aléatoire.
        - Les héros RARES: Il y a 3 types de pioches, 1 pour chaque caractéristique:
            - Les héros RARES force
            - Les héros RARES détermination
            - Les héros RARES charisme
          Chacune de ces pioches a 1 chance sur 4 que la carte se transforme en héros EPIQUE de la même caractéristique
    - Les héros EPIQUES: Ces pioches ne sont pas utilisées directement, mais par les pioches de héros RARES (probabilité d'augmentation de la rareté).
    - Les chances: Ces cartes sont des cartes bonus accordés aux joueurs.
    - Les pièges: A l'inverse des bonus, ces cartes pièges seront là pour empêcher les joueurs de progresser / ralentir les joueurs.
    - Les vilains: Ce sont les "boss" du jeu. Il faut les affronter pour gagner des points et terminer la partie.
    - La pioche EQUIPEMENT: Cette pioche est spéciale. Elle va chercher des cartes chances jusqu'à ce qu'une carte équipement soit piochée.
        Seul le GM / MJ / MdJ peut savoir si la carte piochée est une équipement ou non. Le but de cette carte est de piocher jusqu'à
        avoir une carte équipement, sans défausser les cartes chances piochées entre temps.

Voilà à peu près les spécifications de ce programme.
Il est fait exclusivement en C avec un Makefile.

L'objectif pour la suite de ce programme est de développer une interface graphique pour pouvoir simuler les pioches.


Merci d'avoir lu et bon jeu si vous voulez utiliser ce programme, pour ce jeu ou un autre si vous voulez le modifier (vous en êtes libres si vous le pouvez).
