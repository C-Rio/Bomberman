
#include "Bomberman.h"


/* Fonction principale */


int main()
{
    creerTableau();
    fixerTaille(LARGEUR, HAUTEUR);
    tableauRedimensionnable(1);
    fixerModeBufferisation(1);
    chargement_Menu();

  /* Declaration des variables locales */
    terrain.type = 1;
    terrain.p[0] = red_player();
    terrain.p[1] = blue_player();
    player_t gagnant = red_player();
    int i;
    for (i = 0; i < 36; i++)
    {
        x[i]= 25*i - 450 ;
        y[i]= 450 - 25*i ;
    }

  /* "calcul" effectue par la fonction */
    i = menu(gagnant);
    while ( i >= 0 )
    {
        if ( i == 0 ) i = menu(gagnant);
        if ( i == 1 ) i = jeu(&gagnant);
        if ( i == 2 ) i = options(gagnant);
        if ( i == 3 ) i = controles(gagnant);
        if ( i == 5 ) i = choix_terrain(gagnant);
        if ( i == 6 ) i = choix_perso(gagnant);
    }

    return EXIT_SUCCESS;
}


/* Definition de fonctions */


/********************************************************** Menu de demarrage et options **********************************************************/


int menu(player_t p)                                                // Menu principal (dirige vers autres menus ou jeu
{
    effacerTableau();

    afficherImage(terrain.I[0], -265, y[6]);
    dessiner_rectangle(terrain.I[1], y[17], 106, 36, p.clr);
    dessiner_rectangle(terrain.I[2], y[20], 125, 36, p.clr);
    dessiner_rectangle(terrain.I[13], y[23], 152, 36, p.clr);
    dessiner_rectangle(terrain.I[17], y[32], 120, 36, p.clr);

    tamponner();

    attendreNms(250);

    int i=0;
    while(i==0)
    {

        if( lireEtatSourisClavier().sourisBoutonGauche == 1 && lireEtatSourisClavier().sourisX <= L_REC/2 && lireEtatSourisClavier().sourisX >= -L_REC/2)
        {
            if (lireEtatSourisClavier().sourisY <= y[17]+(H_REC/2) && lireEtatSourisClavier().sourisY >= y[17]-(H_REC/2))
                return 1;
            if (lireEtatSourisClavier().sourisY <= y[20]+(H_REC/2) && lireEtatSourisClavier().sourisY >= y[20]-(H_REC/2))
                return 2;
            if (lireEtatSourisClavier().sourisY <= y[23]+(H_REC/2) && lireEtatSourisClavier().sourisY >= y[23]-(H_REC/2))
                return 3;
            if (lireEtatSourisClavier().sourisY <= y[32]+(H_REC/2) && lireEtatSourisClavier().sourisY >= y[32]-(H_REC/2))
                return -1;
        }
        if (fermetureDemandee() == 1 || lireEtatSourisClavier().touchesClavier[27] == 1) return -1;
    }
    return 0;
}

int options(player_t p)                                             // Menu options (dirige vers menu chois des personnages, choix du terrain ou retour)
{
    effacerTableau();

    afficherImage(terrain.I[3], -105, y[7]);
    dessiner_rectangle(terrain.I[4], y[17], 267, 36, p.clr);
    dessiner_rectangle(terrain.I[5], y[20], 387, 36, p.clr);
    dessiner_rectangle(terrain.I[6], y[32], 120, 36, p.clr);

    tamponner();

    attendreNms(250);

    int i = 2;
    while(i==2)
    {

        if( lireEtatSourisClavier().sourisBoutonGauche == 1 && lireEtatSourisClavier().sourisX <= L_REC/2 && lireEtatSourisClavier().sourisX >= -L_REC/2)
        {
            if (lireEtatSourisClavier().sourisY <= y[17]+(H_REC/2) && lireEtatSourisClavier().sourisY >= y[17]-(H_REC/2))
            {
                return 5;
            }
            if (lireEtatSourisClavier().sourisY <= y[20]+(H_REC/2) && lireEtatSourisClavier().sourisY >= y[20]-(H_REC/2))
            {
                return 6;
            }
            if (lireEtatSourisClavier().sourisY <= y[32]+(H_REC/2) && lireEtatSourisClavier().sourisY >= y[32]-(H_REC/2)) return 0;
        }
        if (lireEtatSourisClavier().touchesClavier[27] == 1) return 0;
    }
    return 2;
}

int choix_terrain(player_t p)                                       // Choix du terrain
{
    effacerTableau();

    if (terrain.type == 1 )
    {
        choisirTypeStylo(TAILLE_TRAIS, 255, 255, 255);
        tracerRectangle (x[3] - 10, y[12] + 10, x[3] + 310, y[12] - 360);
    }
    else if (terrain.type == 2)
    {
        choisirTypeStylo(TAILLE_TRAIS, 255, 255, 255);
        tracerRectangle (x[20] - 10, y[12] + 10, x[20] + 310, y[12] - 360);
    }
    afficherImage(terrain.I[7], -342, y[6]);

    afficherImage(terrain.I[18],x[3],y[12]);
    afficherImage(terrain.I[19],x[20],y[12]);

    dessiner_rectangle(terrain.I[6], y[32], 120, 36, p.clr);

    tamponner();

    attendreNms(250);

    int i = 5;
    while ( i == 5 )
    {
        effacerTableau();

        if (lireEtatSourisClavier().sourisBoutonGauche == 1)
        {
            if (lireEtatSourisClavier().sourisY <= y[12] + 10 && lireEtatSourisClavier().sourisY >= y[12] - 310 && lireEtatSourisClavier().sourisX <= x[3] + 310 && lireEtatSourisClavier().sourisX >= x[3] - 10 )
            {
                terrain.type = 1;
            }
            else if (lireEtatSourisClavier().sourisY <= y[12] + 10 && lireEtatSourisClavier().sourisY >= y[12] - 310 && lireEtatSourisClavier().sourisX <= x[20] + 310 && lireEtatSourisClavier().sourisX >= x[20] - 10 )
            {
                terrain.type = 2;
            }
            else if (lireEtatSourisClavier().sourisX <= L_REC/2 && lireEtatSourisClavier().sourisX >= -L_REC/2 && lireEtatSourisClavier().sourisY <= y[32]+(H_REC/2) && lireEtatSourisClavier().sourisY >= y[32]-(H_REC/2)) return 2;
        }

        if (terrain.type == 1 )
        {
            choisirTypeStylo(TAILLE_TRAIS, 255, 255, 255);
            tracerRectangle (x[3] - 10, y[12] + 10, x[3] + 310, y[12] - 360);

        }
        else if (terrain.type == 2)
        {
            choisirTypeStylo(TAILLE_TRAIS, 255, 255, 255);
            tracerRectangle (x[20] - 10, y[12] + 10, x[20] + 310, y[12] - 360);
        }
        afficherImage(terrain.I[7], -342, y[6]);

        afficherImage(terrain.I[18],x[3],y[12]);
        afficherImage(terrain.I[19],x[20],y[12]);

        dessiner_rectangle(terrain.I[6], y[32], 120, 36, p.clr);

        tamponner();

        if (lireEtatSourisClavier().touchesClavier[27] == 1) return 2 ;
        if (fermetureDemandee() == 1 ) return -1;
    }
    return 5;
}

int choix_perso(player_t p)                                             // Choix des personnages
{
    Image I[5];
    I[0] = red_player().I[0];
    I[1] = blue_player().I[0];
    I[2] = black_player().I[0];
    I[3] = white_player().I[0];
    I[4] = gold_player().I[0];

    int i = 6;
    while ( i == 6 )
    {
        effacerTableau();

        if (lireEtatSourisClavier().sourisBoutonGauche == 1)
        {
            if (lireEtatSourisClavier().sourisY <= y[17] + 15 && lireEtatSourisClavier().sourisY >= y[17] - TAILLE_BLOC - 10 )
            {
                if (lireEtatSourisClavier().sourisX <= x[17] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[17] - 10 &&  terrain.p[1].clr.v != 36 ) terrain.p[0] = black_player();
                else if (lireEtatSourisClavier().sourisX <= x[22] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[22] - 10 && terrain.p[1].clr.v != 255 ) terrain.p[0] = white_player();
                else if (lireEtatSourisClavier().sourisX <= x[27] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[27] - 10 && terrain.p[1].clr.v != 180 ) terrain.p[0] = gold_player();
                else if (lireEtatSourisClavier().sourisX <= x[12] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[12] - 10 && ( terrain.p[1].clr.b != 255 || terrain.p[1].clr.v == 255 ) ) terrain.p[0] = blue_player();
                else if (lireEtatSourisClavier().sourisX <= x[7] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[7] - 10 && ( terrain.p[1].clr.r != 255 || terrain.p[1].clr.v == 255 ) ) terrain.p[0] = red_player();
            }
            else if (lireEtatSourisClavier().sourisY <= y[24] + 15 && lireEtatSourisClavier().sourisY >= y[24] - TAILLE_BLOC - 10 )
            {
                if (lireEtatSourisClavier().sourisX <= x[17] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[17] - 10 &&  terrain.p[0].clr.v != 36 ) terrain.p[1] = black_player();
                else if (lireEtatSourisClavier().sourisX <= x[22] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[22] - 10 && terrain.p[0].clr.v != 255 ) terrain.p[1] = white_player();
                else if (lireEtatSourisClavier().sourisX <= x[27] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[27] - 10 && terrain.p[0].clr.v != 180 ) terrain.p[1] = gold_player();
                else if (lireEtatSourisClavier().sourisX <= x[12] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[12] - 10 && ( terrain.p[0].clr.b != 255 || terrain.p[0].clr.v == 255 ) ) terrain.p[1] = blue_player();
                else if (lireEtatSourisClavier().sourisX <= x[7] + TAILLE_BLOC + 10 && lireEtatSourisClavier().sourisX >= x[7] - 10 && ( terrain.p[0].clr.r != 255 || terrain.p[0].clr.v == 255 ) ) terrain.p[1] = red_player();
            }
            else if (lireEtatSourisClavier().sourisX <= L_REC/2 && lireEtatSourisClavier().sourisX >= -L_REC/2 && lireEtatSourisClavier().sourisY <= y[32]+(H_REC/2) && lireEtatSourisClavier().sourisY >= y[32]-(H_REC/2)) return 2;
        }

        if (terrain.p[0].clr.v == 36 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[0].clr.r, terrain.p[0].clr.v, terrain.p[0].clr.b);
            tracerRectangle (x[17] -10, y[17] +15, x[17] + TAILLE_BLOC +10, y[17] - TAILLE_BLOC -10);
        }
        else if ( terrain.p[0].clr.v == 255 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[0].clr.r, terrain.p[0].clr.v, terrain.p[0].clr.b);
            tracerRectangle (x[22] -10, y[17] +15, x[22] + TAILLE_BLOC +10, y[17] - TAILLE_BLOC -10);
        }
        else if ( terrain.p[0].clr.v == 180 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[0].clr.r, terrain.p[0].clr.v, terrain.p[0].clr.b);
            tracerRectangle (x[27] -10, y[17] +15, x[27] + TAILLE_BLOC +10, y[17] - TAILLE_BLOC -10);
        }
        else if ( terrain.p[0].clr.b == 255 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[0].clr.r, terrain.p[0].clr.v, terrain.p[0].clr.b);
            tracerRectangle (x[12] -10, y[17] +15, x[12] + TAILLE_BLOC +10, y[17] - TAILLE_BLOC -10);
        }
        else if ( terrain.p[0].clr.r == 255 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[0].clr.r, terrain.p[0].clr.v, terrain.p[0].clr.b);
            tracerRectangle (x[7] -10, y[17] +15, x[7] + TAILLE_BLOC +10, y[17] - TAILLE_BLOC -10);
        }

        if ( terrain.p[1].clr.v == 36 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[1].clr.r, terrain.p[1].clr.v, terrain.p[1].clr.b);
            tracerRectangle (x[17] -10, y[24] +15, x[17] + TAILLE_BLOC +10, y[24] - TAILLE_BLOC -10);
        }
        else if ( terrain.p[1].clr.v == 255 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[1].clr.r, terrain.p[1].clr.v, terrain.p[1].clr.b);
            tracerRectangle (x[22] -10, y[24] +15, x[22] + TAILLE_BLOC +10, y[24] - TAILLE_BLOC -10);
        }
        else if ( terrain.p[1].clr.v == 180 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[1].clr.r, terrain.p[1].clr.v, terrain.p[1].clr.b);
            tracerRectangle (x[27] -10, y[24] +15, x[27] + TAILLE_BLOC +10, y[24] - TAILLE_BLOC -10);
        }
        else if ( terrain.p[1].clr.b == 255 && terrain.p[1].clr.r == 0 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[1].clr.r, terrain.p[1].clr.v, terrain.p[1].clr.b);
            tracerRectangle (x[12] -10, y[24] +15, x[12] + TAILLE_BLOC +10, y[24] - TAILLE_BLOC -10);
        }
        else if ( terrain.p[1].clr.r == 255 && terrain.p[1].clr.b == 0 )
        {
            choisirTypeStylo(TAILLE_TRAIS, terrain.p[1].clr.r, terrain.p[1].clr.v, terrain.p[1].clr.b);
            tracerRectangle (x[7] -10, y[24] +15, x[7] + TAILLE_BLOC +10, y[24] - TAILLE_BLOC -10);
        }

        afficherImage(terrain.I[8], -342, y[6]);
        afficherImage(terrain.I[9], x[2], y[14]);
        afficherImage(I[0], x[7], y[17]);
        afficherImage(I[1], x[12], y[17]);
        afficherImage(I[2], x[17], y[17]);
        afficherImage(I[3], x[22], y[17]);
        afficherImage(I[4], x[27], y[17]);
        afficherImage(terrain.I[10], x[2], y[21]);
        afficherImage(I[0], x[7], y[24]);
        afficherImage(I[1], x[12], y[24]);
        afficherImage(I[2], x[17], y[24]);
        afficherImage(I[3], x[22], y[24]);
        afficherImage(I[4], x[27], y[24]);
        dessiner_rectangle(terrain.I[6], y[32], 120, 36, p.clr);

        tamponner();

        if (fermetureDemandee() == 1 ) return -1;
        if (lireEtatSourisClavier().touchesClavier[27] == 1) return 2 ;
    }
    return 6;
}

int controles(player_t p)                                              // Affiche l'image des contr�les
{
    afficherImage(terrain.I[14], x[0], y[0]);
    dessiner_rectangle(terrain.I[6], y[32], 120, 36, p.clr);

    tamponner();

    attendreNms(250);
    int i = 3;
    while (i == 3)
    {
        if( (lireEtatSourisClavier().sourisBoutonGauche == 1 && lireEtatSourisClavier().sourisX <= L_REC/2 && lireEtatSourisClavier().sourisX >= -L_REC/2 && lireEtatSourisClavier().sourisY <= y[32]+H_REC/2 && lireEtatSourisClavier().sourisY >= y[32]-H_REC/2) || lireEtatSourisClavier().touchesClavier[27] == 1 ) return 0;
        if (fermetureDemandee() == 1) return -1;
    }
    return 3;
}

void dessiner_rectangle(Image I, int y, int l_image, int h_image, couleur_t c)          // Dessine rectangles pour les touches des menus
{
    int cx = L_REC/2, cy = H_REC/2, t = TAILLE_TRAIS;
    choisirTypeStylo(t, c.r, c.v, c.b);
    tracerRectangle(-cx+t,y+cy,cx-t,y-cy);
    tracerRectangle(-cx,y+cy-t,cx,y-cy+t);
    choisirTypeStylo(t, 0, 0, 0);
    choisirCouleurPinceau(0, 0, 0);
    tracerRectangle(-cx+2*t,y+cy-t,cx-2*t,y-cy+t);
    tracerRectangle(-cx+t,y+cy-2*t,cx-t,y-cy+2*t);
    afficherImage(I,-l_image/2,y+(h_image/2));
}


void init_player()                                          // Initialisation des joueurs
{
    int i;
    for ( i = 0; i < 2 ; i++ )
    {
        terrain.p[i].n = i;
        terrain.p[i].nb_bombe = 1;
        terrain.p[i].etat = 1;
        terrain.p[i].puissance = 1;
        terrain.p[i].v = 2;
    }
    terrain.p[0].c.x = -360; terrain.p[0].c.y = 360;
    terrain.p[1].c.x = 360; terrain.p[1].c.y = -360;
}


/*********************************************************************** Jeu ***********************************************************************/


int jeu(player_t * p)                                       // Fonction principale de jeu ( d�placements et m�j terrain)
{
    double temps=0, dt=0, dtdeplacement=0;
    int i = 1;
    chargement_Terrain();
    terrain = init_terrain(terrain);
    init_player();
    while (i == 1 )
    {
        dt=delta_temps();
        temps += dt;
        dtdeplacement += dt;

        terrain = affiche_terrain(terrain, temps);

        if (lireEtatSourisClavier().touchesClavier[122] == 1 ) terrain.p[0].haut = 1;
        else terrain.p[0].haut = 0;
        if (lireEtatSourisClavier().touchesClavier[115] == 1 )  terrain.p[0].bas = 1;
        else terrain.p[0].bas = 0;
        if (lireEtatSourisClavier().touchesClavier[113] == 1 ) terrain.p[0].gauche = 1;
        else terrain.p[0].gauche = 0;
        if (lireEtatSourisClavier().touchesClavier[100] == 1 ) terrain.p[0].droite = 1;
        else terrain.p[0].droite = 0;

        if (lireEtatSourisClavier().touchesClavier[273] == 1 ) terrain.p[1].haut = 1;
        else terrain.p[1].haut = 0;
        if (lireEtatSourisClavier().touchesClavier[274] == 1 )  terrain.p[1].bas = 1;
        else terrain.p[1].bas = 0;
        if (lireEtatSourisClavier().touchesClavier[276] == 1 ) terrain.p[1].gauche = 1;
        else terrain.p[1].gauche = 0;
        if (lireEtatSourisClavier().touchesClavier[275] == 1 ) terrain.p[1].droite = 1;
        else terrain.p[1].droite = 0;

        if (lireEtatSourisClavier().touchesClavier[32] == 1) poser_bombe(&(terrain.p[0]),temps);
        if (lireEtatSourisClavier().touchesClavier[305] == 1) poser_bombe(&(terrain.p[1]),temps);

        if (dtdeplacement>0.015)
            {

                if (terrain.p[0].haut ==1 && deplacement_haut(terrain.p[0])==1) terrain.p[0].c.y += terrain.p[0].v;
                if (terrain.p[0].bas ==1 && deplacement_bas(terrain.p[0])==1) terrain.p[0].c.y -= terrain.p[0].v;
                if (terrain.p[0].gauche ==1 && deplacement_gauche(terrain.p[0])==1) terrain.p[0].c.x -= terrain.p[0].v;
                if (terrain.p[0].droite ==1 && deplacement_droite(terrain.p[0])==1) terrain.p[0].c.x += terrain.p[0].v;

                if (terrain.p[1].haut ==1 && deplacement_haut(terrain.p[1])==1) terrain.p[1].c.y += terrain.p[1].v;
                if (terrain.p[1].bas ==1 && deplacement_bas(terrain.p[1])==1) terrain.p[1].c.y -= terrain.p[1].v;
                if (terrain.p[1].gauche ==1 && deplacement_gauche(terrain.p[1])==1) terrain.p[1].c.x -= terrain.p[1].v;
                if (terrain.p[1].droite ==1 && deplacement_droite(terrain.p[1])==1) terrain.p[1].c.x += terrain.p[1].v;

                dtdeplacement = 0;
            }
        int j;
        for (j=0; j<2; j++)
        {
            player(&(terrain.p[j]));
        }

        terrain = explosion(terrain,temps);

        tamponner();

        if ( terrain.p[0].etat == 0 && terrain.p[1].etat == 0 )
        {

        }
        else if ( terrain.p[0].etat == 0 )
        {
            *p = terrain.p[1];
            afficherImage(terrain.I[12],-450,450);
            afficherImage(terrain.p[0].I[12],x[10],y[16]);
            afficherImage(terrain.p[1].I[0],x[23],y[16]);
            tamponner();
            while (i ==1)
            {
                if (lireEtatSourisClavier().touchesClavier[114] == 1) return jeu(p);
                if (lireEtatSourisClavier().touchesClavier[27] == 1) return 0;
                if (fermetureDemandee() == 1) return -1;
            }
        }
        else if ( terrain.p[1].etat == 0 )
        {
            *p = terrain.p[0];
            afficherImage(terrain.I[11],-450,450);
            afficherImage(terrain.p[0].I[0],x[10],y[16]);
            afficherImage(terrain.p[1].I[12],x[23],y[16]);
            tamponner();
            while (i ==1)
            {
                if (lireEtatSourisClavier().touchesClavier[114] == 1) return jeu(p);
                if (lireEtatSourisClavier().touchesClavier[27] == 1) return 0;
                if (fermetureDemandee() == 1) return -1;
            }
        }
        if (lireEtatSourisClavier().touchesClavier[27] == 1) return 0;
        if (fermetureDemandee() == 1) return -1;
    }
    return 0;
}

terrain_t init_terrain(terrain_t t)                                             // Initialisation du terrain
{
    effacerTableau();

    int l=0,c=0;
    for (l=0;l<15;l++)
    {
        for (c=0;c<15;c++)
        {
            t.b[l][c].c.x = c*TAILLE_BLOC-LARGEUR/2;
            t.b[l][c].c.y = HAUTEUR/2-l*TAILLE_BLOC;
            t.b[l][c].type = 0;
            if (l == 0 || l == 14 || c == 0 || c == 14)
            {
                t.b[l][c].type = 1;
                if ( l == 0 && c == 0 ) afficherImage(terrain.I[50],t.b[l][c].c.x,t.b[l][c].c.y);
                else if ( l == 0 && c == 14 ) afficherImage(terrain.I[51],t.b[l][c].c.x,t.b[l][c].c.y);
                else if ( l != 0 && l != 14 && c == 0 ) afficherImage(terrain.I[52],t.b[l][c].c.x,t.b[l][c].c.y);
                else if ( l != 0 && l != 14 && c == 14 ) afficherImage(terrain.I[53],t.b[l][c].c.x,t.b[l][c].c.y);
                else if ( l == 14 && c == 0 ) afficherImage(terrain.I[54],t.b[l][c].c.x,t.b[l][c].c.y);
                else if ( l == 14 && c == 14 ) afficherImage(terrain.I[55],t.b[l][c].c.x,t.b[l][c].c.y);
                else if ( l == 0 ) afficherImage(terrain.I[56],t.b[l][c].c.x,t.b[l][c].c.y);
                else afficherImage(terrain.I[61],t.b[l][c].c.x,t.b[l][c].c.y);
            }
            if (l >= 1 && l <= 13 && c >= 1 && c <= 13 && l%2 == 0 && c%2 == 0)
            {
                afficherImage(terrain.I[60],t.b[l][c].c.x,t.b[l][c].c.y);
                t.b[l][c].type = 2;
            }
            if (t.b[l][c].type != 1 && t.b[l][c].type != 2)
            {
                afficherImage(terrain.I[57],t.b[l][c].c.x,t.b[l][c].c.y);
                t.b[l][c].type = 3;
            }
            if ( ( ( ( l==12 || l==13) && ( c==12 || c==13 ) ) || ( ( l==1 || l==2 ) && ( c==1 || c==2 ) ) ) && t.b[l][c].type!=2 )
            {
                if( l == 1 ) afficherImage(terrain.I[59],t.b[l][c].c.x,t.b[l][c].c.y);
                else afficherImage(terrain.I[58],t.b[l][c].c.x,t.b[l][c].c.y);
                t.b[l][c].type = 0;
            }
        }
    }
    return t;
}

terrain_t affiche_terrain (terrain_t t,double temps)                                    // Affichage du terrain
{
    int l,c,i;
    for (l=1;l<14;l++)
    {
        for (c=1;c<14;c++)
        {
            if ( t.b[l][c].type == 0 || t.b[l][c].type >= 4 )
            {
                if( l == 1 ) afficherImage(terrain.I[59],t.b[l][c].c.x,t.b[l][c].c.y);
                else afficherImage(terrain.I[58],t.b[l][c].c.x,t.b[l][c].c.y);
            }
            if ( t.b[l][c].type == 3 ) afficherImage(terrain.I[57],t.b[l][c].c.x,t.b[l][c].c.y);
            if ( t.b[l][c].type == 4 )
            {
                if ( t.bmb[l][c].t + tp[2] > temps )
                {
                    if ( t.bmb[l][c].t + tp[0] >= temps )
                    {
                        afficherImage(terrain.I[107],t.b[l][c].c.x,t.b[l][c].c.y);
                    }
                    if ( t.bmb[l][c].t + tp[0] < temps && t.bmb[l][c].t + tp[1] >= temps )
                    {
                        afficherImage(terrain.I[108],t.b[l][c].c.x,t.b[l][c].c.y);
                    }
                    if ( t.bmb[l][c].t + tp[1] < temps )
                    {
                        afficherImage(terrain.I[109],t.b[l][c].c.x,t.b[l][c].c.y);
                    }

                }
                else
                {
                    t.p[t.bmb[l][c].player].nb_bombe++;
                    t.b[l][c].type = 5;
                    t.b[l][c].t = terrain.bmb[l][c].t;
                    i=1;
                    while (i<=t.bmb[l][c].puissance && (t.b[l-i][c].type == 0 || t.b[l-i][c].type > 5))
                    {
                        if ( t.b[l-i][c].type == 7 || t.b[l-i][c].type == 10 || t.b[l-i][c].type == 11 )
                        {
                            t.b[l-i][c].type = 5;
                        }
                        else if ( i==t.bmb[l][c].puissance && t.b[l-i][c].type != 6 && t.b[l-i][c].type != 9 )
                        {
                            t.b[l-i][c].type = 8;
                        }
                        else
                        {
                            t.b[l-i][c].type = 6;
                        }
                        t.b[l-i][c].t = terrain.bmb[l][c].t;
                        i++;
                    }
                    if (t.b[l-i][c].type == 3 && i <= t.bmb[l][c].puissance)
                    {
                        t.b[l-i][c].type = 12;
                        t.b[l-i][c].t = terrain.bmb[l][c].t;
                    }
                    if (t.b[l-i][c].type == 4) t.bmb[l-i][c].t = temps - 2.9;
                    i=1;
                    while (i<=t.bmb[l][c].puissance && (t.b[l+i][c].type == 0 || t.b[l+i][c].type > 5))
                    {
                        if ( t.b[l+i][c].type == 7 || t.b[l+i][c].type == 10 || t.b[l+i][c].type == 11 )
                        {
                            t.b[l+i][c].type = 5;
                        }
                        else if ( i==t.bmb[l][c].puissance && t.b[l+i][c].type != 6 && t.b[l+i][c].type != 8 )
                        {
                            t.b[l+i][c].type = 9;
                        }
                        else
                        {
                            t.b[l+i][c].type = 6;
                        }
                        t.b[l+i][c].t = terrain.bmb[l][c].t;
                        i++;
                    }
                    if (t.b[l+i][c].type == 3 && i <= t.bmb[l][c].puissance)
                    {
                        t.b[l+i][c].type = 12;
                        t.b[l+i][c].t = terrain.bmb[l][c].t;
                    }
                    if (t.b[l+i][c].type == 4) t.bmb[l+i][c].t = temps - 2.9;
                    i=1;
                    while (i<=t.bmb[l][c].puissance && (t.b[l][c-i].type == 0 || t.b[l][c-i].type > 5))
                    {
                        if ( t.b[l][c-i].type == 6 || t.b[l][c-i].type == 8 || t.b[l][c-i].type == 9 )
                        {
                            t.b[l][c-i].type = 5;
                        }
                        else if ( i==t.bmb[l][c].puissance && t.b[l][c-i].type != 6 && t.b[l][c-i].type != 11 )
                        {
                            t.b[l][c-i].type = 10;
                        }
                        else
                        {
                            t.b[l][c-i].type = 7;
                        }
                        t.b[l][c-i].t = terrain.bmb[l][c].t;
                        i++;
                    }
                    if (t.b[l][c-i].type == 3 && i <= t.bmb[l][c].puissance)
                    {
                        t.b[l][c-i].type = 12;
                        t.b[l][c-i].t = terrain.bmb[l][c].t;
                    }
                    if (t.b[l][c-i].type == 4) t.bmb[l][c-i].t = temps - 2.9;
                    i=1;
                    while (i<=t.bmb[l][c].puissance && (t.b[l][c+i].type == 0 || t.b[l][c+i].type > 5))
                    {
                        if ( t.b[l][c+i].type == 6 || t.b[l][c+i].type == 8 || t.b[l][c+i].type == 9 )
                        {
                            t.b[l][c+i].type = 5;
                        }
                        else if ( i==t.bmb[l][c].puissance && t.b[l][c+i].type != 6 && t.b[l][c+i].type != 10 )
                        {
                            t.b[l][c+i].type = 11;
                        }
                        else
                        {
                            t.b[l][c+i].type = 7;
                        }
                        t.b[l][c+i].t = terrain.bmb[l][c].t;
                        i++;
                    }
                    if (t.b[l][c+i].type == 3 && i <= t.bmb[l][c].puissance)
                    {
                        t.b[l][c+i].type = 12;
                        t.b[l][c+i].t = terrain.bmb[l][c].t;
                    }
                    if (t.b[l][c+i].type == 4 && i <= t.bmb[l][c].puissance) t.bmb[l][c+i].t = temps - 2.9;
                }
            }

            if ( t.b[l][c].type == 13 )
            {
                afficherImage(t.I[111],t.b[l][c].c.x,t.b[l][c].c.y);
            }

            if ( t.b[l][c].type == 14 )
            {
                afficherImage(t.I[112],t.b[l][c].c.x,t.b[l][c].c.y);
            }

            if ( t.b[l][c].type == 15 )
            {
                afficherImage(t.I[113],t.b[l][c].c.x,t.b[l][c].c.y);
            }

        }
    }
    return t;
}

terrain_t explosion(terrain_t t,double temps)                               // Compl�te affiche_terrain pour les explosions
{
    int l,c;
    for (l=1;l<14;l++)
    {
        for (c=1;c<14;c++)
        {
            if ( t.b[l][c].type == 5 )
            {
                if ( (t.b[l][c].t + tp[2] <= temps && t.b[l][c].t + tp[3] > temps) || (t.b[l][c].t + tp[10] <= temps && t.b[l][c].t + tp[11] > temps) )
                {
                    afficherImage(terrain.I[63],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[3] <= temps && t.b[l][c].t + tp[4] > temps) || (t.b[l][c].t + tp[9] <= temps && t.b[l][c].t + tp[10] > temps) )
                {
                    afficherImage(terrain.I[64],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[4] <= temps && t.b[l][c].t + tp[5] > temps) || (t.b[l][c].t + tp[8] <= temps && t.b[l][c].t + tp[9] > temps) )
                {
                    afficherImage(terrain.I[65],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[5] <= temps && t.b[l][c].t + tp[6] > temps) || (t.b[l][c].t + tp[7] <= temps && t.b[l][c].t + tp[8] > temps) )
                {
                    afficherImage(terrain.I[66],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[6] <= temps && t.b[l][c].t + tp[7] > temps) )
                {
                    afficherImage(terrain.I[67],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if (t.b[l][c].t + tp[11] <= temps)
                {
                    t.b[l][c].type = 0;
                }
            }
            else if ( t.b[l][c].type == 6 )
            {
                if ( (t.b[l][c].t + tp[2] <= temps && t.b[l][c].t + tp[3] > temps) || (t.b[l][c].t + tp[10] <= temps && t.b[l][c].t + tp[11] > temps) )
                {
                    afficherImage(terrain.I[68],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[3] <= temps && t.b[l][c].t + tp[4] > temps) || (t.b[l][c].t + tp[9] <= temps && t.b[l][c].t + tp[10] > temps) )
                {
                    afficherImage(terrain.I[69],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[4] <= temps && t.b[l][c].t + tp[5] > temps) || (t.b[l][c].t + tp[8] <= temps && t.b[l][c].t + tp[9] > temps) )
                {
                    afficherImage(terrain.I[70],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[5] <= temps && t.b[l][c].t + tp[6] > temps) || (t.b[l][c].t + tp[7] <= temps && t.b[l][c].t + tp[8] > temps) )
                {
                    afficherImage(terrain.I[71],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[6] <= temps && t.b[l][c].t + tp[7] > temps) )
                {
                    afficherImage(terrain.I[72],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if (t.b[l][c].t + tp[11] <= temps)
                {
                    t.b[l][c].type = 0;
                }
            }
            else if ( t.b[l][c].type == 7 )
            {
                if ( (t.b[l][c].t + tp[2] <= temps && t.b[l][c].t + tp[3] > temps) || (t.b[l][c].t + tp[10] <= temps && t.b[l][c].t + tp[11] > temps) )
                {
                    afficherImage(terrain.I[73],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[3] <= temps && t.b[l][c].t + tp[4] > temps) || (t.b[l][c].t + tp[9] <= temps && t.b[l][c].t + tp[10] > temps) )
                {
                    afficherImage(terrain.I[74],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[4] <= temps && t.b[l][c].t + tp[5] > temps) || (t.b[l][c].t + tp[8] <= temps && t.b[l][c].t + tp[9] > temps) )
                {
                    afficherImage(terrain.I[75],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[5] <= temps && t.b[l][c].t + tp[6] > temps) || (t.b[l][c].t + tp[7] <= temps && t.b[l][c].t + tp[8] > temps) )
                {
                    afficherImage(terrain.I[76],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[6] <= temps && t.b[l][c].t + tp[7] > temps) )
                {
                    afficherImage(terrain.I[77],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if (t.b[l][c].t + tp[11] <= temps)
                {
                    t.b[l][c].type = 0;
                }
            }
            else if ( t.b[l][c].type == 8 )
            {
                if ( (t.b[l][c].t + tp[2] <= temps && t.b[l][c].t + tp[3] > temps) || (t.b[l][c].t + tp[10] <= temps && t.b[l][c].t + tp[11] > temps) )
                {
                    afficherImage(terrain.I[78],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[3] <= temps && t.b[l][c].t + tp[4] > temps) || (t.b[l][c].t + tp[9] <= temps && t.b[l][c].t + tp[10] > temps) )
                {
                    afficherImage(terrain.I[79],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[4] <= temps && t.b[l][c].t + tp[5] > temps) || (t.b[l][c].t + tp[8] <= temps && t.b[l][c].t + tp[9] > temps) )
                {
                    afficherImage(terrain.I[80],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[5] <= temps && t.b[l][c].t + tp[6] > temps) || (t.b[l][c].t + tp[7] <= temps && t.b[l][c].t + tp[8] > temps) )
                {
                    afficherImage(terrain.I[81],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[6] <= temps && t.b[l][c].t + tp[7] > temps) )
                {
                    afficherImage(terrain.I[82],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if (t.b[l][c].t + tp[11] <= temps)
                {
                    t.b[l][c].type = 0;
                }
            }
            else if ( t.b[l][c].type == 9 )
            {
                if ( (t.b[l][c].t + tp[2] <= temps && t.b[l][c].t + tp[3] > temps) || (t.b[l][c].t + tp[10] <= temps && t.b[l][c].t + tp[11] > temps) )
                {
                    afficherImage(terrain.I[83],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[3] <= temps && t.b[l][c].t + tp[4] > temps) || (t.b[l][c].t + tp[9] <= temps && t.b[l][c].t + tp[10] > temps) )
                {
                    afficherImage(terrain.I[84],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[4] <= temps && t.b[l][c].t + tp[5] > temps) || (t.b[l][c].t + tp[8] <= temps && t.b[l][c].t + tp[9] > temps) )
                {
                    afficherImage(terrain.I[85],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[5] <= temps && t.b[l][c].t + tp[6] > temps) || (t.b[l][c].t + tp[7] <= temps && t.b[l][c].t + tp[8] > temps) )
                {
                    afficherImage(terrain.I[86],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[6] <= temps && t.b[l][c].t + tp[7] > temps) )
                {
                    afficherImage(terrain.I[87],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if (t.b[l][c].t + tp[11] <= temps)
                {
                    t.b[l][c].type = 0;
                }
            }
            else if ( t.b[l][c].type == 10 )
            {
                if ( (t.b[l][c].t + tp[2] <= temps && t.b[l][c].t + tp[3] > temps) || (t.b[l][c].t + tp[10] <= temps && t.b[l][c].t + tp[11] > temps) )
                {
                    afficherImage(terrain.I[88],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[3] <= temps && t.b[l][c].t + tp[4] > temps) || (t.b[l][c].t + tp[9] <= temps && t.b[l][c].t + tp[10] > temps) )
                {
                    afficherImage(terrain.I[89],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[4] <= temps && t.b[l][c].t + tp[5] > temps) || (t.b[l][c].t + tp[8] <= temps && t.b[l][c].t + tp[9] > temps) )
                {
                    afficherImage(terrain.I[90],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[5] <= temps && t.b[l][c].t + tp[6] > temps) || (t.b[l][c].t + tp[7] <= temps && t.b[l][c].t + tp[8] > temps) )
                {
                    afficherImage(terrain.I[91],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[6] <= temps && t.b[l][c].t + tp[7] > temps) )
                {
                    afficherImage(terrain.I[92],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if (t.b[l][c].t + tp[11] <= temps)
                {
                    t.b[l][c].type = 0;
                }
            }
            else if ( t.b[l][c].type == 11 )
            {
                if ( (t.b[l][c].t + tp[2] <= temps && t.b[l][c].t + tp[3] > temps) || (t.b[l][c].t + tp[10] <= temps && t.b[l][c].t + tp[11] > temps) )
                {
                    afficherImage(terrain.I[93],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[3] <= temps && t.b[l][c].t + tp[4] > temps) || (t.b[l][c].t + tp[9] <= temps && t.b[l][c].t + tp[10] > temps) )
                {
                    afficherImage(terrain.I[94],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[4] <= temps && t.b[l][c].t + tp[5] > temps) || (t.b[l][c].t + tp[8] <= temps && t.b[l][c].t + tp[9] > temps) )
                {
                    afficherImage(terrain.I[95],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[5] <= temps && t.b[l][c].t + tp[6] > temps) || (t.b[l][c].t + tp[7] <= temps && t.b[l][c].t + tp[8] > temps) )
                {
                    afficherImage(terrain.I[96],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if ( (t.b[l][c].t + tp[6] <= temps && t.b[l][c].t + tp[7] > temps) )
                {
                    afficherImage(terrain.I[97],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                if (t.b[l][c].t + tp[11] <= temps)
                {
                    t.b[l][c].type = 0;
                }
            }
            else if ( t.b[l][c].type == 12 )
            {
                if ( t.b[l][c].t + tp[2] <= temps && t.b[l][c].t + tp[3] > temps )
                {
                    afficherImage(terrain.I[98],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                else if ( t.b[l][c].t + tp[3] <= temps && t.b[l][c].t + tp[4] > temps )
                {
                    afficherImage(terrain.I[99],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                else if ( t.b[l][c].t + tp[4] <= temps && t.b[l][c].t + tp[11] > temps )
                {
                    afficherImage(terrain.I[100],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                else if ( t.b[l][c].t + tp[11] <= temps && t.b[l][c].t + 4 > temps )
                {
                    afficherImage(terrain.I[101],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                else if ( t.b[l][c].t + 4 <= temps && t.b[l][c].t + 4.1 > temps )
                {
                    afficherImage(terrain.I[102],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                else if ( t.b[l][c].t + 4.1 <= temps && t.b[l][c].t + 4.2 > temps )
                {
                    afficherImage(terrain.I[103],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                else if ( t.b[l][c].t + 4.2 <= temps && t.b[l][c].t + 4.3 > temps )
                {
                    afficherImage(terrain.I[104],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                else if ( t.b[l][c].t + 4.3 <= temps && t.b[l][c].t + 4.4 > temps )
                {
                    afficherImage(terrain.I[105],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                else if ( t.b[l][c].t + 4.4 <= temps && t.b[l][c].t + 4.5 > temps )
                {
                    afficherImage(terrain.I[106],t.b[l][c].c.x,t.b[l][c].c.y);
                }
                else
                {
                    int bonus=rand()%100;
                    if (bonus <= 4) t.b[l][c].type = 13;
                    else if (bonus <= 9) t.b[l][c].type = 14;
                    else if (bonus <= 12) t.b[l][c].type = 15;
                    else t.b[l][c].type = 0;
                }
            }

        }
    }
    return t;
}

coord_t position_grille (coord_t c)                                         // Transformation de coordonn�es en case de tableau
{
    c.x = ( ( LARGEUR / 2 ) + c.x ) / TAILLE_BLOC ;
    c.y = ( ( HAUTEUR / 2 ) - c.y ) / TAILLE_BLOC ;
    return c;
}

void player(player_t *p)                                                     // Affichage et m�j du joueur
{
    int l = position_grille(p->c).y, c = position_grille(p->c).x;
    if ( terrain.b[l][c].type >= 5 && terrain.b[l][c].type < 13) p->etat = 0;
    if ( terrain.b[l][c].type == 13 )
    {
        terrain.b[l][c].type = 0;
        p->puissance++;
    }
    if ( terrain.b[l][c].type == 14 )
    {
        terrain.b[l][c].type = 0;
        p->nb_bombe++;
    }
    if ( terrain.b[l][c].type == 15 )
    {
        terrain.b[l][c].type = 0;
        if (p->v == 2)
        {
            p->v += 1;
            if ( p->c.y > terrain.b[l][c].c.y - 30 )
            {
                p->c.y += 3;
            }
            else if ( p->c.x < terrain.b[l][c].c.x + 30 )
            {
                p->c.x += 3;
            }
            if ( p->c.y < terrain.b[l][c].c.y - 30 )
            {
                p->c.y += 1;
            }
            else if ( p->c.x > terrain.b[l][c].c.x + 30 )
            {
                p->c.x -= 1;
            }
        }
        else if (p->v == 3)
        {
            p->v += 1;
            if ( p->c.y > terrain.b[l][c].c.y - 30 )
            {
                p->c.y -= 2;
            }
            else if ( p->c.x < terrain.b[l][c].c.x + 30 )
            {
                p->c.x -= 2;
            }
            if ( p->c.y < terrain.b[l][c].c.y - 30 )
            {
                p->c.y -= 1;
            }
            else if ( p->c.x > terrain.b[l][c].c.x + 30 )
            {
                p->c.x += 1;
            }
        }
    }
    if (p->etat > 0)
    {
        if (p->haut == 1 && p->bas == 0 && deplacement_haut(*p)==1)
        {
            if ( (p->c.y+HAUTEUR/2)%TAILLE_BLOC < TAILLE_BLOC/4 ) afficherImage(p->I[5],p->c.x-30,p->c.y+30);
            else if ( (p->c.y+HAUTEUR/2)%TAILLE_BLOC < TAILLE_BLOC/2 || (p->c.y+HAUTEUR/2)%TAILLE_BLOC > 3*TAILLE_BLOC/4 ) afficherImage(p->I[3],p->c.x-30,p->c.y+30);
            else afficherImage(p->I[4],p->c.x-30,p->c.y+30);
        }
        else if (p->bas == 1 && p->haut == 0 && deplacement_bas(*p)==1)
        {
            if ( (p->c.y+HAUTEUR/2)%TAILLE_BLOC < TAILLE_BLOC/4 ) afficherImage(p->I[2],p->c.x-30,p->c.y+30);
            else if ( (p->c.y+HAUTEUR/2)%TAILLE_BLOC < TAILLE_BLOC/2 || (p->c.y+HAUTEUR/2)%TAILLE_BLOC > 3*TAILLE_BLOC/4 ) afficherImage(p->I[0],p->c.x-30,p->c.y+30);
            else afficherImage(p->I[1],p->c.x-30,p->c.y+30);
        }
        else if (p->gauche == 1 && p->droite == 0 && deplacement_droite(*p)==1)
        {
            if ( (p->c.x+LARGEUR/2)%TAILLE_BLOC < TAILLE_BLOC/4 ) afficherImage(p->I[11],p->c.x-30,p->c.y+30);
            else if ( (p->c.x+LARGEUR/2)%TAILLE_BLOC < TAILLE_BLOC/2 || (p->c.x+LARGEUR/2)%TAILLE_BLOC > 3*TAILLE_BLOC/4 ) afficherImage(p->I[9],p->c.x-30,p->c.y+30);
            else afficherImage(p->I[10],p->c.x-30,p->c.y+30);
        }
        else if (p->droite == 1 && p->gauche == 0 && deplacement_gauche(*p)==1)
        {
            if ( (p->c.x+LARGEUR/2)%TAILLE_BLOC < TAILLE_BLOC/4 ) afficherImage(p->I[8],p->c.x-30,p->c.y+30);
            else if ( (p->c.x+LARGEUR/2)%TAILLE_BLOC < TAILLE_BLOC/2 || (p->c.x+LARGEUR/2)%TAILLE_BLOC > 3*TAILLE_BLOC/4 ) afficherImage(p->I[6],p->c.x-30,p->c.y+30);
            else afficherImage(p->I[7],p->c.x-30,p->c.y+30);
        }
        else afficherImage(p->I[0],p->c.x-30,p->c.y+30);
    }
    else
    {
        afficherImage(p->I[12],p->c.x-30,p->c.y+30);
    }
}

int deplacement_gauche (player_t p)                                     // Autorisation de d�placement gauche
{
    int l = position_grille(p.c).y, c = position_grille(p.c).x;
    if ( p.etat != 0 && ( terrain.b[l][c].type == 0 || terrain.b[l][c].type == 4) && ( terrain.b[l][c-1].type == 0 || ( terrain.b[l][c-1].type > 4 && terrain.b[l][c-1].type != 12 ) || terrain.b[l][c-1].c.x + 3*TAILLE_BLOC/2 < p.c.x ) && p.c.y == terrain.b[l][c].c.y - TAILLE_BLOC/2 ) return 1;
    else return 0;
}

int deplacement_droite (player_t p)                                     // Autorisation de d�placement droite
{
    int l = position_grille(p.c).y, c = position_grille(p.c).x;
    if ( p.etat != 0 && ( terrain.b[l][c].type == 0 || terrain.b[l][c].type == 4) && ( terrain.b[l][c+1].type == 0 || ( terrain.b[l][c+1].type > 4 && terrain.b[l][c+1].type != 12 ) || terrain.b[l][c+1].c.x - TAILLE_BLOC/2 > p.c.x ) && p.c.y == terrain.b[l][c].c.y - TAILLE_BLOC/2 ) return 1;
    else return 0;
}

int deplacement_haut (player_t p)                                     // Autorisation de d�placement haut
{
    int l = position_grille(p.c).y, c = position_grille(p.c).x;
    if ( p.etat != 0 && ( terrain.b[l][c].type == 0 || terrain.b[l][c].type == 4) && ( terrain.b[l-1][c].type == 0 || ( terrain.b[l-1][c].type > 4 && terrain.b[l-1][c].type != 12 ) || terrain.b[l-1][c].c.y - 3*TAILLE_BLOC/2 > p.c.y ) && p.c.x == terrain.b[l][c].c.x + TAILLE_BLOC/2 ) return 1 ;
    else return 0;
}

int deplacement_bas (player_t p)                                     // Autorisation de d�placement bas
{
    int l = position_grille(p.c).y, c = position_grille(p.c).x;
    if ( p.etat != 0 && ( terrain.b[l][c].type == 0 || terrain.b[l][c].type == 4) && ( terrain.b[l+1][c].type == 0 || ( terrain.b[l+1][c].type > 4 && terrain.b[l+1][c].type != 12 ) || terrain.b[l+1][c].c.y + TAILLE_BLOC/2 < p.c.y ) && p.c.x == terrain.b[l][c].c.x + TAILLE_BLOC/2 ) return 1;
    else return 0;
}

void poser_bombe(player_t *p,double temps)                          // Joueur pose bombe
{
    int l = position_grille(p->c).y, c = position_grille(p->c).x;
    if (terrain.b[l][c].type == 0 && p->nb_bombe > 0 && p->etat > 0)
    {
        p->nb_bombe--;
        terrain.b[l][c].type = 4;
        terrain.bmb[l][c].player = p->n;
        terrain.bmb[l][c].t = temps;
        terrain.bmb[l][c].puissance = p->puissance;
    }
}
