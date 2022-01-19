#include <stdio.h>
#include <stdlib.h>

void dfs(int**,int,int*,int,int,int);

int main() {
    FILE *f=fopen("grafok.txt","rt");
    int **adjM,n,m;
    fscanf(f,"%i%i",&n,&m);
    adjM=(int**)calloc(n+1,sizeof(int*));
    for(int i=1;i<=n;++i){
        adjM[i]=(int*) calloc(n+1,sizeof(int));
    }
    for(int i=0;i<m;++i){
        int el1,el2,suly;
        fscanf(f,"%i%i%i",&el1,&el2,&suly);
        adjM[el1][el2]=suly;
        adjM[el2][el1]=suly;
    }
    fclose(f);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%3i ",adjM[i][j]);
        }
        printf("\n");
    }

    int tav=0,*color=(int*)calloc(n+1,sizeof(int));
    int a=3,b=5;

    //printf("\nA tavolsag:");
    dfs(adjM,n,color,tav,a,b);

    return 0;
}

void dfs(int **adjM,int n,int *color,int tav,int a,int b){
    color[a]=1;
    printf("%i->",a);
    for(int i=1;i<=n;++i) {
        if (adjM[a][i] != 0 && color[i] == 0) {
            tav+=adjM[a][i];
//            if(i==b){
//                printf("%i\n",tav);
//                return;
//            }
            dfs(adjM, n, color, tav, i, b);
        }
    }
    color[a]=2;
}
