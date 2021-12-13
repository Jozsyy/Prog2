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

    for(int i=0;i<n;++i){
        printf("%s:",a[i].cim);
        printf("%i %i\n",a[i].kezd,a[i].veg);
    }

    return 0;
}
