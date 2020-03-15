
#include <stdio.h>
#include <windows.h>

#pragma set_character_execution("UTF-8")


int Boat1Life = 2;
int Boat2Life = 3;
int Boat3Life = 3;
int Boat4Life = 4;
int Boat5Life = 5;
int Try;

int Restart[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Gride[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat1[10][10] = {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat1Model[10][10] = {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat2[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}};

int Boat2Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}};

int Boat3[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}};

int Boat3Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}};

int Boat4[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat4Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat5[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int Boat5Model[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};


//Demande de choisir un pseudo
int pseudo() {
    char pseudo[20];
    system("cls");
    printf("------- Pseudo -------\n");
    printf("Quel est votre pseudo:");
    scanf("%s", pseudo);
    printf("Daccord %s !\n", pseudo);
    system("pause");
}

void Scores() {
    int scores;
    system("cls");
    printf("-----Scores----- :\n");
}

//Affiche la grille de jeu.
void jeu() {
    int InterfaceDeJeu();
    int tirer;
    system("cls");
    printf("------------ Bataille Navale -----------\n\n");
    printf("     { 1 }  { 2 }  { 3 }  { 4 }  { 5 }  { 6 }  { 7 }  { 8 }  { 9 } { 1 0 } \n");
    for (char i = 'A'; i < 'K'; i++) {
        printf("\n------------------------------------------------------------------------------\n");
        printf("%c    ", i);
        printf("{ }    ");
        for (char e = 0; e < 5; e++) {
            printf("{ }    { }    ");
        }
    }
    printf("\n\n");
    printf(" B = Bateau\n O = Dans l'eau\n X = Touché\n Z = Touché coulé");
    printf("\nChoisisez ou tirer :");
    scanf("%d", tirer);

}


//Affiche l'aide de jeu
void aide() {
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
    printf("\n");
    system("pause");


    int menu() {

        int choixmenu;
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
                jeu();
                break;
            case 2 :
                pseudo();
                break;
            case 3 :
                Scores();
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

    void ResetGame() {
        for (int o = 0; o < 11; o++) {
            Gride[o][o] = Restart[o][o];
            for (int p = 1; p < 10; p++) {
                Gride[o + p][o] = Restart[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                Gride[o][o + l] = Restart[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            Boat1[o][o] = Boat1Model[o][o];
            for (int p = 1; p < 10; p++) {
                Boat1[o + p][o] = Boat1Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                Boat1[o][o + l] = Boat1Model[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            Boat2[o][o] = Boat2Model[o][o];
            for (int p = 1; p < 10; p++) {
                Boat2[o + p][o] = Boat2Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                Boat2[o][o + l] = Boat2Model[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            Boat3[o][o] = Boat3Model[o][o];
            for (int p = 1; p < 10; p++) {
                Boat3[o + p][o] = Boat3Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                Boat3[o][o + l] = Boat3Model[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            Boat4[o][o] = Boat4Model[o][o];
            for (int p = 1; p < 10; p++) {
                Boat4[o + p][o] = Boat4Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                Boat4[o][o + l] = Boat4Model[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            Boat5[o][o] = Boat5Model[o][o];
            for (int p = 1; p < 10; p++) {
                Boat5[o + p][o] = Boat5Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                Boat5[o][o + l] = Boat5Model[o][o + l];
            }
        }
        Try = 0;
        Boat1Life = 2;
        Boat2Life = 3;
        Boat3Life = 3;
        Boat4Life = 4;
        Boat5Life = 5;
    }

    int x, y;

    void InterfaceDeJeu() {
        system("cls");
        int ContreTorpilleurNumber = 1;
        printf("--- Bataille Navale ---\n\n");
        printf("     |  1  ||  2  ||  3  ||  4  ||  5  ||  6  ||  7  ||  8  ||  9  || 10  |\n");
        for (char i = 1; i < 11; i++) {
            printf("\n---------------------------------------------------------------------------\n");
            if (i < 10) {
                printf("%d    ", i);
            } else {
                printf("%d   ", i);
            }
            for (char e = 1; e < 11; e++) {
                if (Gride[i - 1][e - 1] == 1) {
                    printf("|  O  |");
                } else {
                    if (Gride[i - 1][e - 1] == 2) {
                        printf("|  X  |");
                    } else {
                        printf("|  ?  |");
                    }
                }
            }
        }
        if (Boat1Life == 0) {
            printf("\n\nTorpilleur coulé !");
        }
        if (Boat2Life == 0) {
            printf("\n\nContre Torpilleur %d coulé !", ContreTorpilleurNumber);
            ContreTorpilleurNumber++;
        }
        if (Boat3Life == 0) {
            printf("\n\nContre Torpilleur %d coulé !", ContreTorpilleurNumber);
            ContreTorpilleurNumber++;
        }
        if (Boat4Life == 0) {
            printf("\n\nCroiseur coulé !");
        }
        if (Boat5Life == 0) {
            printf("\n\nPorte Avion coulé !");
        }
        if (Boat1Life == 0 && Boat2Life == 0 && Boat3Life == 0 && Boat4Life == 0 && Boat5Life == 0) {
            int Score = Score();
            printf("\n\nVotre score est de %d points\n\n", Score);
            system("Pause");
            ResetGame();
            menu();
        } else {
            printf("\n\n? = Inconnu\n");
            printf("X = A l'eau\n");
            printf("O = Touché");
            printf("\n\nX = ");
            scanf("%d", &y);
            fflush(stdin);
            printf("Y = ");
            scanf("%d", &x);
            fflush(stdin);
            Tirer();
        }
    }


    void Tirer() {
        if (Boat5[x - 1][y - 1] == 1) {
            Gride[x - 1][y - 1] = 1;
            Boat5[x - 1][y - 1] = 0;
            Boat5Life = Boat5Life - 1;
            Try = Try + 1;
        } else {
            if (Boat4[x - 1][y - 1] == 1) {
                Gride[x - 1][y - 1] = 1;
                Boat4[x - 1][y - 1] = 0;
                Try = Try + 1;
                Boat4Life = Boat4Life - 1;
            } else {
                if (Boat3[x - 1][y - 1] == 1) {
                    Gride[x - 1][y - 1] = 1;
                    Boat3[x - 1][y - 1] = 0;
                    Try = Try + 1;
                    Boat3Life = Boat3Life - 1;
                } else {
                    if (Boat2[x - 1][y - 1] == 1) {
                        Gride[x - 1][y - 1] = 1;
                        Boat2[x - 1][y - 1] = 0;
                        Boat2Life = Boat2Life - 1;
                        Try = Try + 1;
                    } else {
                        if (Boat1[x - 1][y - 1] == 1) {
                            Gride[x - 1][y - 1] = 1;
                            Boat1[x - 1][y - 1] = 0;
                            Boat1Life = Boat1Life - 1;
                            Try = Try + 1;
                        } else {
                            if (Gride[x - 1][y - 1] == 1) {
                                //Si déjà touché, ne rien faire
                            } else {
                                if (Gride[x - 1][y - 1] == 2) {
                                    //Si déjà tiré, ne rien faire
                                } else {
                                    Gride[x - 1][y - 1] = 2;
                                    Try = Try + 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        InterfaceDeJeu();
    }


}

//Affiche le menu et redirige vers la redirection de notre choix.


int main() {

    SetConsoleOutputCP(65001);


    return 0;

}


