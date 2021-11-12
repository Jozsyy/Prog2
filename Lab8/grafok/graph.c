//
// Created by Jozsi on 11/10/2021.
//

#include "graph.h"


void init(int *n, int *m){
    FILE *f=freopen("input.txt","rt",stdin);
    scanf("%i%i",&(*n),&(*m));     ///vagy &(*n)=n
    dad=(int*)calloc((*n+1),sizeof(int));
    color=(int*)calloc((*n+1),sizeof(int));
    adj_m=(int**)calloc((*n+1),sizeof(int*));
    for(int i=0;i<=*n;++i){
        adj_m[i]=(int*)calloc((*n+1),sizeof (int));
    }
}

void bool_matrix(int m){
    int el1,el2;
    for(int i=0;i<m;++i){
        scanf("%i%i",&el1,&el2);
        adj_m[el1][el2]=1;
        adj_m[el2][el1]=1;
    }
}

void print_bool(int **adj_m,int n){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%i ",adj_m[i][j]);
        }
        printf("\n");
    }
}

void print_array(int *a,int n){
    for(int i=1;i<=n;++i){
        printf("%i ",a[i]);
    }
    printf("\n");
}

void melysegi_bejaras(){
    printf("\nApa tomb:\n");
    print_array(dad,n);
    printf("\nSzin tomb:\n");
    print_array(color,n);
    printf("\nMelysegi bejaras:");
    int k=0;
    for(int i=1;i<=n;++i) {
        if (color[i] == 0) {
            ++k;
            melysegi_menet(i);
        }
    }
    printf("\nAz osszefuggo komponensek szama: %i\n",k);
}

void melysegi_menet(int i){
    int j;
    color[i]=1;
    printf("%i->",i);
    for(j=1;j<=n;++j){
        if(adj_m[i][j]==1 && color[j]==0){
            dad[j]=i;
            melysegi_menet(j);
        }
    }
    color[i]=2;
}

