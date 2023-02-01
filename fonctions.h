/*!
    \file    fonctions.h
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    1 décembre 2022
    \brief   TD Pointeurs
*/

/* Interface de l'objet */
#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_

/* Inclusion des entetes de librairies */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Déclaration des prototypes de fonctions */
/*!
    \fn      void viderBuffer(void)
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    1 décembre 2022
    \brief   Vide le buffer
*/
void viderBuffer(void);

/*!
    \fn      void saisieEntier(void)
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    1 décembre 2022
    \brief   Saisie d'un entier
*/
int saisieEntier(void);

/*!
    \fn      void affichageTab(int* int_tab, int int_taille)
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    1 décembre 2022
    \brief   Afficher les éléments d'un tableau
*/
void affichageTab(int* int_tab, int int_taille);

/*!
    \fn      void triInsertion(int *tab, int int_taille)
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    1 décembre 2022
    \brief   Tri par insertion
*/
void triInsertion(int* int_tab, int int_taille);

/*!
    \fn      int* copierSousTableau(int* int_src, int int_debut, int int_fin)
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    1 décembre 2022
    \brief   Fonction permettant de copier dans un tableau dest les valeurs de src en allant de l'indice début à l'indice fin
*/
int* copierSousTableau(int* int_src, int int_debut, int int_fin);

/*!
    \fn      void fusion(int* int_tab1, int int_taille1, int* int_tab2, int int_taille2, int* int_tabRes)
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    1 décembre 2022
    \brief   Fonction permettant de fusionner deux tableaux triés de façon croissante en un seul tableau trié aussi de façon croissante
*/
void fusion(int* int_tab1, int int_taille1, int* int_tab2, int int_taille2, int* int_tabRes);

/*!
    \fn      void triFusion(int* int_tab, int int_taille)
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    1 décembre 2022
    \brief   Fonction permettant de trier un tableau par la méthode du tri fusion
*/
void triFusion(int* int_tab, int int_taille);

#endif