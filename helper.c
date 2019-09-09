#include "ML.h"


///activation
///Normalises the input to between 0 and 1 using 1/(1+e^x)
///
///@param a     input vale
///@return      normalised value.
double activation(double a)
{
    return 1/(1+exp(a));
}

///Psudorandom function
double psudoRand(double key)
{
    key = (sin(key * 5000) + cos(key * 10000) + sin (key * 6000) + cos(key * 12000)) / 4;
    return key;
}

void printNode(struct node n)
{
    printf("Node = %05.3f \n", n.value);
    for(int i =0; i < n.num_inputs; i++)
    {
        printf("%05.3f  %05.3f | delta: %05.3f\n",n.inputs[i], n.weights[i], n.bpweights[i]);
    }
}