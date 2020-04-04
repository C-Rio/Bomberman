#include <stdlib.h>
#include <stdio.h>
#include "libTableauNoir.h"

/* Declaration de structures et constantes */
#define LARGEUR 900
#define HAUTEUR 900
#define TAILLE_BLOC 60
#define H_REC 50
#define L_REC 400
#define TAILLE_TRAIS 3

typedef struct {                                    // Structure coordonn�es
                int x;
                int y;
                } coord_t;

typedef struct {                                    // Structure couleur
                int r;
                int v;
                int b;
                } couleur_t;

typedef struct {                                    // Structure joueur
                int n;                              // Num�ro du joueur
                Image I[13];                        // Images du personnage
                couleur_t clr;
                coord_t c;
                int puissance;                      // Puissance (bombes)
                int nb_bombe;                       // Nombre de bombes
                int v;                              // Vitesse
                int etat;                           // 0 si mort / 1 si vivant
                int haut;
                int bas;
                int droite;
                int gauche;
                } player_t;

typedef struct {                                    // Structure bombe
                coord_t c;
                int puissance;                      // Largeur de l'explosion
                int player;                         // Joueur auquel la bombe appartient
                double t;                           // Temps pour explosion
                } bombe_t;

typedef struct {                                    // Structure bloc (cases)
                int type;
                coord_t c;
                double t;                           // temps du bloc (si explosion)
                } bloc_t;

typedef struct {                                    // Structure terrain (jeu)
                int type;                           // Choix du d�cors 1 ou 2
                bloc_t b[15][15];                   // Blocs du d�cors
                player_t p[2];                      // Joueurs
                Image I[120];                       // Images servant au jeu
                bombe_t bmb[15][15];                // Bombes (tableau correspontdant � celui des blocs
                } terrain_t;

terrain_t terrain;
int x[36];
int y[36];
double tp[12];


/* Declaration de fonctions */

void chargement_Menu();
int menu(player_t);
int options(player_t);
int choix_terrain(player_t);
int choix_perso(player_t);
int controles(player_t);
void dessiner_rectangle(Image, int, int, int, couleur_t);
player_t red_player();
player_t blue_player();
player_t black_player();
player_t white_player();
player_t gold_player();
int jeu(player_t *);
terrain_t init_terrain(terrain_t);
terrain_t affiche_terrain (terrain_t, double);
terrain_t explosion(terrain_t, double);
coord_t position_grille(coord_t c);
void player(player_t *);
int deplacement_gauche (player_t);
int deplacement_droite (player_t);
int deplacement_haut (player_t);
int deplacement_bas (player_t);
void poser_bombe(player_t *, double t);
void chargement_Terrain();
