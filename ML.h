#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


struct node
{
    int num_inputs;
    double *inputs;
    double *weights;
    double *bpweights;
    double value;
    
};

typedef enum __ML_STATUS
{
    MLSTATUS_OK                     = 0x0,
    MLSTATUS_ERROR                  = 0x100,
    MLSTATUS_INVALID_PARAMS         = 0x101,
    MLSTATUS_MALLOC_FAIL            = 0x102,
    MLSTATUS_NODE_ERROR             = 0x103
}ML_STATUS;

//----------Node Functions-----------
ML_STATUS initalizeNode(struct node *n, int inputs);

ML_STATUS overrideNodeParam(struct node *n, int inputs, double *weights);

ML_STATUS computeNode(struct node *n);

ML_STATUS backPropogate(struct node *n, double goal);

ML_STATUS freeNode(struct node *n);
//----------Helper Functions---------

double activation(double a);

double psudoRand();

void printNode(struct node n);