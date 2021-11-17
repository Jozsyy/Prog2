#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void dfs(char**,int**,int,int,int);

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

    for(int i=1;i<=n;++i){
        printf("%s\n",s[i]);
    }

    for(int i=0;i<m;++i){
        int el1,el2;
        fscanf(f,"%i%i\n",&el1,&el2);
        printf("%i%i",el1,el2);
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
    fscanf(f, "%[^\n]\n%[^\n]\n", x,y);
    ///megkeressuk, hogy hanyadik csomopontok a keresett szemelyek
    for(int i=0;i<n;++i){
        //kezdo csomopont x1
        if(strcmp(strstr(s[i],x),x)==0){
            x1=i;
            printf("%i\t",x1);
        }
        //vegso csomopont y1
        if(strcmp(strstr(s[i],y),y)==0){
            y1=i;
            printf("%i\t",y1);
        }
    }

    int k=0;//szamlalo
    for(int i=x1;i<=y1;++i){
        color[i]=1;
        tav[k]=i;

    }

    return 0;
}

void dfs(char **s,int **adjM,int n,int x1,int y1){

}
