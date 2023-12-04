#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 10
#define COLS 10

int playerX, playerY;
int ghostX, ghostY;
int foodX, foodY;
int score;

char board[ROWS][COLS];

void initializeBoard() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = '.';
        }
    }
}

void printBoard() {
    system("cls");
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void placePlayer() {
    board[playerY][playerX] = 'P';
}

void movePlayer(char direction) {
    board[playerY][playerX] = '.'; // Efface l'ancienne position du joueur

    switch (direction) {
    case 'w':
        if (playerY > 0) playerY--;
        break;
    case 's':
        if (playerY < ROWS - 1) playerY++;
        break;
    case 'a':
        if (playerX > 0) playerX--;
        break;
    case 'd':
        if (playerX < COLS - 1) playerX++;
        break;
    }

    placePlayer(); // Place le joueur dans sa nouvelle position
}

void placeGhost() {
    board[ghostY][ghostX] = 'G';
}

void moveGhost() {
    board[ghostY][ghostX] = '.'; // Efface l'ancienne position du fantôme

    // Logique de mouvement du fantôme (peut être aléatoire pour un exemple simple)
    int direction = rand() % 4;

    switch (direction) {
    case 0:
        if (ghostY > 0) ghostY--;
        break;
    case 1:
        if (ghostY < ROWS - 1) ghostY++;
        break;
    case 2:
        if (ghostX > 0) ghostX--;
        break;
    case 3:
        if (ghostX < COLS - 1) ghostX++;
        break;
    }

    placeGhost(); // Place le fantôme dans sa nouvelle position
}

void placeFood() {
    board[foodY][foodX] = 'F';
}

void checkCollisions() {
    if (playerX == ghostX && playerY == ghostY) {
        printf("Game Over! Ton score finale est : %d\n", score);
        exit(0);
    }

    if (playerX == foodX && playerY == foodY) {
        score++;
        foodX = rand() % COLS;
        foodY = rand() % ROWS;
        placeFood();
    }
}

int main() {
    playerX = COLS / 2;
    playerY = ROWS / 2;
    ghostX = rand() % COLS;
    ghostY = rand() % ROWS;
    foodX = rand() % COLS;
    foodY = rand() % ROWS;

    initializeBoard();

    while (1) {
        printBoard();
        checkCollisions();
        movePlayer(_getch()); // Utilise les touches W-A-D-S pour le déplacement
        moveGhost();
    }

    return 0;
}