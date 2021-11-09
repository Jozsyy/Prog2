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

///Iranyitatlan szomszedsagi lista
void u_adjacency_list(const char *fileName){
    FILE *f=fopen(fileName,"rt");
    if(!f){
        printf("Cannot open %s",fileName);
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
        int j=1,k=1;
        while(a[el1][j]!=0){
            ++j;
        }
        while(a[el2][k]!=0){
            ++k;
        }
        a[el1][j]=el2;
        a[el2][k]=el1;
    }
    fclose(f);

    for(int i=1;i<=n;++i){
        printf("%i ",i);
        for(int j=1;j<=n && a[i][j]!=0;++j){
            printf("%i ",a[i][j]);
        }
        printf("\n");
    }
}

void d_adjacency_list(const char *fileName){
    FILE *f=fopen(fileName,"rt");
    if(!f){
        printf("Cannot open %s",fileName);
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
        int j=1;
        while(a[el1][j]!=0){
            ++j;
        }
        a[el1][j]=el2;
    }
    fclose(f);

    for(int i=1;i<=n;++i){
        printf("%i ",i);
        for(int j=1;j<=n && a[i][j]!=0;++j){
            printf("%i ",a[i][j]);
        }
        printf("\n");
    }
}

///Illeszkedesi matrix
void u_incidence_matrix(const char *fileName){
    FILE *f=fopen(fileName,"rt");
    if(!f){
        printf("Cannot open %s",fileName);
        return;
    }
    int n,m,**a;
    fscanf(f,"%i%i",&n,&m);
    a=(int**)calloc(n+1,sizeof(int*));
    for(int i=0;i<=n;++i){
        a[i]=(int*)calloc(m+1,sizeof(int));
    }

    int el1,el2;
    int c=1;
    for(int i=0;i<m;++i){
        fscanf(f,"%i%i",&el1,&el2);
        a[el1][c]=1;
        a[el2][c]=1;
        ++c;
    }
    fclose(f);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%i ",a[i][j]);
        }
        printf("\n");
    }
}

///Ellista
void u_el_list(const char *fileName){
    FILE *f=fopen(fileName,"rt");
    if(!f){
        printf("Cannot open %s",fileName);
        return;
    }
    int n,m,**a;
    fscanf(f,"%i%i",&n,&m);
    a=(int**)calloc(m+1,sizeof(int*));
    for(int i=0;i<=m;++i){
        a[i]=(int*)calloc(3,sizeof(int));
    }

    int el1,el2;
    for(int i=1;i<=m;++i){
        fscanf(f,"%i%i",&el1,&el2);
        a[i][1]=el1;
        a[i][2]=el2;
    }
    fclose(f);

    for(int i=1;i<=m;++i){
        printf("%i %i %i\n",i,a[i][1],a[i][2]);
    }
}


