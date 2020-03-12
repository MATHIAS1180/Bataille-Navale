
#include <stdio.h>
#include <windows.h>
int choixmenu;
int menu() {
        printf("\nBataille Navale");
        printf("1-Jouer\n");
        printf("2-Pseudo\n");
        printf("3-Scores\n");
        printf("4-Aide\n");
        printf("5-Quitter\n");
        printf("\nFaite votre choix :");
        scanf("%d", &choixmenu);
        fflush(stdin);

        if(choixmenu < 1 || choixmenu > 5){
            while(choixmenu < 1 || choixmenu > 5){
               menu();
            }
    }
    return choixmenu;
}
void aide (){
printf("---Aide---");


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
            printf("\nVous avez choisi d'afficher l'aide ");
            aide();
            break;
        case 5 :
            printf("\nVous avez choisi de quitter le jeu ");
            break;
        default :
            break;
    }
}

int main() {

    int choix = menu();

    Redirection(choix);
    return 0;

}

