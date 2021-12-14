#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int kezd,veg;
    char cim[40];
}FILM;

int main() {
    FILE *f=fopen("filmek.txt","rt");
    if(!f){
        printf("Error! Cannot open the input file");
        return 0;
    }
    int n;
    FILM *a;
    fscanf(f,"%i\n",&n);
    a=(FILM*)calloc(n,sizeof(FILM));
    for(int i=0;i<n;++i){
        fscanf(f,"%[^\n]\n",a[i].cim);
        fscanf(f,"%i%i\n",&a[i].kezd,&a[i].veg);
    }
    fclose(f);

//    for(int i=0;i<n;++i){
//        printf("%s:",a[i].cim);
//        printf("%i %i\n",a[i].kezd,a[i].veg);
//    }

    //rendezzuk a filmeket a vegzodesukhoz kepest
    FILM aux;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            if(a[i].veg>a[j].veg){
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }

//    printf("A filmek rendezes utan:\n");
//    for(int i=0;i<n;++i){
//        printf("%s:",a[i].cim);
//        printf("%i %i\n",a[i].kezd,a[i].veg);
//    }

    //Filmek kivalasztasa---Greedy
    printf("Kivalasztott filmek:\n");
    printf("%s: %i %i\n",a[0].cim,a[0].kezd,a[0].veg);
    int megnezve=0;
    for(int i=1;i<n;++i){
        if(a[i].kezd>=a[megnezve].veg){
            printf("%s: %i %i\n",a[i].cim,a[i].kezd,a[i].veg);
            megnezve=i;
        }
    }
    return 0;
}
