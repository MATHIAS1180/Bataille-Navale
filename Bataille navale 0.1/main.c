
#include <stdio.h>
#include <windows.h>

#pragma set_character_execution("UTF-8")
int choixmenu, choix_q, choix;

int menu() {
    printf("\nBataille Navale");
    printf("\n1-Jouer\n");
    printf("2-Pseudo\n");
    printf("3-Scores\n");
    printf("4-Aide\n");
    printf("5-Quitter\n");
    printf("\nFaite votre choix :");
    scanf("%d", &choixmenu);
    fflush(stdin);

    if (choixmenu < 1 || choixmenu > 5) {
        while (choixmenu < 1 || choixmenu > 5) {
            printf("Choisisez un nombre éxcistant");
            menu();
        }
    }
    return choixmenu;
}

void quitter() {
    printf("Etes vous sur de vouloir quitter?\n");
    printf("1-Oui\n");
    printf("2-Non\n");
    printf("\nFaite votre choix :");
    scanf("%d", &choix_q);
    fflush(stdin);
    if (choix_q == 2) {
        menu();
    } else {
        if (choix_q == 1) {

        } else {
            printf("\n\nMauvais choix\n\n");
            quitter();
        }
    }
}

void jeu() {

}

void aide() {
    printf("\n------Aide------\n");
    printf("\n"
           "Chaque joueur possède:\n"
           "\n"
           "Un bateau de 5 cases\n"
           "Un bateau de 4 cases\n"
           "Deux bateau de 3 cases\n"
           "Un bateaux de 2 cases\n");
    printf("\n"
           "Chacun son tour, chaque joueur tire un obus sur une case de la carte adverse.\n"

           "\nUn bateau est touché quand un obus atterrit sur une des cases du bateau.\n"

           "\nUn bateau est coulé quand toutes ses cases sont touchées\n"

           "Une partie se termine quand un joueur coule tout les bateaux adverses.\n");


}

void Redirection(choix) {
    switch (choix) {
        case 1 :
            printf("\nVous avez choisi de lancer une partie ");
            break;
        case 2 :
            printf("\nVous avez choisi de choisir votre pseudo ");
            break;
        case 3 :
            printf("\nVous avez choisi d'afficher votre scores ");
            break;
        case 4 :
            printf("\nVous avez choisi d'afficher l'aide\n ");
            aide();
            break;
        case 5 :
            printf("\nVous avez choisi de quitter le jeu ");
            quitter();
            break;
        default :
            break;
    }
}

int main() {

    SetConsoleOutputCP(65001);

    menu();

    Redirection();
    return 0;

}

