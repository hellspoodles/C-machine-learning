#include "ML.h"

int main()
{
    //TODO
    int inputs = 4;
    struct node hiddenLayer_1[2];
    struct node hiddenLayer_2[2];
    struct node output;
    //initalise
    for(int i = 0; i <2 ;i++)
    {
        initalizeNode(&hiddenLayer_1[i], 4);
        printNode(hiddenLayer_1[i]);
        initalizeNode(&hiddenLayer_2[i], 4);
        printNode(hiddenLayer_2[i]);
    }
    initalizeNode(&output, 2);
    printNode(output);
    //Do a quick calc
    printf("Nodes initalized\n");
    
}