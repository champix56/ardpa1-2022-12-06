#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14F
unsigned int degToRad(float,float*);
int main()
{
    float value=0.0F;
    unsigned int isMoreOne =degToRad(180.0F,&value);
    printf("DEMAT BREIZH!\n%.3f",value);
    return 0;
}

unsigned int degToRad(float angle,float *radValue){
    unsigned int isMoreThanOneTurn=0;
    if(angle>360.0F)isMoreThanOneTurn=1;

    *radValue=angle*(M_PI/180.0F);
    printf("Dans la fonction \t%.3f\n-----\n",*radValue);

    return isMoreThanOneTurn;
}
