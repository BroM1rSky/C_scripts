#include <stdio.h>
#include <stdlib.h>
#include "FuncionsPropies.h"

int main()
{ char selec;
  int selecPc, vida=5, puntsUs=0, puntsPc=0, vidaPc=5,contJ=0;



    do{


        srand(time(NULL));

        pintaEnergiaPunts(vida,puntsUs,puntsPc,vidaPc);
        DemanarTiradaUsu(&selec);
        DemanarTiradaPc(&selecPc);
        PintaJugada(&contJ,selec,selecPc);
        EvaluarJugada(&selec, &selecPc, &puntsUs,&puntsPc, &vida, &vidaPc);


    system("pause");
    system("cls");

    }while(vida !=0 && vidaPc !=0);

    resultat(vida,vidaPc,puntsUs);






    return 0;
}

void pintaEnergiaPunts(int vida, int puntsUs,int puntsPc, int vidaPc)
{ int i;
    printf("***********BENVINGUT AL STONE - PAPER - CUTTER REVOLUTION 2021*******************\n\n");
    printf("ENERGIA DELS JUGADORS: \n");
    printf("USUARI: ");
     for(i=0;i<vida;i++){
     printf("*");}

    printf("  VIDA: %d   PUNTS: %d\n",vida,puntsUs);
    printf("PC: ");
     for(i=0;i<vidaPc;i++){
     printf("*");}
    printf("  VIDA: %d   PUNTS: %d\n\n",vidaPc,puntsPc);


}



void DemanarTiradaUsu(char *selec)
{
    printf("Escull Stone, Paper o Cutter (s,p,c): ");
    fflush(stdin);
    scanf("%c",&*selec);
}

void DemanarTiradaPc (int *selecPc)
{
    *selecPc= rand()%3 + 1;
}

void ConversorUs (char selec)
{
     //USUARI
    if(selec == 's') printf("Stone");
    else if (selec == 'p') printf("Paper");
    else if (selec == 'c') printf("Cutter");
}

void ConversorPc ( int selecPc)
{
    //PC

    if (selecPc == 1) printf("Stone\n\n");
    else if (selecPc == 2) printf("Paper\n\n");
    else printf("Cutter\n\n");
}




void PintaJugada(int *contJ ,char selec, int selecPc)
{
    (*contJ)++;

    printf("JUGADA: %d\n\n",*contJ);
    printf("JUGADOR: ");
    ConversorUs(selec);
    printf("\nPC: ");
    ConversorPc(selecPc);

}




void EvaluarJugada(char *selec, int *selecPc,int *puntsUs,int *puntsPc, int *vida,int *vidaPc)
{


    //Guanyar
    if (*selec == 's' && *selecPc == 3)
    {
        printf("\n\nHas guanyat!\n\n");
        *puntsUs = *puntsUs +2;
        *vidaPc = *vidaPc -1;
    }
    else if(*selec == 'p' && *selecPc == 1)
    {
        printf("\n\nHas guanyat!\n\n");
        *puntsUs = *puntsUs +2;
        *vidaPc = *vidaPc -1;
    }
    else if (*selec == 'c' && *selecPc == 2)
    {
        printf("\n\nHas guanyat!\n\n");
       *puntsUs = *puntsUs +2;
       *vidaPc = *vidaPc -1;
    }


    //empatar
    else if (*selec == 's' && *selecPc==1)
    {
        printf("Empat\n\n");
        *puntsUs = *puntsUs +1;
        *puntsPc = *puntsPc +1;
    }
    else if (*selec == 'p' && *selecPc ==2)
    {
        printf("Empat\n\n");
        *puntsUs = *puntsUs +1;
        *puntsPc = *puntsPc +1;

    }
    else if (*selec == 'c' && *selecPc ==3)
    {
        printf("Empat\n\n");
        *puntsUs = *puntsUs +1;
        *puntsPc = *puntsPc +1;

    }

    //perdre
    else if (*selec == 'c' && *selecPc == 1)
    {
        printf("\n\nHas perdut!\n\n");
       *puntsPc = *puntsPc +2;
       *vida = *vida -1;
    }
    else if(*selec == 's' && *selecPc == 2)
    {
        printf("\n\nHas perdut!\n\n");
       *puntsPc = *puntsPc +2;
       *vida = *vida -1;
    }
    else if (*selec == 'p' && *selecPc == 3)
    {
        printf("\n\nHas perdut!\n\n");
       *puntsPc = *puntsPc +2;
       *vida = *vida -1;
    }

}




void resultat(int vida, int vidaPc,int puntsUs,int puntsPc)
{
  if (vidaPc == 0)  printf("\n\n\n**************** FELICITATS!!! HAS GUANYAT AL ORDINADOR AMB %d PUNTS !!!!***********\n\n\n",puntsUs);
  else if(vida == 0) printf("\n\n\n*************JOC FUNALITZAT!********** HAS PERDUT !!!*******\n\n\n");

}

