#include "ML.h"

/*
struct node
{
    int num_inputs;
    double *inputs;
    double *weights;
    double *bpweights;
    double value;
};
*/

ML_STATUS initalizeNode(struct node *n, int inputs)
{
    inputs++;
    n->inputs    = malloc(sizeof(double) * inputs);
    if(n->inputs == NULL)
        return MLSTATUS_MALLOC_FAIL;
    n->weights   = malloc(sizeof(double) * inputs);
    if(n->weights == NULL)
        return MLSTATUS_MALLOC_FAIL;
    n->bpweights = malloc(sizeof(double) * inputs);
    if(n->bpweights == NULL)
        return MLSTATUS_MALLOC_FAIL;
    time_t temptime;
    time(&temptime);
    double key = (double) temptime;
    for(int i = 0; i < inputs; i++)
    {
        n->inputs[i] = 1;
        n->weights[i] = psudoRand(&key);     //DEBUG: Not sure correct macro name. double check
        n->bpweights[i] = 0;
    }
    //bias is set as an extra input with constant value 1;
    n->num_inputs = inputs-1;
    computeNode(n);
    return MLSTATUS_OK;
}

ML_STATUS overrideNodeParam(struct node *n, int inputs, double *weights)
{
    if(inputs != n->num_inputs)
        return MLSTATUS_INVALID_PARAMS;
    for(int i = 0; i < inputs; i++)
    {
        n->weights[i] = weights[i];
    }
    return MLSTATUS_OK;
}

ML_STATUS computeNode(struct node *n)
{
    double sum = 0;
    if(n->inputs == NULL || n->weights == NULL)
        return MLSTATUS_NODE_ERROR;
    for(int i = 0; i < n->num_inputs + 1; i++)
    {
        sum += n->inputs[i] * n->weights[i];
    }
    n->value = activation(sum / n->num_inputs);
    return MLSTATUS_OK;
}

ML_STATUS backPropogate(struct node *n, double goal)
{
    //find the error.
    //scan nodes and edit their value based on a function of the error and weight impact.
    double error =  goal - n->value;
    for(int i = 0; i < n->num_inputs + 1; i++)
    {
        n->bpweights[i] = n->inputs[i] * error;
        n->weights[i] += n->bpweights[i];
    }
    return MLSTATUS_OK;
}

ML_STATUS freeNode(struct node *n)
{
    //TODO: Return free fail error.(free is error is possible??).
    free(n->inputs);
    free(n->weights);
    free(n->bpweights);
    return MLSTATUS_OK;
}