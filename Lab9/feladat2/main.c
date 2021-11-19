#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int**, int*, int*, char*, char*, char*, int, int);

int main() {
    FILE *f=fopen("bemenet.txt","r");
    if(!f){
        printf("Cannot open the input file!");
        return 0;
    }
    int n,m,**adjM,*color,*dist,x;
    char *s,*test,*dists;
    fscanf(f,"%i%i\n",&n,&m);

    //Helyfoglalasok
    adjM=(int**)calloc(n+1,sizeof(int*));
    for(int i=1;i<=n;++i){
        adjM[i]=(int*)calloc(n+1,sizeof (int));
    }
    color=(int*)calloc(n+1,sizeof(int));
    dist=(int*)calloc(n+1,sizeof(int));
    s=(char*)malloc((n+1)*sizeof(char));
    test=(char*)malloc((n+1)*sizeof(char));
    dists=(char*)calloc((n+1),sizeof(char));

    //beolvasasok
    char aux;//szokozoket ide olvassuk
    for(int i=1;i<=n;++i){
        fscanf(f,"%c%c",&s[i],&aux);
    }
    for(int i=0;i<m;++i){
        int el1, el2;
        fscanf(f,"%i%i",&el1,&el2);
        adjM[el1][el2]=1;
        adjM[el2][el1]=1;
    }

    fscanf(f,"%s",test);
    fscanf(f,"%i",&x);
    dist[0]=x;
    dists[0]=s[x];
    fclose(f);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%i ",adjM[i][j]);
        }
        printf("\n");
    }

    dfs(adjM,color, dist,s,test, dists,n,x);
    return 0;
}

void dfs(int **adjM, int *color, int *dist, char *s, char *test, char* dists, int n,int x){     ///dist-melysegi bejaras x-bol indulva  ///dists- melysegi bejaras xbol karakterlanckent
    int j;
    color[x]=1;
    //printf("%i->",x);
    for(j=1;j<=n;++j){
        if(adjM[x][j]==1 && color[j]==0){
            int k=0;
            while(dist[k]!=0){++k;}
            dist[k]=j;
            dists[k]=s[j];
            if(strlen(dists)>=strlen(test) && strstr(dists,test)!=NULL && strcmp(strstr(dists,test),test)==0){
                printf("\nSikeresen megkaptuk a teszt:%s karakterlancot a melysegi bejarasssal",test);
                printf("\nAz eddigi megtett tavolsag karakterlancokban:%s",dists);
                break;
            }
            dfs(adjM,color,dist,s,test,dists,n,j);
        }
    }
    color[x]=2;
}