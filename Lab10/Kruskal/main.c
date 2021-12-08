#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u,v;
    double suly;
}EL;

void egyesit(int*,int,int,int);

int main() {

    FILE *f=fopen("input.txt","rt");
    if(!f){
        printf("Error!Cannot open the input file");
        return 0;
    }

    int n,m;
    fscanf(f,"%i%i",&n,&m);
    EL *elek;
    elek=(EL*)malloc((m+1)*sizeof(EL));
    if(!elek){
        printf("Error while allocating memory");
        return 0;
    }

    for(int i=1;i<=m;++i){
        fscanf(f,"%i%i%lf",&elek[i].u,&elek[i].v,&elek[i].suly);
    }
    fclose(f);

    for(int i=1;i<=m;++i){
        printf("%i %i %.2lf\n",elek[i].u,elek[i].v,elek[i].suly);
    }

   // qsort(elek,m, sizeof (double), double_cmp);

   EL aux;
   for(int i=1;i<m;++i){
       for(int j=i+1;j<=m;++j){
           if(elek[i].suly>elek[j].suly){
               aux=elek[i];
               elek[i]=elek[j];
               elek[j]=aux;
           }
       }
   }

   printf("\nRendezes utan:\n");
    for(int i=1;i<=m;++i){
        printf("%i %i %.2lf\n",elek[i].u,elek[i].v,elek[i].suly);
    }

    int *fa=(int*)malloc((n+1)*sizeof(int));
    if(!fa){
        printf("Error while allocating memory");
        return 0;
    }
    for(int i=1;i<=n;++i){
        fa[i]=i;
    }
    double osszsuly=0;
    int egyik,masik;
    printf("...........Minimalis feszitofahoz szukseges elek-sulyokkal......\n");
    for(int i=1;i<=m;++i){
        egyik=fa[elek[i].u];
        masik=fa[elek[i].v];
        if(egyik!=masik){
            osszsuly+=elek[i].suly;
            printf("%i %i %.2lf\n",elek[i].u,elek[i].v,elek[i].suly);
            egyesit(fa,n,egyik,masik);
        }
//        else{
//            printf("!!!%i %i %.2lf\n",elek[i].u,elek[i].v,elek[i].suly);
//        }
    }

    printf("\nOsszkoltseg:%.2lf",osszsuly);



    free(elek);
    free(fa);
    return 0;
}

void egyesit(int *fa,int n,int egyik,int masik){
    for(int i=1;i<=n;++i){
        if(fa[i]==masik){
            fa[i]=egyik;
        }
    }
}

