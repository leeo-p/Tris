/*!
    \file    fonctions.c
    \author  Léo Portet <portetleo@cy-tech.fr>
    \version 0.1 première version
    \date    01 décembre 2022
    \brief   TD Pointeurs
*/

#include "fonctions.h"

/* Vider le Buffer */
void viderBuffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Fonction de saisie d'un entier */
int saisieEntier(void) {
    int int_nb;     // Variable de stockage du nombre saisi
    int int_retour; // Variable de retour de la fonction scanf

    printf("Veuillez saisir un entier :\n");
    int_retour = scanf("%d", &int_nb);
    viderBuffer();
    if (!int_retour) {
        fprintf(stderr, "Erreur de saisie, le programme a été stoppé veuillez recommencer\n");
        exit(EXIT_FAILURE); // On quitte le programme
    }
    else {
        return int_nb; // On retourne le nombre saisi
    }
}

/* Procédure d'affichage d'un tableau*/
void affichageTab(int* int_tab, int int_taille) {
    int int_i;

    for (int_i = 0; int_i < int_taille; int_i++) {
        printf("%d ", int_tab[int_i]);
    }
}

/* Fonction de tri par insertion */
void triInsertion(int* int_tab, int int_taille) {
    int int_i; 
    int int_j;
    int int_tmp;

    for (int_i = 1; int_i < int_taille; int_i++) {
        int_tmp = int_tab[int_i];
        for (int_j = int_i; int_j > 0 && int_tab[int_j - 1] > int_tmp; int_j--) {
            int_tab[int_j] = int_tab[int_j - 1];
        }
        int_tab[int_j] = int_tmp;
    }
}

/* Fonction permettant de copier dans un tableau dest les valeurs de src en allant de l'indice début à l'indice fin */
int* copierSousTableau(int* int_src, int int_debut, int int_fin) {
    int int_i;      // Variable de boucle
    int* int_dest;  // Tableau de destination

    int_dest = malloc((int_fin - int_debut + 1) * sizeof(int)); // Allocation dynamique du tableau de destination

    for (int_i = int_debut; int_i <= int_fin; int_i++) {
        int_dest[int_i - int_debut] = int_src[int_i]; // On copie les valeurs de src dans dest
    }
    return int_dest; // On retourne le tableau de destination
}

/* Fonction permettant de fusionner deux tableaux triés de façon croissante en un seul tableau trié aussi de façon croissante */
void fusion(int* int_tab1, int int_taille1, int* int_tab2, int int_taille2, int* int_tabRes) {
    /* Variables de boucle */
    int int_i;
    int int_j;
    int int_k; 

    int_i = 0;
    int_j = 0;
    int_k = 0;

    /*Fusionner deux tableaux trié en un tableau trié*/
    while (int_i < int_taille1 && int_j < int_taille2) {
        if (int_tab1[int_i] < int_tab2[int_j]) { // Si la valeur du tableau 1 est plus petite que celle du tableau 2
            int_tabRes[int_k] = int_tab1[int_i]; // On ajoute la valeur du tableau 1 dans le tableau résultat
            int_i++;
        }
        else {                                   // Sinon
            int_tabRes[int_k] = int_tab2[int_j]; // On ajoute la valeur du tableau 2 dans le tableau résultat
            int_j++;
        }
        int_k++;
    }

    /* Copier les éléments restants de int_tab1 */
    while (int_i < int_taille1) {
        int_tabRes[int_k] = int_tab1[int_i];
        int_i++;
        int_k++;
    }

    /* Copier les éléments restants de int_tab2 */
    while (int_j < int_taille2) {
        int_tabRes[int_k] = int_tab2[int_j];
        int_j++;
        int_k++;
    }
}

/* Procédure de tri Fusion suivant les règles suivantes */
// 1. Si le tableau à trier contient 1 élément, il est déjà trié
// 2. Sinon, on divise le tableau en deux sous-tableaux de même taille
// 3. On trie récursivement les deux sous-tableaux
// 4. On fusionne les deux sous-tableaux triés en un seul tableau trié
void triFusion(int *int_tab, int int_taille) {
    int int_milieu; // Variable de stockage de la taille du premier sous-tableau
    int* int_tabG;  // Premier sous-tableau
    int* int_tabD;  // Deuxième sous-tableau

    if (int_taille == 1) {
        return;
    }
    else {
        int_milieu = int_taille / 2; // On calcule la taille du premier sous-tableau

        int_tabG = copierSousTableau(int_tab, 0, int_milieu - 1); // On copie le premier sous-tableau
        int_tabD = copierSousTableau(int_tab, int_milieu, int_taille - 1); // On copie le deuxième sous-tableau

        triFusion(int_tabG, int_milieu); // On trie récursivement le premier sous-tableau
        triFusion(int_tabD, int_taille - int_milieu); // On trie récursivement le deuxième sous-tableau

        fusion(int_tabG, int_milieu, int_tabD, int_taille - int_milieu, int_tab); // On fusionne les deux sous-tableaux triés en un seul tableau trié
    }
}