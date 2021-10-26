
#include "functions.h"

int main() {
    int n,*a;
    FILE *f,*g;
    f=fopen("in.txt","rt");
    if(!f){
        printf("Error!Cannot open the file");
        return 0;
    }
    fscanf(f,"%i",&n);
    a=(int*)malloc(n*sizeof(int));
    if(!a){
        printf("Error while allocate memory!");
    }
    //read(f,a,n);
    read_rec(f,a,n,0);
    fclose(f);

    g=fopen("out.txt","wt");
    //print(g,a,n);
    print_rec(f,a,n,0);
    fclose(g);

    //printf("Szamjegyek osszege:%i\n",sum(a,n));
    printf("Szamjegyek osszege:%i\n", sum_rec(a,n,0));

//    if(is_in_array(a,n)){
//        printf("A szamsorozatban szerepel 0");
//    }
//    else{
//        printf("A szamsorozatban nem szerepel 0");
//    }
    if(is_in_array_rec(a,n,0)){
        printf("A szamsorozatban szerepel 0\n");
    }
    else{
        printf("A szamsorozatban nem szerepel 0\n");
    }


    printf("A szam szamjegyei:");
    print_digit_number(a[0]);
    printf("\nA szam szamjegyeinek szama:%i", number_digit_number(a[0]));
    printf("\nA szam paros szamjegyei kitorolve:%i", delete_digit_number(a[0]));
    printf("\nA szam paros szamjegyei utan 9-es beszurasa:%i", insert_digit_number(a[0]));
    printf("\nEgy szam hatvanya: %i", power2(2,10));


    ///Labor 5

    printf("\nMax szam:%i", *maxkereses(a,n));  ///maxkereses->visszateriti a cimet; *maxkereses->szamot
    printf("\nMax2:%i", max_kereses(a,n-1));
    if(binariskereses(a,0,n-1,150)!=-1) {
        printf("\nA keresett szam indexe:%i", binariskereses(a, 0, n - 1, 150));
    }
    else{
        printf("\nA keresett szam nincsa tombben!");
    }

    int szam=5;
    if(letezik_e(a,n,5)){
        printf("\nA szamsorozatba letezik az megadott %i szam",szam);
    }
    else{
        printf("\nA szamsorozatba nem letezik a megadott %i szam",szam);
    }
    printf("\n%i a kobon:%i",szam, hatvanyozas_1(szam,3));
    printf("\n%i a 4-en:%i",szam, hatvanyozas_2(szam,4));
    printf("\nLnko 15,25: %i", lnko(50,30));
    return 0;
}
