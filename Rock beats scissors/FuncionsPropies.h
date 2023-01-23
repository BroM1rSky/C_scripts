#include <stdlib.h>
#include<stdio.h>
#ifndef FUNCIONSPROPIES_H_INCLUDED
#define FUNCIONSPROPIES_H_INCLUDED



void cantameAlgo()
{
    printf("\n LA LA LA\n ");
    printf("MI CARRO ME LO CHINGAROOOOOOOOOON");
}


int demanarNumEntreRang(int min, int max)
{
    int num;

 do
 {

    scanf("%d",&num);
 }while(num<min || num>max);

 return(num);

}
int demanarNum ()
{
    int num;
    scanf("%d", &num);

    return (num);
}

void pinntaNum(int num)
{
    printf("\nEl numero es: %d",num);
}

#endif // FUNCIONSPROPIES_H_INCLUDED
