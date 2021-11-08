//
// Created by Jozsi on 11/3/2021.
//

#include "graph.h"

///undirected adjacency_matrix
void u_adjacency_matrix(const char *name){
    FILE *f=fopen(name,"rt");
    if(!f){
        printf("Cannot open %s",name);
        return;
    }
    int n,m,**a;
    fscanf(f,"%i%i",&n,&m);
    a=(int**)calloc(n+1,sizeof(int*));
    for(int i=0;i<=n;++i){
        a[i]=(int*)calloc(n+1,sizeof(int));
    }
    int el1,el2;
    for(int i=0;i<m;++i){
        fscanf(f,"%i%i",&el1,&el2);
        a[el1][el2]=1;
        a[el2][el1]=1;
    }
    fclose(f);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%i ",a[i][j]);
        }
        printf("\n");
    }
}

///Iranyitott szomszedsagi matrix (sulyozott)
void d_adjacency_matrix(const char* name){
    FILE *f=fopen(name,"rt");
    if(!f){
        printf("Cannot open %s",name);
        return;
    }
    int n,m,**a;
    fscanf(f,"%i%i",&n,&m);
    a=(int**)calloc(n+1,sizeof(int*));
    for(int i=0;i<=n;++i){
        a[i]=(int*)calloc(n+1,sizeof(int));
    }
    int el1,el2,weight;
    for(int i=0;i<m;++i){
        fscanf(f,"%i%i%i",&el1,&el2,&weight);
        a[el1][el2]=weight;
    }
    fclose(f);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%i ",a[i][j]);
        }
        printf("\n");
    }
}


Node* createNode() {
    Node* newNode = (Node*)calloc(1, sizeof(Node));

    if(!newNode) {
        printf("Error while allocating newNode!");
        return NULL;
    }

    newNode->next = NULL;
    return newNode;
}

void adjacency_list(Node* , const char *name){
    FILE *f=fopen(name,"rt");
    if(!f){
        printf("Cannot open %s",name);
        return;
    }
    int n,m;
    Node* list;
    scanf("%i%i",&n,&m);
    list=(Node*)malloc(n*sizeof(Node));
    for(int i=0;i<n;++i) {
        list[i]=createNode();

    }
}


