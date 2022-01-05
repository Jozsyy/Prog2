#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int penz,db;
}PENZ;

int prim(int);
int dupla_paros(int);
int cmp(const void*, const void*);
void moho_alg(int osszeg,PENZ* penzek,int m);

int main() {

    ///1. feladat
    int n,**a;
    scanf("%i",&n);
    a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;++i){
        a[i]=(int*)malloc(n*sizeof(int));
    }
    if(!a){
        printf("Error while allocating memory");
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%i",&a[i][j]);
        }
    }

    int c=0;
    for(int i=0;i<n;++i){
        if(prim(a[i][i])==1){
            ++c;
        }

    }

    printf("A foatlon levo primszamok szama: %i\n",c);


    ///2. feladat
    int x;
    scanf("%i",&x);
    printf("%i\n\n", dupla_paros(x));

    ///3. feladat
    FILE *f=fopen("input.txt","rt");
    if(!f){
        printf("Error while opening the input file");
        return 0;
    }
    int m,osszeg;
    fscanf(f,"%i%i",&m, &osszeg);
    PENZ *penzek;
    penzek=(PENZ*)malloc(n*sizeof (PENZ));
    for(int i=0;i<m;++i){
        fscanf(f,"%i",&penzek[i].penz);
    }
    for(int i=0;i<m;++i){
        fscanf(f,"%i",&penzek[i].db);
    }
    qsort(penzek,m,sizeof(PENZ),cmp);

    printf("Penzermek rendezes utan:\n");
    for(int i=0;i<m;++i){
        printf("%i %i\n",penzek[i].penz,penzek[i].db);
    }
    printf("\n");

    moho_alg(osszeg,penzek,m);
    return 0;
}

int prim(int x){
    if(x<2) return 0;
    if(x!=2 && x%2==0) return 0;
    for(int i=3;i*i<=x;i=i+2){
        if(x%i==0){ return 0;}
    }
    return 1;
}

int dupla_paros(int x){
    if(x>0){
        if(x%2==0){
            if(x%10*2>9){
                return 100 * dupla_paros(x/10) + x%10*2;
            }
            else{
                return 10 * dupla_paros(x/10) + x%10*2;
            }
        }
        else{
            return 10 * dupla_paros(x/10) + x%10;
        }
    }
    else{
        return 0;
    }

}


int cmp(const void *p1, const void *p2){
    PENZ *q1=(PENZ*) p1;
    PENZ *q2=(PENZ*) p2;
    return q2->penz-q1->penz;
}

void moho_alg(int osszeg,PENZ* penzek,int m){
        for(int i=0;i<m;++i){

            int db=0;
            while(osszeg-penzek[i].penz>=0 && penzek[i].db>0 ){
                db++;
                osszeg-=penzek[i].penz;
                penzek[i].db--;
            }
            printf("%i db:%i\n",db,penzek[i].penz);
        }
    if(osszeg==0){
        printf("\nKi lehet fizetni az osszeget");
    }
    else{
        printf("\nNem lehet kifizetni az osszeget");
    }
}

