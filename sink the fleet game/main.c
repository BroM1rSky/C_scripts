#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FuncionsPropies.h"
int main()
{
/*-----------------------------------VARIABLES-------------------------------------*/

    int missils=6,punts = 0,proa,centre1,centre2,popa,posicio;

    bool proaTocat,centre1Tocat,centre2Tocat,popaTocat;

/*----------------------------------------------------------------------------------*/

    srand(time(NULL));

    generarPosicions(&proa,&centre1,&centre2,&popa);  /*Generem Posicions*/




    do{

        pintaEstatJoc(&missils,&punts,proaTocat, centre1Tocat, centre2Tocat,popaTocat); /* Pintem El Menu*/

        posicio=demanarPosicio(); /* Demanem un pas al usuari */

        analisiPosicio( posicio, proa, centre1, centre2, popa); /* Analitzem el pas */

        analitzarParts(posicio,proa,centre1,centre2,popa,&proaTocat, &centre1Tocat, &centre2Tocat, &popaTocat); /* Concluim resultats*/

        actualitzarMenu(&missils, &punts, posicio, proa, centre1,centre2, popa); /* actualitzem dades */


        system ("\n\npause");

        system("cls");


    }while(missils !=0 && (proaTocat== false || centre1Tocat== false || centre2Tocat== false || popaTocat==false));

    Resultat (missils);

    /*El Joc acaba si ens quedem sense missils o en cas de destruir el vaixell per complet */

    return 0;
}



void generarPosicions(int *proa,int *centre1, int *centre2, int *popa)
{

    *proa = rand()%20+1;
    *centre1= *proa+1;
    *centre2 = *proa+2;
    *popa = *proa+3;

    if (*proa>17)
    {
        *centre1 = *proa-1;
        *centre2 = *proa-2;
        *popa = *proa-3;

    }

  /* printf("MODO HACKER\n proa %d, centre1 %d, centre2 %d, popa %d \n\n",*proa,*centre1,*centre2,*popa);*/




}

void pintaEstatJoc(int *missils,int *punts,bool proaTocat, bool centre1Tocat, bool centre2Tocat, bool popaTocat)
{
    printf("**********EDUCEM BATTLE CHIPS*************\n\n");
    printf("\nMISSILS : %d",*missils);
    printf("\n\nPUNTS: %d",*punts);

    printf("\n\n----------------------------------\n");
    printf("TOCAT: %d\n",proaTocat);
    printf("TOCAT: %d\n",centre1Tocat);
    printf("TOCAT: %d\n",centre2Tocat);
    printf("TOCAT: %d\n",popaTocat);


}

int demanarPosicio()
{int posicio;

    printf("\nDigam una posicio!\n");
    posicio=demanarNumEntreRang(1,20);

    return(posicio);
}

void analisiPosicio(int posicio, int proa,int centre1, int centre2,int popa)
{
    if(posicio==proa || posicio == centre1 || posicio == centre2 || posicio == popa)
    {
        printf("\nTocat ! ! !\n ");
    }
    else
    {
        printf("\nAigua!\n");
    }
}

void analitzarParts (int posicio,int proa,int centre1, int centre2, int popa, bool *proaTocat, bool *centre1Tocat, bool *centre2Tocat, bool *popaTocat)
{
    if (posicio==proa)
    {
        *proaTocat=1;

    }
    else if (posicio==centre1)
    {
        *centre1Tocat=1;

    }
    else if (posicio==centre2)
    {
        *centre2Tocat=1;

    }
    else if (posicio==popa)
    {
        *popaTocat=1;

    }



}



void actualitzarMenu (int *missils, int *punts,int posicio,int proa, int centre1, int centre2, int popa)
{

    *missils = *missils -1;

    if(*missils >=5 && (posicio==proa || posicio == centre1 || posicio == centre2 || posicio == popa))
       {
           *punts=*punts +2;
       }
    else if (*missils >=3 && (posicio==proa || posicio == centre1 || posicio == centre2 || posicio == popa))
       {
           *punts = *punts +5;
       }




}


void Resultat (int missils)
{
    if(missils == 0)
    {
        printf("GAME OVER ! ! ! T'has quedat sense missils!\n\n\n");
    }

    else {
        printf("\n HAS GUANYAT ! ! ! EL VAIXELL S'HA DESTROSAT TOTALMENT ! ! !\n\n\n");
    }
}

