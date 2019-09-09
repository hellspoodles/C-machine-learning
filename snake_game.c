#include "snake_game.h"


///////////////////////////////////////////////////////////////
////////////////////  Private  ////////////////////////////////
///////////////////////////////////////////////////////////////


static int parseBoardState(boardState *state)
{
    int enemyCounter = 0;
    for (int x = 0; x < state->width; x++)
    {
        for (int y = 0; y < state->height; y++)
        {
            //get player head
            if (state->playerPrev[x][y] == 0 && state->player[x][y] > 0)
            {
                state->playerHeadX = x;
                state->playerHeadY = y;
            }
            if (state->enemyPrev[x][y] == 0 && state->enemy[x][y] > 0)
            {
                state->enemyHeadX[enemyCounter] = x;
                state->enemyHeadY[enemyCounter] = y;
                enemyCounter++;
            }
            if (state->food[x][y] == 1)
            {
                state->foodX = x;
                state->foodY = y;
            }
        }
    }
}

static int initalizeBoard(boardState *state, int width, int height, int enemies)
{
    //allocate all arrays.
    //allocates width * height * 5 * 2 bytes.
    //for a 10x10 board that is. 100,000 bytes or 100 kb
    state->player       = (int **)malloc(sizeof(int) * width);
    state->playerPrev   = (int **)malloc(sizeof(int) * width);
    state->enemy        = (int **)malloc(sizeof(int) * width);
    state->enemyPrev    = (int **)malloc(sizeof(int) * width);
    state->food         = (int **)malloc(sizeof(int) * width);
    for (int i = 0; i < width; i++)
    {
        state->player[i]       = (int *)malloc(sizeof(int) * height);
        state->playerPrev[i]   = (int *)malloc(sizeof(int) * height);
        state->enemy[i]        = (int *)malloc(sizeof(int) * height);
        state->enemyPrev[i]    = (int *)malloc(sizeof(int) * height);
        state->food[i]         = (int *)malloc(sizeof(int) * height);
        //zero initalize
        for (int j = 0; j < height; j++)
        {
            state->player[i][j]       = 0;
            state->playerPrev[i][j]   = 0;
            state->enemy[i][j]        = 0;
            state->enemyPrev[i][j]    = 0;
            state->food[i][j]         = 0;
        }
    }
    //place player, enemies, and food. then update table
    //start at length like... 1.
    state->player[random() % width][random() % height] = 1;
    for(int i = 0; i < enemies; i++)
    {
        state->enemy[random() % width][random() % height] = 1;
    }
    state->enemies = enemies;
    state->enemyHeadX = malloc(sizeof(int) * enemies);
    state->enemyHeadY = malloc(sizeof(int) * enemies);
    state->food[random() % width][random() % height] = 1;

}