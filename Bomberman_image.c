#include "Bomberman.h"


void chargement_Menu()           // Charge toutes les images hors jeu
{
    terrain.I[0] = chargerImage("Images/Menu/Bomberman_splash.bmp");
    terrain.I[1] = chargerImage("Images/Menu/Jouer.bmp");
    terrain.I[2] = chargerImage ("Images/Menu/Options.bmp");
    terrain.I[3] = chargerImage ("Images/Menu/Options_splash.bmp");
    terrain.I[4] = chargerImage ("Images/Menu/Terrain.bmp");
    terrain.I[5] = chargerImage ("Images/Menu/Personnages.bmp");
    terrain.I[6] = chargerImage ("Images/Menu/Retour.bmp");
    terrain.I[7] = chargerImage ("Images/Menu/Terrain_splash.bmp");

    terrain.I[8] = chargerImage ("Images/Menu/Personnages_splash.bmp");
    terrain.I[9] = chargerImage ("Images/Menu/Joueur1.bmp");
    terrain.I[10] = chargerImage ("Images/Menu/Joueur2.bmp");
    terrain.I[11] = chargerImage ("Images/Menu/V1.bmp");
    terrain.I[12] = chargerImage ("Images/Menu/V2.bmp");

    terrain.I[13] = chargerImage ("Images/Menu/Controles.bmp");
    terrain.I[14] = chargerImage ("Images/Menu/Controle.bmp");
    terrain.I[15] = chargerImage ("Images/Menu/Credits.bmp");
    terrain.I[16] = chargerImage ("Images/Menu/Credit.bmp");
    terrain.I[17] = chargerImage ("Images/Menu/Quitter.bmp");

    terrain.I[18] = chargerImage ("Images/Tiles/Terrains/1/terrain1.bmp");
    terrain.I[19] = chargerImage ("Images/Tiles/Terrains/2/terrain2.bmp");

    int i;
    for (i=18; i <=19; i++)
    {
        fixerCouleurDeTransparence(terrain.I[i], 0, 255, 0);
    }
}

/************************************************************* Choix du skin de joueur *************************************************************/


player_t red_player()
{
    player_t p = {clr: {255, 0, 0}, nb_bombe:1};
    p.I[0] = chargerImage("Images/Players/Red/face_statique.bmp");
    p.I[1] = chargerImage("Images/Players/Red/face_gauche.bmp");
    p.I[2] = chargerImage("Images/Players/Red/face_droite.bmp");
    p.I[3] = chargerImage("Images/Players/Red/dos_statique.bmp");
    p.I[4] = chargerImage("Images/Players/Red/dos_gauche.bmp");
    p.I[5] = chargerImage("Images/Players/Red/dos_droite.bmp");
    p.I[6] = chargerImage("Images/Players/Red/droite_statique.bmp");
    p.I[7] = chargerImage("Images/Players/Red/droite_gauche.bmp");
    p.I[8] = chargerImage("Images/Players/Red/droite_droite.bmp");
    p.I[9] = chargerImage("Images/Players/Red/gauche_statique.bmp");
    p.I[10] = chargerImage("Images/Players/Red/gauche_gauche.bmp");
    p.I[11] = chargerImage("Images/Players/Red/gauche_droite.bmp");
    p.I[12] = chargerImage("Images/Players/Red/Gravestone.bmp");

    int i;
    for (i=0; i<13; i++)
    {
        fixerCouleurDeTransparence(p.I[i], 0, 255, 0);
    }
    return p;
}

player_t blue_player()
{
    player_t p = {clr: {0, 0, 255}, nb_bombe:1} ;
    p.I[0] = chargerImage("Images/Players/Blue/face_statique.bmp");
    p.I[1] = chargerImage("Images/Players/Blue/face_gauche.bmp");
    p.I[2] = chargerImage("Images/Players/Blue/face_droite.bmp");
    p.I[3] = chargerImage("Images/Players/Blue/dos_statique.bmp");
    p.I[4] = chargerImage("Images/Players/Blue/dos_gauche.bmp");
    p.I[5] = chargerImage("Images/Players/Blue/dos_droite.bmp");
    p.I[6] = chargerImage("Images/Players/Blue/droite_statique.bmp");
    p.I[7] = chargerImage("Images/Players/Blue/droite_gauche.bmp");
    p.I[8] = chargerImage("Images/Players/Blue/droite_droite.bmp");
    p.I[9] = chargerImage("Images/Players/Blue/gauche_statique.bmp");
    p.I[10] = chargerImage("Images/Players/Blue/gauche_gauche.bmp");
    p.I[11] = chargerImage("Images/Players/Blue/gauche_droite.bmp");
    p.I[12] = chargerImage("Images/Players/Blue/Gravestone.bmp");

    int i;
    for (i=0; i<13; i++)
    {
        fixerCouleurDeTransparence(p.I[i], 0, 255, 0);
    }
    return p;
}

player_t black_player()
{
    player_t p = {clr: {33, 36, 33} , nb_bombe:1} ;
    p.I[0] = chargerImage("Images/Players/Black/face_statique.bmp");
    p.I[1] = chargerImage("Images/Players/Black/face_gauche.bmp");
    p.I[2] = chargerImage("Images/Players/Black/face_droite.bmp");
    p.I[3] = chargerImage("Images/Players/Black/dos_statique.bmp");
    p.I[4] = chargerImage("Images/Players/Black/dos_gauche.bmp");
    p.I[5] = chargerImage("Images/Players/Black/dos_droite.bmp");
    p.I[6] = chargerImage("Images/Players/Black/droite_statique.bmp");
    p.I[7] = chargerImage("Images/Players/Black/droite_gauche.bmp");
    p.I[8] = chargerImage("Images/Players/Black/droite_droite.bmp");
    p.I[9] = chargerImage("Images/Players/Black/gauche_statique.bmp");
    p.I[10] = chargerImage("Images/Players/Black/gauche_gauche.bmp");
    p.I[11] = chargerImage("Images/Players/Black/gauche_droite.bmp");
    p.I[12] = chargerImage("Images/Players/Black/Gravestone.bmp");

    int i;
    for (i=0; i<13; i++)
    {
        fixerCouleurDeTransparence(p.I[i], 0, 255, 0);
    }
    return p;
}

player_t white_player()
{
    player_t p = {clr: {255, 255, 255}, nb_bombe:1} ;
    p.I[0] = chargerImage("Images/Players/White/face_statique.bmp");
    p.I[1] = chargerImage("Images/Players/White/face_gauche.bmp");
    p.I[2] = chargerImage("Images/Players/White/face_droite.bmp");
    p.I[3] = chargerImage("Images/Players/White/dos_statique.bmp");
    p.I[4] = chargerImage("Images/Players/White/dos_gauche.bmp");
    p.I[5] = chargerImage("Images/Players/White/dos_droite.bmp");
    p.I[6] = chargerImage("Images/Players/White/droite_statique.bmp");
    p.I[7] = chargerImage("Images/Players/White/droite_gauche.bmp");
    p.I[8] = chargerImage("Images/Players/White/droite_droite.bmp");
    p.I[9] = chargerImage("Images/Players/White/gauche_statique.bmp");
    p.I[10] = chargerImage("Images/Players/White/gauche_gauche.bmp");
    p.I[11] = chargerImage("Images/Players/White/gauche_droite.bmp");
    p.I[12] = chargerImage("Images/Players/White/Gravestone.bmp");

    int i;
    for (i=0; i<13; i++)
    {
        fixerCouleurDeTransparence(p.I[i], 0, 255, 0);
    }
    return p;
}

player_t gold_player()
{
    player_t p = {clr: {240, 180, 40}, nb_bombe:1};
    p.I[0] = chargerImage("Images/Players/Gold/face_statique.bmp");
    p.I[1] = chargerImage("Images/Players/Gold/face_gauche.bmp");
    p.I[2] = chargerImage("Images/Players/Gold/face_droite.bmp");
    p.I[3] = chargerImage("Images/Players/Gold/dos_statique.bmp");
    p.I[4] = chargerImage("Images/Players/Gold/dos_gauche.bmp");
    p.I[5] = chargerImage("Images/Players/Gold/dos_droite.bmp");
    p.I[6] = chargerImage("Images/Players/Gold/droite_statique.bmp");
    p.I[7] = chargerImage("Images/Players/Gold/droite_gauche.bmp");
    p.I[8] = chargerImage("Images/Players/Gold/droite_droite.bmp");
    p.I[9] = chargerImage("Images/Players/Gold/gauche_statique.bmp");
    p.I[10] = chargerImage("Images/Players/Gold/gauche_gauche.bmp");
    p.I[11] = chargerImage("Images/Players/Gold/gauche_droite.bmp");
    p.I[12] = chargerImage("Images/Players/Gold/Gravestone.bmp");

    int i;
    for (i=0; i<13; i++)
    {
        fixerCouleurDeTransparence(p.I[i], 0, 255, 0);
    }
    return p;
}


/************************************************************* Choix du skin du Terrain *************************************************************/

void chargement_Terrain()
{
    if ( terrain.type == 1 )
    {
        terrain.I[50] = chargerImage("Images/Tiles/Terrains/1/t-left.bmp");
        terrain.I[51] = chargerImage("Images/Tiles/Terrains/1/t-right.bmp");
        terrain.I[52] = chargerImage("Images/Tiles/Terrains/1/left.bmp");
        terrain.I[53] = chargerImage("Images/Tiles/Terrains/1/right.bmp");
        terrain.I[54] = chargerImage("Images/Tiles/Terrains/1/b-left.bmp");
        terrain.I[55] = chargerImage("Images/Tiles/Terrains/1/b-right.bmp");
        terrain.I[56] = chargerImage("Images/Tiles/Terrains/1/middle.bmp");
        terrain.I[57] = chargerImage("Images/Tiles/Terrains/1/cassable.bmp");
        terrain.I[58] = chargerImage("Images/Tiles/Terrains/1/font.bmp");
        terrain.I[59] = chargerImage("Images/Tiles/Terrains/1/t-font.bmp");
        terrain.I[60] = chargerImage("Images/Tiles/Terrains/1/incassable.bmp");
        terrain.I[61] = chargerImage("Images/Tiles/Terrains/1/middle.bmp");
    }
    else if ( terrain.type == 2 )
    {
        terrain.I[50] = chargerImage("Images/Tiles/Terrains/2/t-left.bmp");
        terrain.I[51] = chargerImage("Images/Tiles/Terrains/2/t-right.bmp");
        terrain.I[52] = chargerImage("Images/Tiles/Terrains/2/left.bmp");
        terrain.I[53] = chargerImage("Images/Tiles/Terrains/2/right.bmp");
        terrain.I[54] = chargerImage("Images/Tiles/Terrains/2/b-left.bmp");
        terrain.I[55] = chargerImage("Images/Tiles/Terrains/2/b-right.bmp");
        terrain.I[56] = chargerImage("Images/Tiles/Terrains/2/top.bmp");
        terrain.I[57] = chargerImage("Images/Tiles/Terrains/2/cassable.bmp");
        terrain.I[58] = chargerImage("Images/Tiles/Terrains/2/font.bmp");
        terrain.I[59] = chargerImage("Images/Tiles/Terrains/2/font.bmp");
        terrain.I[60] = chargerImage("Images/Tiles/Terrains/2/incassable.bmp");
        terrain.I[61] = chargerImage("Images/Tiles/Terrains/2/bottom.bmp");
    }

    terrain.I[63] = chargerImage("Images/Tiles/Bombs/Center/1.bmp");
    terrain.I[64] = chargerImage("Images/Tiles/Bombs/Center/2.bmp");
    terrain.I[65] = chargerImage("Images/Tiles/Bombs/Center/3.bmp");
    terrain.I[66] = chargerImage("Images/Tiles/Bombs/Center/4.bmp");
    terrain.I[67] = chargerImage("Images/Tiles/Bombs/Center/5.bmp");

    terrain.I[68] = chargerImage("Images/Tiles/Bombs/Vertical/1.bmp");
    terrain.I[69] = chargerImage("Images/Tiles/Bombs/Vertical/2.bmp");
    terrain.I[70] = chargerImage("Images/Tiles/Bombs/Vertical/3.bmp");
    terrain.I[71] = chargerImage("Images/Tiles/Bombs/Vertical/4.bmp");
    terrain.I[72] = chargerImage("Images/Tiles/Bombs/Vertical/5.bmp");

    terrain.I[73] = chargerImage("Images/Tiles/Bombs/Horizontal/1.bmp");
    terrain.I[74] = chargerImage("Images/Tiles/Bombs/Horizontal/2.bmp");
    terrain.I[75] = chargerImage("Images/Tiles/Bombs/Horizontal/3.bmp");
    terrain.I[76] = chargerImage("Images/Tiles/Bombs/Horizontal/4.bmp");
    terrain.I[77] = chargerImage("Images/Tiles/Bombs/Horizontal/5.bmp");

    terrain.I[78] = chargerImage("Images/Tiles/Bombs/Top/1.bmp");
    terrain.I[79] = chargerImage("Images/Tiles/Bombs/Top/2.bmp");
    terrain.I[80] = chargerImage("Images/Tiles/Bombs/Top/3.bmp");
    terrain.I[81] = chargerImage("Images/Tiles/Bombs/Top/4.bmp");
    terrain.I[82] = chargerImage("Images/Tiles/Bombs/Top/5.bmp");

    terrain.I[83] = chargerImage("Images/Tiles/Bombs/Bottom/1.bmp");
    terrain.I[84] = chargerImage("Images/Tiles/Bombs/Bottom/2.bmp");
    terrain.I[85] = chargerImage("Images/Tiles/Bombs/Bottom/3.bmp");
    terrain.I[86] = chargerImage("Images/Tiles/Bombs/Bottom/4.bmp");
    terrain.I[87] = chargerImage("Images/Tiles/Bombs/Bottom/5.bmp");

    terrain.I[88] = chargerImage("Images/Tiles/Bombs/Left/1.bmp");
    terrain.I[89] = chargerImage("Images/Tiles/Bombs/Left/2.bmp");
    terrain.I[90] = chargerImage("Images/Tiles/Bombs/Left/3.bmp");
    terrain.I[91] = chargerImage("Images/Tiles/Bombs/Left/4.bmp");
    terrain.I[92] = chargerImage("Images/Tiles/Bombs/Left/5.bmp");

    terrain.I[93] = chargerImage("Images/Tiles/Bombs/Right/1.bmp");
    terrain.I[94] = chargerImage("Images/Tiles/Bombs/Right/2.bmp");
    terrain.I[95] = chargerImage("Images/Tiles/Bombs/Right/3.bmp");
    terrain.I[96] = chargerImage("Images/Tiles/Bombs/Right/4.bmp");
    terrain.I[97] = chargerImage("Images/Tiles/Bombs/Right/5.bmp");

    terrain.I[98] = chargerImage("Images/Tiles/Bombs/Cassable/1.bmp");
    terrain.I[99] = chargerImage("Images/Tiles/Bombs/Cassable/2.bmp");
    terrain.I[100] = chargerImage("Images/Tiles/Bombs/Cassable/3.bmp");
    terrain.I[101] = chargerImage("Images/Tiles/Bombs/Cassable/4.bmp");
    terrain.I[102] = chargerImage("Images/Tiles/Bombs/Cassable/5.bmp");
    terrain.I[103] = chargerImage("Images/Tiles/Bombs/Cassable/6.bmp");
    terrain.I[104] = chargerImage("Images/Tiles/Bombs/Cassable/7.bmp");
    terrain.I[105] = chargerImage("Images/Tiles/Bombs/Cassable/8.bmp");
    terrain.I[106] = chargerImage("Images/Tiles/Bombs/Cassable/9.bmp");

    terrain.I[107] = chargerImage("Images/Tiles/Bombs/1.bmp");
    terrain.I[108] = chargerImage("Images/Tiles/Bombs/2.bmp");
    terrain.I[109] = chargerImage("Images/Tiles/Bombs/3.bmp");

    terrain.I[110] = chargerImage("Images/Players/Gravestone.bmp");

    terrain.I[111] = chargerImage("Images/Tiles/bonus_p.bmp");
    terrain.I[112] = chargerImage("Images/Tiles/bonus_+.bmp");
    terrain.I[113] = chargerImage("Images/Tiles/bonus_speed.bmp");

    int i;
    for (i=63; i<=113; i++)
    {
        fixerCouleurDeTransparence(terrain.I[i], 0, 255, 0);
    }

    tp[0] = 1;
    tp[1] = 2;
    tp[2] = 3;
    tp[3] = 3.1;
    tp[4] = 3.2;
    tp[5] = 3.3;
    tp[6] = 3.4;
    tp[7] = 3.5;
    tp[8] = 3.6;
    tp[9] = 3.7;
    tp[10] = 3.8;
    tp[11] = 3.9;

}
