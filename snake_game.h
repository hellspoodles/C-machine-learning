#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/random.h>

#ifndef __SNAKE_GAME_
#define __SNAKE_GAME_

typedef struct __boardState{
    int width;
    int height;
    int **player;
    int **playerPrev;
    int **enemy;
    int **enemyPrev;
    int **food;
    int playerHeadX;
    int playerHeadY;
    int enemies;
    int *enemyHeadX;
    int *enemyHeadY;
    int foodX;
    int foodY;
}boardState;

int getGameState(int **player, int **playerPrev, int **enemy, int **enemyPrev, int **food);

#endif