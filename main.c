/*!
    \file    main.c
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    29 novembre 2022
    \brief   TD Pointeurs
*/

#include "fonctions.h"

/*!
    \fn         int main(int argc, char *argv[])
    \author     Léo Portet <portetleo@cy-tech.fr>
    \version    0.1 première version
    \date       29 novembre 2022
    \brief      Programme principal
    \param argc nombre d'arguments en entrée
    \param argv valeur d'arguments en entrée
    \return     0 si tout est OK
*/
int main(int argc, char *argv[]) {
    int *int_tab;       // Tableau de stockage des nombres saisis
    int int_taille;     // Taille du tableau

    /* Menu de sélection */
    printf("            Menu            \n\n");
    printf("1. Tri par insertion\n");
    printf("2. Tri par fusion\n");
    printf("3. Quitter\n\n");

    switch (saisieEntier()) {
        case 1:
            printf("\nVous avez choisi le tri par insertion\n\n");
            printf("Veuillez saisir la taille du tableau :\n");

            int_taille = saisieEntier();
            int_tab = malloc(int_taille * sizeof(int));
            
            if (int_tab == NULL) {
                fprintf(stderr, "Erreur d'allocation mémoire, le programme a été stoppé veuillez recommencer\n");
                exit(EXIT_FAILURE); // On quitte le programme
            }

            printf("Veuillez saisir les nombres à trier :\n");
            for (int i = 0; i < int_taille; i++) {
                int_tab[i] = saisieEntier();
            }
            printf("\n");
            
            printf("Voici le tableau avant le tri :\n");
            affichageTab(int_tab, int_taille);
            printf("\n");
            
            triInsertion(int_tab, int_taille);
            
            printf("Voici le tableau trié :\n");
            affichageTab(int_tab, int_taille);
            printf("\n");
            break;
        case 2:
            printf("\nVous avez choisi le tri par fusion\n\n");
            printf("Veuillez saisir la taille du tableau :\n");

            int_taille = saisieEntier();
            int_tab = malloc(int_taille * sizeof(int));

            if (int_tab == NULL) {
                fprintf(stderr, "Erreur d'allocation mémoire, le programme a été stoppé veuillez recommencer\n");
                exit(EXIT_FAILURE); // On quitte le programme
            }

            printf("Veuillez saisir les nombres à trier :\n");
            for (int i = 0; i < int_taille; i++) {
                int_tab[i] = saisieEntier();
            }
            printf("\n");

            printf("Voici le tableau avant le tri :\n");
            affichageTab(int_tab, int_taille);
            printf("\n");

            triFusion(int_tab, int_taille);

            printf("Voici le tableau trié :\n");
            affichageTab(int_tab, int_taille);
            printf("\n");
            break;
        case 3:
            printf("Au revoir\n");
            exit(EXIT_SUCCESS);
        default:
            fprintf(stderr, "Erreur de saisie, le programme a été stoppé veuillez recommencer\n");
            exit(EXIT_FAILURE);
    }

    return 0;
}