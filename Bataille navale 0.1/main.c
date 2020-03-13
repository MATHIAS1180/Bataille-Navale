
#include <stdio.h>
#include <windows.h>

#pragma set_character_execution("UTF-8")
int choixmenu;


void jeu() {

}


void aide() {
    int retour;
    do {
        system("cls");
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
        scanf("%d",&retour);
    } while (retour != 1);

}


int menu() {
    system("cls");
    printf("\nBataille Navale");
    printf("\n1-Jouer\n");
    printf("2-Pseudo\n");
    printf("3-Scores\n");
    printf("4-Aide\n");
    printf("5-Quitter\n");
    printf("\nFaite votre choix :");
    scanf("%d", &choixmenu);
    fflush(stdin);
    switch (choixmenu) {
        case 1 :
            break;
        case 2 :
            break;
        case 3 :
            break;
        case 4 :
            aide();
            break;
        case 5 :
            break;
        default :
            system("cls");
            break;
    }
}

int main() {

    SetConsoleOutputCP(65001);
    do {
        menu();
    } while (choixmenu != 5);

    return 0;

}

