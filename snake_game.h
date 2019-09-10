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

typedef enum __SNAKE_DIRECTION{
    SNAKE_DIR_UP    = 0,
    SNAKE_DIR_LEFT  = 1,
    SNAKE_DIR_RIGHT = 2,
    SNAKE_DIR_DOWN  = 3
}SNAKE_DIRECTION;

static int initalizeBoard(boardState *state, int width, int height, int enemies);

#endif