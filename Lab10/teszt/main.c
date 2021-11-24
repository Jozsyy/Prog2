/*5. Adott a G irányított gráf a csomópontok számával, élek számával valamint az éllistával
        (zárójelben az élsúlyok, esetünkben összegyűjthető zsetonk száma):
a:b(3), c(8); b:d(7); c:d(5); d:e(2); e:a(10)
Mennyit zsetont tud egy játékos össegyűjteni az a ponttól az e pontig:
a) Mélységi bejárással (5 pont)
b) Szélességi bejárással (5 pont)
Megjegyzés: a zsetonok csak menetirány számolódnak, mindig a kiindulópont és az érkezési
pont útvonalon.
*/
#include <stdio.h>
#include <stdlib.h>

void dfs(int **adjM,int *color,int tav,int x,int y,int n);
void bfs(int **adjM, int *color, int tav, int n, int x,int y,int *q,int e, int v);

int main() {
    FILE *f=fopen("in.txt","rt");
    if(!f){
        printf("Cannot open the input file!");
        return 0;
    }
    int **adjM,n,m,*color,*color2,*q;
    fscanf(f,"%i%i\n",&n,&m);
    //helyfoglalas a boole matrixnak
    adjM=(int**)calloc(n+1,sizeof(int*));
    for(int i=1;i<=n;++i){
        adjM[i]=(int*)calloc(n+1,sizeof(int));
    }
    color=(int*)calloc(n+1,sizeof(int));
    color2=(int*)calloc(n+1,sizeof(int));
    q=(int*)calloc(n+1,sizeof(int));
    int ascii=97,suly,e1,e2;   //97-tol kezdodnek a kis betuk
    char el1,el2,aux;
    for(int i=0;i<m;++i) {
        fscanf(f, "%c%c%c", &el1, &aux, &el2);
        fscanf(f, "%i\n", &suly);
        //a betuket atalakitom szamma, ugy hogy az a=1,b=2,c=3...
        e1 = el1-ascii + 1;
        e2 = el2-ascii + 1;
        adjM[e1][e2]=suly;
    }

    //utoljara az el1 es el2-be beolvassuk a kiindulo es vegpontot
    fscanf(f, "%c%c%c", &el1, &aux, &el2);
    //atalakitjuk oket es taroljuk az e1 es e2-be
    e1 = el1-ascii + 1;
    e2 = el2-ascii + 1;

    fclose(f);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            printf("%i ",adjM[i][j]);
        }
        printf("\n");
    }

    int tav=0,e,v;  //tavolsag: itt osszeadjuk a sulyokat(zsetonokat)

    printf("Osszegyujtheto zsetonok %c ponttol a/az %c pontig melysegi bejarassal:",el1,el2);
    dfs(adjM,color,tav,e1,e2,n);

    tav=0,e=0,v=0;
    q[0]=e1;
    printf("\nOsszegyujtheto zsetonok %c ponttol a/az %c pontig szelessegi bejarassal:",el1,el2);
    bfs(adjM,color2,tav,n,e1,e2,q,e,v);
    return 0;
}

void dfs(int **adjM,int *color,int tav,int x,int y,int n){
    int j;
    color[x]=1;
    //printf("%i->",x);
    for(j=1;j<=n;++j){
        if(adjM[x][j]!=0 && color[j]==0){
            tav+=adjM[x][j];
            if(j==y){
                printf("%i",tav);
                break;
            }
            dfs(adjM,color,tav,j,y,n);
        }
    }
    color[x]=2;
}


void bfs(int **adjM, int *color, int tav, int n, int x,int y,int *q,int e, int v){   //e=a sor eleje, v=a sor vege, mi esetunkbe a sor q
    while(e<=v){
        int i=q[e];
        //printf("%i->",i);
        for(int j=1;j<=n;++j){
            if(adjM[i][j]!=0 && color[j]==0){
                ++v;
                q[v]=j;
                tav+=adjM[i][j];
                if(j==y){
                    printf("%i",tav);
                }
                color[j]=1;
            }
        }
        ++e;
        color[i]=2;
    }
}
