#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f=fopen("bemenet.txt","r");
    if(!f){
        printf("Cannot open the input file!");
        return 0;
    }
    int n,m,**adjM;
    char *s;
    fscanf(f,"%i%i\n",&n,&m);
    adjM=(int**)calloc(n+1,sizeof(int*));
    for(int i=1;i<=n;++i){
        adjM[i]=(int*)calloc(n+1,sizeof (int));
    }
    s=(char*)malloc((n+1)*sizeof(char));
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

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%i ",adjM[i][j]);
        }
        printf("\n");
    }
    return 0;
}
