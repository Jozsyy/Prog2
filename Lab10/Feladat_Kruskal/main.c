/**
 Matrixaval adott egy varos uthal6zatanak osszefugo, elsUlyozott,
 iranyitatlan , egyszeru grafja: a csucsok a csom6pontok ,
 az elek a csom6pontok kozotti kozvetlen utak, az elek sulya pedig
 azt mutatja, hogy hany h6munkas tudja az adott utszakaszt letakaritani 1 6ra alatt.
 Szeretnenk tudni, hogy legalabb mennyi h6munkasra van szukseg osszesen ahhoz, hogy egy ejszakai h6eses utan
 (ami reggel 6-kor elallt), a 7 6ras munkakezdes utan 1 oran belul a foterrol (ami egy csucs a grAfban) a varos
 osszes csom6pontja elerheto legyen  letakaritott  uton.
Melyik tanult algoritmust lehet alkalmazni, hogyan es miert , ha O(n2) lepesben valaszt akarunk kapni, ahol
n a csom6pontok szama?


 */
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int u,v,suly;   //u,v csomopontok (varosok)   suly:hany homunkas szukseges az adott utvonal takaritasahoz
}EL;

void egyesit(int*,int,int,int);

int main() {
    FILE *f=fopen("bemenet.txt","rt");
    if(!f){
        printf("Error! Cannot open the input file");
        return 0;
    }
    int **adjM,n,m;
    fscanf(f,"%i%i",&n,&m);

    ///Helyfoglalas
    adjM=(int**)calloc((n+1),sizeof(int*));
    for(int i=1;i<=n;++i){
        adjM[i]=(int*)calloc((n+1),sizeof(int));
    }
    if(!adjM){
        printf("Error while allocating memory for matrix");
        return 0;
    }

    ///Adatok beolvasasa
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            fscanf(f,"%i",&adjM[i][j]);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%3i ",adjM[i][j]);
        }
        printf("\n");
    }

    fclose(f);

    EL *elek=(EL*)calloc((m+1),sizeof(EL));
    if(!elek){
        printf("Error while allocating memory");
        return 0;
    }

    ///Matrixban levo adatokat atrakjuk a sulyozott ellistaba
    int c=1; //szamlalo
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(adjM[i][j]!=0) {
                elek[c].u = i;
                elek[c].v = j;
                elek[c].suly = adjM[i][j];
                ++c;
            }
        }
    }


    printf("\nEllista:\n");
    for(int i=1;i<=m;++i){
        printf("%i %i %i\n",elek[i].u,elek[i].v,elek[i].suly);
    }

    ///matrix helyenek felszabaditasa
    for(int i=1;i<=n;++i){
        free(adjM[i]);
    }
    free(adjM);

    ///Rendezzuk az ellistat
    EL aux;
    for(int i=1;i<m;++i){
        for(int j=i+1;j<=m;++j){
            if(elek[i].suly>elek[j].suly){
                aux=elek[i];
                elek[i]=elek[j];
                elek[j]=aux;
            }
        }
    }

    printf("\nRendezes utan:\n");
    for(int i=1;i<=m;++i){
        printf("%i %i %i\n",elek[i].u,elek[i].v,elek[i].suly);
    }

    int *fa=(int*)malloc((n+1)*sizeof(int));
    if(!fa){
        printf("Error while allocating memory");
        return 0;
    }
    for(int i=1;i<=n;++i){
        fa[i]=i;
    }
    int egyik,masik,osszsuly=0;
    printf("...........Minimalis feszitofahoz szukseges elek-sulyokkal......\n");
    for(int i=1;i<=m;++i){
        egyik=fa[elek[i].u];
        masik=fa[elek[i].v];
        if(egyik!=masik){
            osszsuly+=elek[i].suly;
            printf("%i %i %i\n",elek[i].u,elek[i].v,elek[i].suly);
            egyesit(fa,n,egyik,masik);
        }
    }

    printf("\nOsszesen legkevesebb %i hohanyo szukseges az utak eltakaritasahoz",osszsuly);

    free(elek);
    free(fa);
    return 0;
}

void egyesit(int *fa,int n,int egyik,int masik){
    for(int i=1;i<=n;++i){
        if(fa[i]==masik){
            fa[i]=egyik;
        }
    }
}
