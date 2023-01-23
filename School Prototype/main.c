#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "FuncionsPropies.h"
#define MAXCADENA 50
#define MAXCODI 6
#define MAXMODUL 3
#define MAXALUMNE 10


typedef struct{

    char nom[MAXCADENA];
    char ofici[MAXCADENA];

}PARES;

typedef struct{

    int codi;
    char nom[MAXCADENA];
    int hores;

}MODUL;

typedef struct{

    int codi;
    float nota;

}MATRICULA;


typedef struct{

    char codi[MAXCODI];
    char nom[MAXCADENA];
    char correu[MAXCADENA];
    PARES mare;
    PARES pare;
    MATRICULA vModulsCursa[MAXMODUL];
    int qttModulsCursa;

}ALUMNE;


bool existeixAlumne(char nomAux[MAXCADENA],ALUMNE a1[MAXALUMNE],int qttAlumnes);
bool existeixModul(char modulAux[MAXCADENA], MODUL m1[MAXMODUL],int *qttModuls);

int main()
{
    int opcio=0,qttAlumnes=2,qttModuls=2;

    ALUMNE a1[MAXALUMNE] = {{"AL001","Dyma Kot","br@gmail.com",{"Lesia Brom","Bancaria"},{"Vasyl Brom","Paleta"},{{2,7}},1},{"AL002","Elena Kot","El.com",{"Olga Iusva"," Artista"},{"Evgen Ius","Militar"},{{1,10}},1}};
    MODUL m1[MAXMODUL] = {{1,"Bases de dades",8},{2,"Programacio",6}};

    do{
        demanarOpcio(&opcio);

        system("cls");

            switch(opcio)
            {
                 case 1: IntroduirAlumne(a1,&qttAlumnes);break;
                 case 2: IntroduirModul(m1,&qttModuls);break;
                 case 3: LlistarAlumnes(a1,qttAlumnes);break;
                 case 4: LlistarModuls(m1,qttModuls);break;
                 case 5: MatricularAlumne(a1,m1,qttAlumnes,qttModuls);break;
                 case 6: LlistarAlumnesAmbModuls(a1,m1,qttAlumnes,qttModuls);break;
                 case 7: LlistarNotes(a1,qttAlumnes);break;
                 case 8: AvaluarAlumne(a1,qttAlumnes,m1,qttModuls);break;
                 case 9: DonarAlumneDeBaixa(a1,&qttAlumnes);break;
                 case 10:EliminarModul(m1,&qttModuls);break;

            }

        getch();
        system("cls");

    }while(opcio!=0);

    return 0;
}

void EliminarModul(MODUL m1[MAXMODUL],int *qttModuls)
{
    char modulAux[MAXCADENA];
    bool trobat=false;
    int posMod;

    printf("\t\t\t*******ELIMINAR UN MODUL*******\n\n\n");
    LlistarModuls(m1,*qttModuls);
    printf("\n\nSelecciona un modul per donar-ho de baixa: ");
    entrarCadena(modulAux,MAXCADENA);
    trobat=existeixModul(modulAux,m1,*qttModuls);

    if(trobat==false){printf("\n\nAQUEST MODUL NO EXISTEIX!");}

    else{

        posMod = cercarPosModul(modulAux,m1,*qttModuls);
        eliminaModul2(posMod,m1,&*qttModuls);
        printf("\n\nS'HA ELIMINAT EXITOSAMENT EL EL MODUL <<%s>>!",modulAux);

    }
}


void eliminaModul2(int posMod, MODUL m1[MAXMODUL],int *qttModuls)
{
    int i=posMod;

    while(i<(*qttModuls-1))
    {
        m1[i] = m1[i+1],
        i++;
    }
    (*qttModuls)--;


}

void DonarAlumneDeBaixa(ALUMNE a1[MAXALUMNE],int *qttAlumnes)
{
    char nomAux[MAXCADENA];
    bool trobat=false;
    int posAl;


    printf("\t\t\t*******DONAR DE BAIXA A UN ALUMNE*******\n\n\n");
    LlistarAlumnes(a1,*qttAlumnes);
    printf("\n\nSelecciona un alumne per donar-ho de baixa: ");
    entrarCadena(nomAux,MAXCADENA);
    trobat=existeixAlumne(nomAux,a1,*qttAlumnes);

    if(trobat==false){printf("\n\nAQUEST ALUMNE NO EXISTEIX!");}

    else{

        posAl = cercarPosAlumne(nomAux,a1,*qttAlumnes);

        eliminarAlumne(posAl,a1,&*qttAlumnes);
        printf("S'ha donat de baixa a l'alumne %s.",nomAux);
    }



}

void eliminarAlumne(int posAl, ALUMNE a1[MAXALUMNE],int *qttAlumnes)
{
    int i=posAl;

    while(i<(*qttAlumnes-1))
    {
        a1[i] = a1[i+1];
        i++;
    }
    (*qttAlumnes)--;
}

void AvaluarAlumne(ALUMNE a1[MAXALUMNE],int qttAlumnes,MODUL m1[MAXMODUL], int qttModuls)
{
    int i=0,posAl;
    char nomAux[MAXCADENA];
    bool trobat=false;
    printf("*****AVALUAR ALUMNE*******\n\n\n");
    LlistarAlumnesAmbModuls(a1,m1,qttAlumnes,qttModuls);

    printf("\n\nSelecciona alumne per avaluar:" );
    entrarCadena(nomAux,MAXALUMNE);
    trobat = existeixAlumne(nomAux,a1,qttAlumnes);


    if(trobat == false){printf("\n\nAQUEST ALUMNE NO EXISTEIX! INDICA UN NOM VALID!");}

    else{

        posAl = cercarPosAlumne(nomAux,a1,qttAlumnes);

        for(i=0;i<a1[posAl].qttModulsCursa;i++)
        {
            printf("\nIntrodueix la nota del alumne %s : ",a1[posAl].nom);
            a1[posAl].vModulsCursa[i].nota = demanarNumEntreRang(0,10);
        }
    }
}


void LlistarNotes(ALUMNE a1[MAXALUMNE],int qttAlumnes)
{
    int i,j;

    printf("******NOTES DELS ALUMNES******\n\n");

    for(i=0;i<qttAlumnes;i++)
    {
        printf("%s:\t%s\t",a1[i].codi,a1[i].nom);

            for(j=0;j<a1[i].qttModulsCursa;j++)
            {
                printf("%.2f\t",a1[i].vModulsCursa[j].nota);
            }
            printf("\n");
    }



}


void MatricularAlumne(ALUMNE a1[MAXALUMNE],MODUL m1[MAXMODUL],int qttAlumnes, int qttModuls)
{
    char nomAux[MAXCADENA];
    char modulAux[MAXCADENA];
    bool trobat=false;
    int posAl,posMod=-1;

    printf("\t\t\t\t\t******MATRICULAR ALUMNE******\n\n\n");
    LlistarAlumnes(a1,qttAlumnes);
    printf("\n\nQuin alumne vols matricular?: ");
    entrarCadena(nomAux,MAXCADENA);
    system("cls");
    trobat = existeixAlumne(nomAux,a1,qttAlumnes);

    if(trobat==false){printf("\n\nAQUEST ALUMNE NO EXISTEIX! INDICA UN NOM VALID!");}


    else{

        LlistarModuls(m1,qttModuls);
        printf("\n\nEscull el modul per matricular-se: ");
        posMod = demanarNumEntreRang(1,qttModuls);
        posAl = cercarPosAlumne(nomAux,a1,qttAlumnes);

        a1[posAl].vModulsCursa[a1[posAl].qttModulsCursa].codi = posMod;
        a1[posAl].vModulsCursa[a1[posAl].qttModulsCursa].nota = -1;
        (a1[posAl].qttModulsCursa)++;


    }


}

int cercarPosAlumne(char alumneAux[MAXCADENA],ALUMNE a1[MAXALUMNE],int qttAlumnes)
{
     int i=0,posAl;

    while(i<qttAlumnes)
    {
        if(strcmpi(a1[i].nom,alumneAux)==0)
        {
            posAl = i;
        }

        i++;
    }

    return posAl;
}

int cercarPosModul(char modulAux[MAXCADENA],MODUL m1[MAXALUMNE],int qttModuls)
{
     int i=0,posMod;

    while(i<qttModuls)
    {
        if(strcmpi(m1[i].nom,modulAux)==0)
        {
            posMod = i;
        }

        i++;
    }

    return posMod;
}


void LlistarAlumnesAmbModuls(ALUMNE a1[MAXALUMNE],MODUL m1[MAXMODUL],int qttAlumnes, int qttModuls)
{
    int i=0;
    int b=0;

    printf("\n*******LLISTAT DELS ALUMNES AMB MODULS (Tenim %d MODULS a la llista):********\n\n\n",qttAlumnes);

    printf("CODI\tALUMNES\t\tMODULS\tNOTA\n\n");


       for(i=0;i<qttAlumnes;i++)
       {
           printf("%s\t%s ",a1[i].codi,a1[i].nom);

           for(b=0;b<a1[i].qttModulsCursa;b++)
           {
               printf("%s",m1[a1[i].vModulsCursa[b].codi-1].nom);
               printf(":\t%.2f\t\t",a1[i].vModulsCursa[b].nota);


           }
           printf("\n");
       }
}



void LlistarModuls(MODUL m1[MAXMODUL],int qttModuls)
{
    int i=0;

    printf("******LLISTAT DELS MODULS(EN TOTAL N'HI HAN %d)******\n\n");
    printf(" CODI \tNOM\t\tHORES\n\n");
    for(i=0;i<qttModuls;i++)
    {
        printf("%d:\t%s\t%d\n",m1[i].codi,m1[i].nom,m1[i].hores);
    }
}


void IntroduirModul(MODUL m1[MAXMODUL],int *qttModuls)
{
    bool trobat=false;
    char modulAux[MAXCADENA];

    printf("****INTRODUIR MODUL****\n\n");
    printf("\nEscriu el nom del Modul: ");
    entrarCadena(modulAux,MAXCADENA);
    trobat = existeixModul(modulAux,m1,*qttModuls);

    if(trobat==true){printf("\n\nAQUEST MODUL JA EXISTEIX! INRODUEIX UN ALTRE NOM DE MODUL.");}

    else{
        strcpy(m1[*qttModuls].nom,modulAux);
        printf("\nIntrodueix la cuantitat d'hores: ");
        m1[*qttModuls].hores = demanarNumEntreRang(1,8);

        m1[*qttModuls].codi = (*qttModuls)+1;

        (*qttModuls)++;

        printf("\n\n\nEL MODUL S'HA INSERIT EXISTOSAMENT!");
    }
}

bool existeixModul(char modulAux[MAXCADENA], MODUL m1[MAXMODUL],int *qttModuls)
{
    int i=0;
    bool trobat=false;

    while(i<qttModuls && trobat == false)
    {
        if(strcmpi(m1[i].nom,modulAux)==0)
        {
            trobat = true;
        }

        i++;
    }

    return trobat;



}
void IntroduirAlumne(ALUMNE a1[MAXALUMNE],int *qttAlumnes)
{
    bool trobat;
    char nomAux[MAXCADENA];

    printf("*******INTRDOUIR ALUMNE********\n\n\n");

    printf("Escriu el nom complet del Alumne: ");
    entrarCadena(nomAux,MAXCADENA);

    trobat = existeixAlumne(nomAux,a1,*qttAlumnes);

    if(trobat == true){
        printf("\n\nAQUEST ALUMNE JA EXISTEIX! INDICA UN ALTRE NOM.");
    }

    else{

        strcpy(a1[*qttAlumnes].nom,nomAux);
        printf("\nIntrodueix el correu electronic del alumne: ");
        entrarCadena(a1[*qttAlumnes].correu,nomAux);
        printf("\nEscriu el nom del pare del Alumne: ");
        entrarCadena(a1[*qttAlumnes].pare.nom);
        printf("\nEscriu l'ofici del pare del Alumne: ");
        entrarCadena(a1[*qttAlumnes].pare.ofici);
        printf("\nEscriu el nom de la mare del Alumne: ");
        entrarCadena(a1[*qttAlumnes].mare.nom);
        printf("\nEscriu l'ofici de la mare del Alumne: ");
        entrarCadena(a1[*qttAlumnes].mare.ofici);

        sprintf(a1[*qttAlumnes].codi,"AL%.3d",*qttAlumnes+1);

        (*qttAlumnes)++;

        printf("\n\nL'ALUMNE S'HA INSERIT CORRECTAMENT!");

    }

}

bool existeixAlumne(char nomAux[MAXCADENA],ALUMNE a1[MAXALUMNE],int qttAlumnes)
{
    int i=0;
    bool trobat=false;

    while(i<qttAlumnes && trobat == false)
    {
        if(strcmpi(a1[i].nom,nomAux)==0)
        {
            trobat = true;
        }

        i++;
    }

    return trobat;
}



void LlistarAlumnes(ALUMNE a1[MAXALUMNE],int qttAlumnes)
{
    int i=0;

    printf("******LLISTAT DELS ALUMNES(EN TOTAL N'HI HAN %d)******\n\n");
    printf(" CODI    NOM\t  CORREU\t\t NOM MARE\t OFICI\t\t\t NOM PARE\t OFICI\n\n");
    for(i=0;i<qttAlumnes;i++)
    {
        printf("%s  %s\t %s\t\t%s\t%s\t\t%s\t%s\n",a1[i].codi,a1[i].nom,a1[i].correu,a1[i].mare.nom,a1[i].mare.ofici,a1[i].pare.nom,a1[i].pare.ofici);
    }

}


void demanarOpcio(int *opcio)
{
    printf("\n*******ESCOLA EDUCEM MATRICULES******\n\n");
    printf("\n1.- Inserir nou alumne: ");
    printf("\n2.- Inserir moduls");
    printf("\n3.- Llistar dades alumnes.");
    printf("\n4.- Llistar moduls:");
    printf("\n5.- Matricular alumne:");
    printf("\n6.- Llistar alumnes amb moduls:");
    printf("\n7.- Llistar les seves notes ");
    printf("\n8.- Avaluar alumne:  ");
    printf("\n9.- Donar de baixa alumne. ");
    printf("\n10.- Eliminar un modul. ");
    printf("\n0.- Sortir");

    printf("\n\nEscull una opcio: ");

    *opcio=demanarNumEntreRang(0,10);



}


void entrarCadena(char cad[],int qtt)
{
    fflush(stdin);
    fgets(cad,qtt,stdin);
    if(cad[strlen(cad)-1]=='\n') cad[strlen(cad)-1]='\0';
}
