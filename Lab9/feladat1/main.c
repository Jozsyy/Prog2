#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char**,int**,int*,int*,int,int,int);

int main() {
    FILE *f=fopen("bemenet.txt","r");
    if(!f){
        printf("Cannot open the input file!");
        return 0;
    }
    int n,m,**adjM,*tav,*color;
    fscanf(f,"%i%i\n",&n,&m);
    color=(int*)calloc(n+1,sizeof(int));
    tav=(int*)calloc(n,sizeof(int));
    char **s=(char**)malloc((n+1)*sizeof(char*));
    adjM=(int**)calloc(n+1,sizeof(int*));
    for(int i=1;i<n+1;++i){
        s[i]=(char*)malloc(30*sizeof(char));
        fscanf(f, "%[^\n]\n", s[i]);
        adjM[i]=(int*)calloc(n+1,sizeof(int));
    }

//    for(int i=1;i<=n;++i){
//        printf("%s\n",s[i]);
//    }

    for(int i=0;i<m;++i){
        int el1,el2;
        fscanf(f,"%i%i\n",&el1,&el2);
        adjM[el1][el2]=1;
        adjM[el2][el1]=1;
    }


    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            printf("%i ",adjM[i][j]);
        }
        printf("\n");
    }

    ///beolvassuk a 2 nevet
    char x[30],y[30];
    int x1,y1;
    fscanf(f, "%[^\n]\n %[^\n]\n", x,y);
    fclose(f);
    ///megkeressuk, hogy hanyadik csomopontok a keresett szemelyek
    for(int i=0;i<n;++i){
        //kezdo csomopont x1
        if(strcmp(s[i],x)==0){
            x1=i;
        }
        //vegso csomopont y1
        if(strcmp(s[i],y)==0){
            y1=i;
        }
    }

    printf("%s es %s tavolsaga melysegi bejarassal:",x,y);
    dfs(s,adjM,color,tav,x1,y1,n);
    return 0;
}

void dfs(char **s,int **adjM,int *color,int *tav,int x,int y,int n){
    int j;
    color[x]=1;
    //printf("%i->",x);
    for(j=1;j<=n;++j){
        if(adjM[x][j]==1 && color[j]==0){
            int k=0;
            while(tav[k]!=0){++k;}
            tav[k]=j;
            if(j==y){
                printf("%i",k);
                break;
            }
            dfs(s,adjM,color,tav,j,y,n);
        }
    }
    color[x]=2;
}
