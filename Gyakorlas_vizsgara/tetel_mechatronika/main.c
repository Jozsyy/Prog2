#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nev[20];
    int ev,nem,emelet;
}SZEMELY;

int int_cmp(const void*, const void*);
void greedy_strat(SZEMELY*,int);

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
