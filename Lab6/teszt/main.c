#include "functions.h"

int main() {

    FILE *f=fopen("input.txt","rt");
    if(!f){
        printf("Cannot open the input file!");
        return 0;
    }
    int *a,n;
    fscanf(f,"%i",&n);
    a=(int*)malloc(n*sizeof(int));
    read_rec(f,a,n,0);
    fclose(f);
    printf("A paros pozicion illetve a paratlan pozicion levo szamok "
           "osszegenek a kulonbsege:%i\n", sum_pair(a,n,0)-sum_impair(a,n,0));


    ///2 feladathoz is felhasznaljuk az input file-ban levo adatokat, amiket mar beolvastunk
    ///Rendezzuk a tombot
    qsort(a,n,sizeof(int),int_cmp);

    for(int i=0;i<n;++i){
        printf("%i ",a[i]);
    }
    ///Keressuk meg a az 5 sulyu ladat: ha letezik akkor irassuk ki a poziciot,
    /// ha nem akkor -1-es erteket
    printf("\n%i", binary_search(a,0,n,5));

    /// Keressuk meg a legnagyobb sulyu ladat
    printf("\nA legnagyobb sulyu lada:%i\n",a[maxindex(a,0,n-1)]);

    ///Feltetelezzuk, hogy egymasra rakunk annyi ugyanolyan ladat az adott sulyu ladakbol ahany (kg) sulyu az adott lada
    ///irassuk ki az igy kapott ladak sulyait
    for(int i=0;i<n;++i){
        printf("%i ", power(a[i],2));
    }
    return 0;
}
