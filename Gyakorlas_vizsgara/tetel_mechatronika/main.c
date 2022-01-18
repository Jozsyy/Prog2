#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char nev[20];
    int ev,nem,emelet;
}SZEMELY;

typedef struct{
    int a,b,suly;
}EL;

int int_cmp(const void*, const void*);
void greedy_strat(SZEMELY*,int);
void osszes_baratsag(SZEMELY *, int);
void min_koltseg(SZEMELY *, int);
int elek_cmp(const void*, const void*);
void egyesit(int*, int, int, int);


///6.feladat
int paratlan_szamjegyosszeg(int);

int main() {
    ///Allomany megnyitas
    FILE *f=fopen("input.txt","rt");
    if(!f){
        printf("Error!Cannot open the input file\n");
        return 0;
    }

    ///Helyfoglalas-Beolvasas
    SZEMELY *szemelyek;
    int n;
    fscanf(f,"%i\n",&n);
    szemelyek=(SZEMELY*)calloc(n,sizeof(SZEMELY));
    for(int i=0;i<n;++i){
        fscanf(f,"%[^ ] ",szemelyek[i].nev);
        fscanf(f,"%i%i%i\n",&szemelyek[i].ev,&szemelyek[i].nem,&szemelyek[i].emelet);
    }
    fclose(f);

    //1.Kiiratas
    for(int i=0;i<n;++i){
        printf("%s: -eletkor:%i, nem:%i, emelet:%i\n",szemelyek[i].nev,szemelyek[i].ev,szemelyek[i].nem,szemelyek[i].emelet);
    }

    //2.Atlageletkor ferfiak-nok
    double atlag1=0,atlag2=0;
    int n1=0,n2=0;
    for(int i=0;i<n;++i){
        if(szemelyek[i].nem==1){
            atlag1+=szemelyek[i].ev;
            n1++;
        }
        else{
            atlag2+=szemelyek[i].ev;
            n2++;
        }
    }
    atlag1/=n1;
    atlag2/=n2;
    printf("\nA ferfiak atlag eletkora:%.2lf\nA nok atlag eletkora:%.2lf\n",atlag1,atlag2);

    ///3.Lift hasznalata, hogy minimalis legyen a varakozasi ido
    greedy_strat(szemelyek,n);

    ///4. Az osszes lehetseges baratsag (Backtracking)
    printf("\nAz osszes baratsag:\n");
    osszes_baratsag(szemelyek,n);

    ///5. Minimalis koltseggel alakithato baratsagi kor
    min_koltseg(szemelyek,n);

    return 0;
}

int int_cmp(const void *p1, const void *p2){
    SZEMELY *q1=(SZEMELY *) p1;
    SZEMELY *q2=(SZEMELY *) p2;
    return q1->emelet-q2->emelet;
}

void greedy_strat(SZEMELY *szemelyek,int n){
    ///Rendezzuk novekvo sorrendbe a szmelyeket az emelethez kepest
    int varakozas=0;
    qsort(szemelyek,n,sizeof(SZEMELY),int_cmp);
    printf("\nA sorrend, hogy az osszvarakozasi ido a minimalis legyen:\n");
    for(int i=0;i<n;++i){
        printf("%s: -eletkor:%i, nem:%i, emelet:%i\n",szemelyek[i].nev,szemelyek[i].ev,szemelyek[i].nem,szemelyek[i].emelet);
        varakozas+=szemelyek[i].emelet;
    }
    printf("\nAz osszvarakozasi ido pedig:%i\n",varakozas);
}

void osszes_baratsag(SZEMELY *szemely, int n){
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j)
                printf("%s<->%s\n",szemely[i].nev,szemely[j].nev);
    }
}

void min_koltseg(SZEMELY *szemely, int n){
   /** Bool matrix (szomszedsagi)
    int **a=(int**)calloc(n,sizeof (int*));
    for(int i=0;i<n;++i){
        a[i]=(int*)calloc(n,sizeof(int));
    }

    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            if(szemely[i].ev-szemely[j].ev>=0){
                a[i][j]=szemely[i].ev-szemely[j].ev;
                a[j][i]=szemely[i].ev-szemely[j].ev;
            }
            else{
                a[i][j]=szemely[j].ev-szemely[i].ev;
                a[j][i]=szemely[j].ev-szemely[i].ev;
            }
        }
    }

    printf("\nBaratsag koltsegek:\n");
    for(int i=0;i<n;++i) {
        for (int j = 0; j < n; ++j) {
            printf("%i ",a[i][j]);
        }
        printf("\n");
    }
*/

   ///Ellista


   int m=(n-1)*n/2,k=0;     ///m=az elek szama (ahany baratsag van)   (n-1)+(n-2)+...+1
   EL *elek=(EL*)calloc(m,sizeof(EL));
   for(int i=0;i<n-1;++i){
       for(int j=i+1;j<n;++j){
           if(szemely[i].ev-szemely[j].ev>0){
               elek[k].a=i;
               elek[k].b=j;
               elek[k].suly=szemely[i].ev-szemely[j].ev;
               ++k;
           }
           else{
               elek[k].a=i;
               elek[k].b=j;
               elek[k].suly=szemely[j].ev-szemely[i].ev;
               ++k;
           }
       }
   }
   printf("\nSulyozott ellista\n");
   for(int i=0;i<m;++i){
       printf("%i-%i:%i\n",elek[i].a,elek[i].b,elek[i].suly);
   }

   ///Rendezzuk az ellistat
   qsort(elek,m,sizeof(EL),elek_cmp);

   printf("\nRendezett ellista:\n");
    for(int i=0;i<m;++i){
        printf("%s-%s:%i\n",szemely[elek[i].a].nev,szemely[elek[i].b].nev,elek[i].suly);
    }


    printf("\nMinimalis koltsegu korut:\n");
    ///Kruskal-min koltsegu korut
    int *fa=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        fa[i]=i;
    }

    int osszsuly=0,egyik,masik;
    for(int i=0;i<m;++i){
        egyik=fa[elek[i].a];
        masik=fa[elek[i].b];
        if(egyik!=masik){
            osszsuly+=elek[i].suly;
            printf("%s-%s:%i\n",szemely[elek[i].a].nev,szemely[elek[i].b].nev,elek[i].suly);
            egyesit(fa,n,egyik,masik);
        }
    }

    printf("\nAz osszsuly:%i",osszsuly);
}

int elek_cmp(const void *p1, const void *p2){
    EL *q1=(EL *) p1;
    EL *q2=(EL *) p2;
    return q1->suly-q2->suly;
}

void egyesit(int *fa, int n, int egyik, int masik){
    for(int i=0;i<n;++i){
        if(fa[i]==masik){
            fa[i]=egyik;
        }
    }
}




int paratlan_szamjegyosszeg(int n){
    if(n==0){
        return 0;
    }
    else{
        if(n%2==1){
            return paratlan_szamjegyosszeg(n/10)+1;
        }
        else{
            return paratlan_szamjegyosszeg(n/10);
        }
    }
}