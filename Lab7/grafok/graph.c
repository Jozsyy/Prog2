//
// Created by Jozsi on 11/3/2021.
//

#include "graph.h"

///
void u_adjacency_matrix(const char *name){
    FILE *f=fopen(name,"rt");
    if(!f){
        printf("Cannot open %s",name);
        return;
    }
    int n,m,**a;
    fscanf(f,"%i%i",&n,&m);
    a=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;++i){
        a[i]=(int*)calloc(n,sizeof(int));
    }

}