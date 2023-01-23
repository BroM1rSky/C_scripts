#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionsPropies.h"
#define MAXCADENA 50
#define MAXOFERTA 9
#define MAXOBJECTE 10
#include <stdbool.h>


typedef struct{

   char nom [MAXCADENA];
   float preu;


}OFERTA;



typedef struct{

   char nombre[MAXCADENA];
   char artista[MAXCADENA];
   float precioSalida;
   int qttOfertes;
   bool tancada;
   OFERTA vOfertes[MAXOFERTA];

}OBJECTE;

bool existeixArtista(char artisteAux[MAXCADENA], OBJECTE o1[MAXOBJECTE], int qttObjectes);
bool existeixArticle(char artisteAux[MAXCADENA], OBJECTE o1[MAXOBJECTE], int qttObjectes);
bool existeixNomOferta(char nomOfertaAux[MAXCADENA], OBJECTE o1[MAXOBJECTE],int posArtis, int qttObjectes);
void IntrdoirOferta (OBJECTE o1 [MAXOBJECTE], int qttObjectes);
void LListarMillorsOfertes(OBJECTE o1[MAXOBJECTE],int qttObjectes);
void Sortir(OBJECTE o1[MAXOBJECTE], int qttObjectes);
void MostraOferta(OBJECTE o1[MAXOBJECTE], int qttObjectes);
int existeixPosArticle(char articleAux[MAXCADENA], OBJECTE o1[MAXOBJECTE], int qttObjectes);
int existeixPosArtiste(char artisteAux[MAXCADENA], OBJECTE o1[MAXOBJECTE], int qttObjectes);
void LlistarTotesSubastes(OBJECTE o1[MAXOBJECTE], int qttObjectes);
void LlistarSubastesTancades(OBJECTE o1[MAXOBJECTE], int qttObjectes);
void LlistarSubastes (OBJECTE o1[MAXOBJECTE], int qttObjectes);
void InserirObjecte(OBJECTE o1[MAXOBJECTE], int *qttObjectes);
void demanarOpcio(int *opcio);
void entrarCadena(char cad[],int qtt);

int main()
{

   int opcio=0;
   OBJECTE o1[MAXOBJECTE] = {{"Gorra","Elvis",200,3,false,{{"David Porti",230},{"Jaume Fado",235},{"Xavi Garcia",240}}},{"Jaqueta","Alejandro Sanz",1200,3,false,{{"Dyma Brom",1250},{"Denys",1350},{"Marta Mata",1480}}},{"Casc","Marc Marquez",240,3,false,{{"Andei Shevchenko",260},{"Kel",280},{"Moppi",300}}},{"Jaqueta","Will Smith",24,0,true},{"Cabra","Donny Ien",240,0,false}};
    int qttObjectes=5;



     do{
    demanarOpcio(&opcio);
    system ("cls");


    switch(opcio)
    {
        case 1: InserirObjecte(o1,&qttObjectes);break;
        case 2: LlistarSubastesTancades(o1,qttObjectes);break;
        case 3: LlistarSubastes(o1,qttObjectes);break;
        case 4: IntrdoirOferta(o1, qttObjectes);break;
        case 5: MostraOferta(o1,qttObjectes);break;
        case 6: Sortir(o1,qttObjectes);break;

    }

    getch();
    system ("cls");



    }while(opcio!=6);

    return 0;
}

void IntrdoirOferta (OBJECTE o1 [MAXOBJECTE], int qttObjectes)
{
    int posArtis;
    char nomOfertaAux[MAXCADENA];
    char articleAux[MAXCADENA];
    char artisteAux[MAXCADENA];
    bool trobat,trobat2;

    LlistarSubastes(o1,qttObjectes);
    printf("\n\n******INTRODUIR OFERTA*****\n\n");

    printf("Introdueix el nom de l'article al que vols posar una oferta: ");
    entrarCadena(articleAux,MAXCADENA);
    trobat = existeixArticle(articleAux,o1,qttObjectes);
    printf("Introdueix el nom del artiste: ");
    entrarCadena(artisteAux,MAXCADENA);
    trobat2 = existeixArtista(artisteAux,o1,qttObjectes);
    posArtis = existeixPosArtiste(artisteAux,o1,qttObjectes);

    if(trobat==false || trobat2==false){
        printf("\n\nL'article introduit o el artiste no existeix!");
    }
    else{
        printf("\nIntrodueix el teu nom: ");
        entrarCadena(nomOfertaAux,MAXCADENA);

        trobat = existeixNomOferta(nomOfertaAux,o1,posArtis,qttObjectes);

        if(trobat==true){
            printf("\n\nNo pots inserir mes d'una oferta amb el mateix nom!");
        }

        else {

            strcpy(o1[posArtis].vOfertes[o1[posArtis].qttOfertes].nom,nomOfertaAux);

            printf("\nIntrodueix el preu d'oferta: ");

            if(o1[posArtis].qttOfertes == 0){

            o1[posArtis].vOfertes[o1[posArtis].qttOfertes].preu = demanarNumEntreRang(o1[posArtis].precioSalida,9999);
            (o1[posArtis].qttOfertes)++;

            }

            else{

            o1[posArtis].vOfertes[o1[posArtis].qttOfertes].preu = demanarNumEntreRang(o1[posArtis].vOfertes[o1[posArtis].qttOfertes-1].preu,9999);
            (o1[posArtis].qttOfertes)++;

            }

            if(o1[posArtis].qttOfertes == MAXOFERTA)
            {
                o1[posArtis].tancada = true;
            }
            printf("\n\nL'oferta s'ha introduit correctament!");
        }


    }

}

bool existeixNomOferta(char nomOfertaAux[MAXCADENA], OBJECTE o1[MAXOBJECTE],int posArtis, int qttObjectes)
{
    int i=0;
    bool trobat3 = false;

    while(i<qttObjectes && trobat3==false)
    {
        if(strcmpi(o1[posArtis].vOfertes[i-1].nom,nomOfertaAux)==0)
        {
            trobat3 = true;
        }
        i++;
    }

    return trobat3;

}



void Sortir(OBJECTE o1[MAXOBJECTE], int qttObjectes)
{
    int i;
    float suma=0;

    printf("****RESUM****\n\n");


    LlistarSubastesTancades(o1,qttObjectes);
    printf("\n\n");


    LlistarSubastes(o1,qttObjectes);
    printf("\n\nTOTAL RECEPTAT: ");


       for(i=0;i<qttObjectes;i++)
       {
        suma = suma + o1[i].vOfertes[o1[i].qttOfertes-1].preu;
       }
       printf("%.2f",suma);

    printf("\n\nGRACIES PER UTILITZAR EL SISTEMA!");
}
void MostraOferta(OBJECTE o1[MAXOBJECTE], int qttObjectes)
{
    char articleAux[MAXCADENA];
    char artisteAux[MAXCADENA];
    bool trobat,trobat2;
    int i,posArtis;


    printf("***ARTICLES EN SUBHASTA****\n\n");
    LlistarTotesSubastes(o1,qttObjectes);

    printf("\n\nIndica l'objecte del qual vols veure totes les ofertes que s'han fet: ");
    entrarCadena(articleAux,MAXCADENA);
    trobat = existeixArticle(articleAux,o1,qttObjectes);
    printf("Indica l'artista: ");
    entrarCadena(artisteAux,MAXCADENA);
    trobat2 = existeixArtista(artisteAux,o1,qttObjectes);
    posArtis = existeixPosArtiste(artisteAux,o1,qttObjectes);

    if(trobat == false || trobat2 == false){
        printf("\nL'article o l'artiste seleccionat no existeixen!");
    }
    else{

    for(i=o1[posArtis].qttOfertes;i>=0;i--)
    //for(b=0;b<o1[posArtis].qttOfertes;b++)
     {

        if(o1[posArtis].vOfertes[i].preu !=0)
                    {printf("\n%.2f\t%s",o1[posArtis].vOfertes[i].preu,o1[posArtis].vOfertes[i].nom);}

        else if(o1[posArtis].qttOfertes == 0)
                    {printf("\n\nNo n'hi han ofertes d'aquest objecte.");}
     }

    }
}


int existeixPosArticle(char articleAux[MAXCADENA], OBJECTE o1[MAXOBJECTE], int qttObjectes)
{

    int i=0,posArt;

    while(i<qttObjectes)
    {
        if(strcmpi(o1[i].nombre,articleAux)==0)
        {
            posArt = i;
        }
        i++;
    }

    return posArt;



}

int existeixPosArtiste(char artisteAux[MAXCADENA], OBJECTE o1[MAXOBJECTE], int qttObjectes)
{

    int i=0,posArtis;

    while(i<qttObjectes)
    {
        if(strcmpi(o1[i].artista,artisteAux)==0)
        {

            posArtis = i;
        }
        i++;
    }

    return posArtis;



}

void LlistarTotesSubastes(OBJECTE o1[MAXOBJECTE], int qttObjectes)
{

    int i=0;
    int b=0;


       for(i=0;i<qttObjectes;i++)
       {
         printf("%s (%s)\n",o1[i].nombre,o1[i].artista);

       }

}
void LlistarSubastesTancades(OBJECTE o1[MAXOBJECTE], int qttObjectes)
{
    int i=0;
    int b=0;
    float stop;

  printf("*****ATRICLES EN SUBHASTA TANCADA********\n\n");

   for(i=0;i<qttObjectes;i++)
       {
           if(o1[i].tancada==true){
                printf("%s (%s)  Preu Sortida: %.2f --> ",o1[i].nombre,o1[i].artista,o1[i].precioSalida);

                if(o1[i].qttOfertes != 0){
                printf("Millor oferta (%s %.2f)",o1[i].vOfertes[o1[i].qttOfertes-1].nom,o1[i].vOfertes[o1[i].qttOfertes-1].preu);}

               else if(o1[i].qttOfertes == 0){printf("SENSE OFERTA");}
                printf("\n-------------------------\n");
           }

       }


}

void LlistarSubastes (OBJECTE o1[MAXOBJECTE], int qttObjectes)
{

    int i=0;
    float stop;

  printf("*****ATRICLES EN SUBHASTA ********\n\n");

       for(i=0;i<qttObjectes;i++)
       {
           if(o1[i].tancada==false){
                printf("%s (%s)  Preu Sortida: %.2f --> ",o1[i].nombre,o1[i].artista,o1[i].precioSalida);

                if(o1[i].qttOfertes != 0){
                printf("Millor oferta (%s %.2f)",o1[i].vOfertes[o1[i].qttOfertes-1].nom,o1[i].vOfertes[o1[i].qttOfertes-1].preu);}

               else if(o1[i].qttOfertes == 0){printf("SENSE OFERTA");}
                printf("\n-------------------------\n");
           }

       }

}

void InserirObjecte(OBJECTE o1[MAXOBJECTE], int *qttObjectes)
{
    char articleAux[MAXCADENA];
    char artisteAux[MAXCADENA];
    bool trobat,trobat2;

    printf("*******INSERIR ATRICLE**********\n\n\n");
    printf("Introdueix el nom de l'article: ");
    entrarCadena(articleAux,MAXCADENA);

    trobat = existeixArticle(articleAux,o1,*qttObjectes);
    printf("\nIntrodueix el nom del artista: ");
    entrarCadena(artisteAux,MAXCADENA);

    trobat2 = existeixArtista(artisteAux,o1,*qttObjectes);


    if(trobat==true && trobat2 == true)printf("Aquest objecte ja pertany a aquest artista! Indica un altre nom!");

    else{

        strcpy(o1[*qttObjectes].nombre,articleAux);
        strcpy(o1[*qttObjectes].artista,artisteAux);
        printf("\nIntroduiex el preu de sortida d'atricle: ");
        o1[*qttObjectes].precioSalida = demanarNumEntreRang(0,2000);


        printf("\n\nL'Atricle s'ha Inserit correctament!");

        (*qttObjectes)++;


    }

}


bool existeixArtista(char artisteAux[MAXCADENA], OBJECTE o1[MAXOBJECTE], int qttObjectes)
{
    int i=0;
    bool trobat = false;

    while(i<qttObjectes && trobat==false)
    {
        if(strcmpi(o1[i].artista,artisteAux)==0)
        {
            trobat = true;
        }
        i++;
    }

    return trobat;

}
bool existeixArticle(char articleAux[MAXCADENA], OBJECTE o1[MAXOBJECTE], int qttObjectes)
{
    int i=0;
    bool trobat = false;

    while(i<qttObjectes && trobat==false)
    {
        if(strcmpi(o1[i].nombre,articleAux)==0)
        {
            trobat = true;
        }
        i++;
    }

    return trobat;

}


void demanarOpcio(int *opcio)
{
   printf("***SUBASTES***\n\n");
   printf("1.-Introdueix Objecte\n");
   printf("2.-Objectes amb subhasta tancada\n");
   printf("3.-Objectes en subhasta\n");
   printf("4.-Oferta\n");
   printf("5.-Mostrar Ofertes d'un Objecte determinat\n");
   printf("6.-Sortir.\n\n");

    printf("Escull una opcio: ");

    *opcio=demanarNumEntreRang(0,15);
}



void entrarCadena(char cad[],int qtt)
{
    fflush(stdin);
    fgets(cad,qtt,stdin);
    if(cad[strlen(cad)-1]=='\n') cad[strlen(cad)-1]='\0';
}
