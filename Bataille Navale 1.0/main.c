
/**
    * Author : Mathias Bourqui
    * Date : 17.03.2020
    * Description :
    * Version : 0.1
    */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
// Permet d'afficher les accents (ou caractère spéciale ou latin)
#pragma set_character_execution("UTF-8")

int Menu();

int template;
int firstStart;

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

// Pour la map A
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

// Pour la map B
int BB_1[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int BB_1_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int BB_2[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int BB_2_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int BB_3[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int BB_3_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int BB_4[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int BB_4_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int BB_5[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int BB_5_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

// Pour la map C
int CB_1[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int CB_1_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int CB_2[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int CB_2_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int CB_3[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int CB_3_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int CB_4[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int CB_4_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int CB_5[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int CB_5_Model[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};


// Variables de positions
int x;
int y;

// Fonctions indiquant quelle bateaux est touchées ou, permetre de definir un tir qui est coulé ou touché/coulé
void Tirer() {
    if (template == 1) {
        if (B_1[x - 1][y - 1] == 1) {
            Grille_A[x - 1][y - 1] = 1;
            B_1[x - 1][y - 1] = 0;
            BLife_5 = BLife_5 - 1;
            Nb_Essaie = Nb_Essaie + 1;
        } else {
            if (B_4[x - 1][y - 1] == 1) {
                Grille_A[x - 1][y - 1] = 1;
                B_4[x - 1][y - 1] = 0;
                Nb_Essaie = Nb_Essaie + 1;
                BLife_4 = BLife_4 - 1;
            } else {
                if (B_3[x - 1][y - 1] == 1) {
                    Grille_A[x - 1][y - 1] = 1;
                    B_3[x - 1][y - 1] = 0;
                    Nb_Essaie = Nb_Essaie + 1;
                    BLife_3 = BLife_3 - 1;
                } else {
                    if (B_2[x - 1][y - 1] == 1) {
                        Grille_A[x - 1][y - 1] = 1;
                        B_2[x - 1][y - 1] = 0;
                        BLife_2 = BLife_2 - 1;
                        Nb_Essaie = Nb_Essaie + 1;
                    } else {
                        if (B_1[x - 1][y - 1] == 1) {
                            Grille_A[x - 1][y - 1] = 1;
                            B_1[x - 1][y - 1] = 0;
                            BLife_1 = BLife_1 - 1;
                            Nb_Essaie = Nb_Essaie + 1;
                        } else {
                            if (Grille_A[x - 1][y - 1] == 1) {
                                //Si déjà touché, ne rien faire
                            } else {
                                if (Grille_A[x - 1][y - 1] == 2) {
                                    //Si déjà tiré, ne rien faire
                                } else {
                                    Grille_A[x - 1][y - 1] = 2;
                                    Nb_Essaie = Nb_Essaie + 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        Jeu();
    } else {
        if (template == 2) {
            if (BB_5[x - 1][y - 1] == 1) {
                Grille_A[x - 1][y - 1] = 1;
                BB_5[x - 1][y - 1] = 0;
                BLife_5 = BLife_5 - 1;
                Nb_Essaie = Nb_Essaie + 1;
            } else {
                if (BB_4[x - 1][y - 1] == 1) {
                    Grille_A[x - 1][y - 1] = 1;
                    BB_4[x - 1][y - 1] = 0;
                    Nb_Essaie = Nb_Essaie + 1;
                    BLife_4 = BLife_4 - 1;
                } else {
                    if (BB_3[x - 1][y - 1] == 1) {
                        Grille_A[x - 1][y - 1] = 1;
                        BB_3[x - 1][y - 1] = 0;
                        Nb_Essaie = Nb_Essaie + 1;
                        BLife_3 = BLife_3 - 1;
                    } else {
                        if (BB_2[x - 1][y - 1] == 1) {
                            Grille_A[x - 1][y - 1] = 1;
                            BB_2[x - 1][y - 1] = 0;
                            BLife_2 = BLife_2 - 1;
                            Nb_Essaie = Nb_Essaie + 1;
                        } else {
                            if (BB_1[x - 1][y - 1] == 1) {
                                Grille_A[x - 1][y - 1] = 1;
                                BB_1[x - 1][y - 1] = 0;
                                BLife_1 = BLife_1 - 1;
                                Nb_Essaie = Nb_Essaie + 1;
                            } else {
                                if (Grille_A[x - 1][y - 1] == 1) {
                                    //Si déjà touché, ne rien faire
                                } else {
                                    if (Grille_A[x - 1][y - 1] == 2) {
                                        //Si déjà tiré, ne rien faire
                                    } else {
                                        Grille_A[x - 1][y - 1] = 2;
                                        Nb_Essaie = Nb_Essaie + 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            Jeu();
        } else {
            if (CB_5[x - 1][y - 1] == 1) {
                Grille_A[x - 1][y - 1] = 1;
                CB_5[x - 1][y - 1] = 0;
                BLife_5 = BLife_5 - 1;
                Nb_Essaie = Nb_Essaie + 1;
            } else {
                if (CB_4[x - 1][y - 1] == 1) {
                    Grille_A[x - 1][y - 1] = 1;
                    CB_4[x - 1][y - 1] = 0;
                    Nb_Essaie = Nb_Essaie + 1;
                    BLife_4 = BLife_4 - 1;
                } else {
                    if (CB_3[x - 1][y - 1] == 1) {
                        Grille_A[x - 1][y - 1] = 1;
                        CB_3[x - 1][y - 1] = 0;
                        Nb_Essaie = Nb_Essaie + 1;
                        BLife_3 = BLife_3 - 1;
                    } else {
                        if (CB_2[x - 1][y - 1] == 1) {
                            Grille_A[x - 1][y - 1] = 1;
                            CB_2[x - 1][y - 1] = 0;
                            BLife_2 = BLife_2 - 1;
                            Nb_Essaie = Nb_Essaie + 1;
                        } else {
                            if (CB_1[x - 1][y - 1] == 1) {
                                Grille_A[x - 1][y - 1] = 1;
                                CB_1[x - 1][y - 1] = 0;
                                BLife_1 = BLife_1 - 1;
                                Nb_Essaie = Nb_Essaie + 1;
                            } else {
                                if (Grille_A[x - 1][y - 1] == 1) {
                                    //Si déjà touché, ne rien faire
                                } else {
                                    if (Grille_A[x - 1][y - 1] == 2) {
                                        //Si déjà tiré, ne rien faire
                                    } else {
                                        Grille_A[x - 1][y - 1] = 2;
                                        Nb_Essaie = Nb_Essaie + 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            Jeu();
        }
    }
}

int Scores() {
    int Score;
    system("cls");
    printf("------------------Score------------------\n");
    printf("\nPseudo\nVous avez %d de scores.\n\n", Score);
    system("pause");
    // Redirige vers le menu
    Menu();
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

    for (int o = 0; o < 11; o++) {
        BB_1[o][o] = BB_1_Model[o][o];
        for (int p = 1; p < 10; p++) {
            BB_1[o + p][o] = BB_1_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            BB_1[o][o + l] = BB_1_Model[o][o + l];
        }
    }
    for (int o = 0; o < 11; o++) {
        BB_2[o][o] = BB_2_Model[o][o];
        for (int p = 1; p < 10; p++) {
            BB_2[o + p][o] = BB_2_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            BB_2[o][o + l] = BB_2_Model[o][o + l];
        }
    }
    for (int o = 0; o < 11; o++) {
        BB_3[o][o] = BB_3_Model[o][o];
        for (int p = 1; p < 10; p++) {
            BB_3[o + p][o] = BB_3_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            BB_3[o][o + l] = BB_3_Model[o][o + l];
        }
    }
    for (int o = 0; o < 11; o++) {
        BB_4[o][o] = BB_4_Model[o][o];
        for (int p = 1; p < 10; p++) {
            BB_4[o + p][o] = BB_4_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            BB_4[o][o + l] = BB_4_Model[o][o + l];
        }
    }
    for (int o = 0; o < 11; o++) {
        BB_5[o][o] = BB_5_Model[o][o];
        for (int p = 1; p < 10; p++) {
            BB_5[o + p][o] = BB_5_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            BB_5[o][o + l] = BB_5_Model[o][o + l];
        }
    }

    for (int o = 0; o < 11; o++) {
        CB_1[o][o] = CB_1_Model[o][o];
        for (int p = 1; p < 10; p++) {
            CB_1[o + p][o] = CB_1_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            CB_1[o][o + l] = CB_1_Model[o][o + l];
        }
    }
    for (int o = 0; o < 11; o++) {
        CB_2[o][o] = CB_2_Model[o][o];
        for (int p = 1; p < 10; p++) {
            CB_2[o + p][o] = CB_2_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            CB_2[o][o + l] = CB_2_Model[o][o + l];
        }
    }
    for (int o = 0; o < 11; o++) {
        CB_3[o][o] = CB_3_Model[o][o];
        for (int p = 1; p < 10; p++) {
            CB_3[o + p][o] = CB_3_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            CB_3[o][o + l] = CB_3_Model[o][o + l];
        }
    }
    for (int o = 0; o < 11; o++) {
        CB_4[o][o] = CB_4_Model[o][o];
        for (int p = 1; p < 10; p++) {
            CB_4[o + p][o] = CB_4_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            CB_4[o][o + l] = CB_4_Model[o][o + l];
        }
    }
    for (int o = 0; o < 11; o++) {
        CB_5[o][o] = CB_5_Model[o][o];
        for (int p = 1; p < 10; p++) {
            CB_5[o + p][o] = CB_5_Model[o + p][o];
        }
        for (int l = 1; l < 10; l++) {
            CB_5[o][o + l] = CB_5_Model[o][o + l];
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
    if (firstStart = 1) {
        srand((unsigned) time(NULL));
        template = 1 + rand() % 3;
        firstStart = 0;
    }
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
        scanf("%d", &x);
        fflush(stdin);
        printf("B = ");
        scanf("%d", &y);
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
        printf("3-Score\n");
        printf("4-Aide\n");
        printf("5-Quitter\n");
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
                Scores();
                break;
            case 4 :
                Aide();
                break;
            case 5 :
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