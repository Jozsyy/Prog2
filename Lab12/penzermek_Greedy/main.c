/*
 * Írj programot, amely a penzek.txt-ből beolvassa a rendelkezésünkre álló bankjegyek értékeit.
Minden bankjegyből „végtelen” darabszámú áll rendelkezésünkre. A program határozza meg, hogy
egy, a képernyőről beolvasott, értéket, hogyan lehetne a legkevesebb bankjeggyel kifizetni.
Pl: ha a penzek.txt tartalma
5
10 50 5 1 100
A beolvasott összeg: 277
Az eredmény: 2x100 1x50 2x10 1x5 2x1
 */
#include <stdio.h>
#include <stdlib.h>

///qsorthoz szukseged segedfuggveny ami megmondaj mi hogyan rendezze a tombot
int int_cmp(const void*,const void*);

int main() {
    FILE *f=fopen("penzek.txt","rt");
    if(!f){
        printf("Error! Cannot open the input file");
        return 0;
    }

    //Adatok beolvasasa
    int n,*a,osszeg;
    fscanf(f,"%i",&n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        fscanf(f,"%i",&a[i]);
    }
    fscanf(f,"%i",&osszeg);
    fclose(f);

    ///Rendezzuk a tombot csokkeno sorrendbe
    qsort(a,n,sizeof(int),int_cmp);

    printf("Rendelkezesre allo penzermek rendezes utan:\n");
    for(int i=0;i<n;++i){
        printf("%i ",a[i]);
    }
    printf("\nA %i osszeg kifizetesehez szukseges penzermek:",osszeg);

    //Greedy
    int db;
    for (int i=0;i<n && osszeg>=0;++i){
        db=0;
        if(a[i]<=osszeg) {
            db=osszeg/a[i];
            osszeg=osszeg%a[i];
            printf("%ix%i ",db,a[i]);
        }
    }
    if (osszeg!=0) {
        printf("Nem lehet kifizetni!");
    }
}

///csokkeno sorrendbe rendezzuk a tombot
int int_cmp(const void *p1,const void *p2){
    int *q1=(int*) p1;
    int *q2=(int*) p2;
    if(*q1 < *q2){ return 1;}
    else if (*q1 > *q2){ return -1;}
    return 0;
}