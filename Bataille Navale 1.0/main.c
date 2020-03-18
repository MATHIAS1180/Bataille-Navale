    /**
     * Author : Mathias Bourqui
     * Date : 17.03.2020
     * Description :
     * Version : 0.1
     */

    #include <stdio.h>
    #include <stdlib.h>
    #include <windows.h>
    // Permet d'afficher les accents (ou caractère spéciale ou latin)
    #pragma set_character_execution("UTF-8")

    int Menu();

    void Jeu();


    //Affiche l'aide de jeu de la batille navale
    void Aide() {
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
    // redirige vers le menu
        Menu();
    }
    //Demande de choisir un pseudo
    int pseudo() {
        char pseudo[20];
        system("cls");
        printf("------- Pseudo -------\n");
        printf("Quel est votre pseudo:");
        scanf("%s", pseudo);
        printf("Daccord %s !\n", pseudo);
        system("pause");
    // Redirige vers le menu
        Menu();
    }




    // Initialisations des variables pour les HP des différent bateaux + déclaration de la variables du nombres d'essaie
    int BLife_1 = 2;
    int BLife_2 = 3;
    int BLife_3 = 3;
    int BLife_4 = 4;
    int BLife_5 = 5;
    int Nb_Essaie;

    // Ajout ds grilles pour elancer une partie + des bateaux et des tableaux afficher en jeu
    // les 0 sont vides et les 1 sont les bateaux
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

    int Grille_A[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

        int B_1[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

        int B_1_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

        int B_2[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

        int B_2_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

        int B_3[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 1, 1, 1, 0, 0}};

        int B_3_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 1, 1, 1, 0, 0}};

        int B_4[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

        int B_4_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

        int B_5[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

        int B_5_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    // Variables de positions
    int A;
    int B;

    // Fonctions indiquant quelle bateaux est touchées ou, permetre de definir un tir qui est coulé ou touché/coulé
    void Tirer() {
        if (B_5[B - 1][A - 1] == 1) {
            Grille_A[B - 1][A - 1] = 1;
            B_5[B - 1][A - 1] = 0;
            BLife_5 = BLife_5 - 1;
            Nb_Essaie = Nb_Essaie + 1;
        } else {
            if (B_4[B - 1][A - 1] == 1) {
                Grille_A[B - 1][A - 1] = 1;
                B_4[B - 1][A - 1] = 0;
                Nb_Essaie = Nb_Essaie + 1;
                BLife_4 = BLife_4 - 1;
            } else {
                if (B_3[B - 1][A - 1] == 1) {
                    Grille_A[B - 1][A - 1] = 1;
                    B_3[B - 1][A - 1] = 0;
                    Nb_Essaie = Nb_Essaie + 1;
                    BLife_3 = BLife_3 - 1;
                } else {
                    if (B_2[B - 1][A - 1] == 1) {
                        Grille_A[B - 1][A - 1] = 1;
                        B_2[B - 1][A - 1] = 0;
                        BLife_2 = BLife_2 - 1;
                        Nb_Essaie = Nb_Essaie + 1;
                    } else {
                        if (B_1[B - 1][A - 1] == 1) {
                            Grille_A[B - 1][A - 1] = 1;
                            B_1[B - 1][A - 1] = 0;
                            BLife_1 = BLife_1 - 1;
                            Nb_Essaie = Nb_Essaie + 1;
                        } else {
                            if (Grille_A[B - 1][A - 1] == 1) {
                                //Si (déjà) touché : rien faire
                            } else {
                                if (Grille_A[B - 1][A - 1] == 2) {
                                    //Si (déjà tiré) : ne rien faire
                                } else {
                                    Grille_A[B - 1][A - 1] = 2;
                                    Nb_Essaie = Nb_Essaie + 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    // Redirige vers le jeu
        Jeu();
    }

    int Scores(){
        int Score;
        Score = 10 / Nb_Essaie *10;
        return Score;
    }


    // Remet la grille a neuf en utilisant les tableaux models + Réinitialisation des variables
    void ResetGame() {
        for (int o = 0; o < 11; o++) {
            Grille_A[o][o] = Restart[o][o];
            for (int p = 1; p < 10; p++) {
                Grille_A[o + p][o] = Restart[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                Grille_A[o][o + l] = Restart[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            B_1[o][o] = B_1_Model[o][o];
            for (int p = 1; p < 10; p++) {
                B_1[o + p][o] = B_1_Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                B_1[o][o + l] = B_1_Model[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            B_2[o][o] = B_2_Model[o][o];
            for (int p = 1; p < 10; p++) {
                B_2[o + p][o] = B_2_Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                B_2[o][o + l] = B_2_Model[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            B_3[o][o] = B_3_Model[o][o];
            for (int p = 1; p < 10; p++) {
                B_3[o + p][o] = B_3_Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                B_3[o][o + l] = B_3_Model[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            B_4[o][o] = B_4_Model[o][o];
            for (int p = 1; p < 10; p++) {
                B_4[o + p][o] = B_4_Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                B_4[o][o + l] = B_4_Model[o][o + l];
            }
        }
        for (int o = 0; o < 11; o++) {
            B_5[o][o] = B_5_Model[o][o];
            for (int p = 1; p < 10; p++) {
                B_5[o + p][o] = B_5_Model[o + p][o];
            }
            for (int l = 1; l < 10; l++) {
                B_5[o][o + l] = B_5_Model[o][o + l];
            }
        }
    // Indique chaque vie des bateaux
    // Une vie est une case d'un bateaux
        Nb_Essaie = 0;
        BLife_1 = 2;
        BLife_2 = 3;
        BLife_3 = 3;
        BLife_4 = 4;
        BLife_5 = 5;
    }

    // Plateau de jeu de la batille navale
    void Jeu() {
        system("cls");
        int ContreTorpilleurNumber = 1;
        printf("----------------------------- Bataille Navale -----------------------------\n\n");
        printf("     {  1  }{  2  }{  3  }{  4  }{  5  }{  6  }{  7  }{  8  }{  9  }{ 10  }\n");
        for (char i = 1; i < 11; i++) {
            printf("\n---------------------------------------------------------------------------\n");
            if (i < 10) {
                printf("%d    ", i);
            } else {
                printf("%d   ", i);
            }
            for (char e = 1; e < 11; e++) {
                if (Grille_A[i - 1][e - 1] == 1) {
                    printf("{  X  }");
                } else {
                    if (Grille_A[i - 1][e - 1] == 2) {
                        printf("{  O  }");
                    } else {
                        printf("{     }");
                    }
                }
            }
        }
    // Indique les bateaux coulé au cours de la partie
        if (BLife_1 == 0) {
            printf("\n\nTorpilleur coulé !");
        }
        if (BLife_2 == 0) {
            printf("\n\nContre Torpilleur %d coulé !", ContreTorpilleurNumber);
            ContreTorpilleurNumber++;
        }
        if (BLife_3 == 0) {
            printf("\n\nContre Torpilleur %d coulé !", ContreTorpilleurNumber);
            ContreTorpilleurNumber++;
        }
        if (BLife_4 == 0) {
            printf("\n\nCroiseur coulé !");
        }
        if (BLife_5 == 0) {
            printf("\n\nPorte Avion coulé !");
        }
        if (BLife_1 == 0 && BLife_2 == 0 && BLife_3 == 0 && BLife_4 == 0 && BLife_5 == 0) {
            int Score = Scores();
            printf("\n\nVotre nombre de point est : %d points\n\n", Score);
            system("Pause");
            ResetGame();
            Menu();
        } else {
            printf("\n\n");
            printf("O = A l'eau\n");
            printf("X = Touché");
            printf("\n\nA = ");
            scanf("%d", &A);
            fflush(stdin);
            printf("B = ");
            scanf("%d", &B);
            fflush(stdin);
            Tirer();
        }
    }

    // Affiche le menu principal de la Bataille navale
    // Demande du choix a l'utilisateur
    int Menu() {
        int choixmenu;
        {
            system("cls");
            printf("\nBataille Navale");
            printf("\n1-Jouer\n");
            printf("2-Pseudo\n");
            printf("3-Aide\n");
            printf("4-Quitter\n");
            printf("\nFaite votre choix :");
            scanf("%d", &choixmenu);
            fflush(stdin);
    // Affiche le choix choisi par l'utilisateur
            switch (choixmenu) {
                case 1 :
                    Jeu();
                    break;
                case 2 :
                    pseudo();
                    break;
                case 3 :
                    Aide();
                    break;
                case 4 :
                    break;

            }
        }
    }

    // La fonction main affiche le menu principal + caractère latin
    int main() {
        SetConsoleOutputCP(65001);

        Menu();

        return 0;
}