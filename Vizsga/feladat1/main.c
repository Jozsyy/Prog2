#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char marka[20],rendszam[8];
    int ev,cm3;
}AUTO;

AUTO min_kereses(AUTO *, int, int);
int cmp(const void *, const void *);
int neg_rec(int *, int);

int main() {
    ///allomany megnyitas
    FILE *f=fopen("auto.txt","rt");
    if(!f){
        printf("Error!Cannot open the input file!");
        return 0;
    }
    int n;
    fscanf(f,"%i\n",&n);

    ///helyfoglalas
    AUTO *autok=(AUTO*)calloc(n,sizeof(AUTO));
    if(!autok){
        printf("Error while allocating memory");
        return 0;
    }

    ///beolvasas-kiiratas
    for(int i=0;i<n;++i){
        fscanf(f,"%[^ ] ",autok[i].marka); ///beolvassuk a markat space jelig
        fscanf(f,"%i%i",&autok[i].ev,&autok[i].cm3);
        fscanf(f,"%s\n",autok[i].rendszam);
        printf("%s %i %i %s\n",autok[i].marka, autok[i].ev, autok[i].cm3,autok[i].rendszam);
    }
    fclose(f);

    ///2.Legidosebb auto
    AUTO legidosebb;
    legidosebb= min_kereses(autok,0,n-1);
    printf("\nA legidosebb auto adatai: %s %i %i %s\n",legidosebb.marka,legidosebb.ev, legidosebb.cm3, legidosebb.rendszam);

    ///3.Rendszam szerint rendezes
    qsort(autok,n,sizeof(AUTO),cmp);
    printf("\nRendszam szerint rendezett autok adatai:\n");
    for(int i=0;i<n;++i){
        printf("%s %i %i %s\n",autok[i].marka, autok[i].ev, autok[i].cm3,autok[i].rendszam);
    }
    free(autok);


    ///4.Szamsorozat negativ elemeinek szama
    int *a=(int*)malloc(n*sizeof(int)); ///az allomanybol vett n-et hasznaljuk
    printf("\nAdd meg a/az %i elembol allo szamsorozatot:\n",n);
    for(int i=0;i<n;++i){
        scanf("%i",&a[i]);          ///console-rol olvassuk az adatokat
    }
    printf("A szamsorozatban %i negativ elem szerepel", neg_rec(a,n-1));
    free(a);
    return 0;
}

///divide et impera modszerrel
AUTO min_kereses(AUTO *autok, int a, int b){
    if(a==b){
        return autok[a];
    }
    else {
        AUTO minn1, minn2;
        minn1 = min_kereses(autok, a, (a+b)/2);
        minn2 = min_kereses(autok, (a+b)/ 2 + 1,b);
        if (minn1.ev < minn2.ev) {
            return minn1;
        }
        else{
            return minn2;
        }
    }

}

int cmp(const void *p1, const void *p2){
    AUTO *q1=(AUTO*) p1;
    AUTO *q2=(AUTO*) p2;
    int szam1=(q1->rendszam[2]-'0')*10 + q1->rendszam[3]-'0'; ///atalakitjuk a rendszambol a szamot int-e
    int szam2=(q2->rendszam[2]-'0')*10 + q2->rendszam[3]-'0';
    return szam1-szam2;
}

int neg_rec(int *a, int n){
    if(n==0){
        if(*a<0){ return 1;}
        ///vagy itt return 0 es nem a vegen
    }
    else{
        if(*a<0){
            return 1+ neg_rec(a+1,n-1);
        }
        else{
            return neg_rec(a+1,n-1);
        }
    }
    return 0;
}

/** Min kereses rekurzivan
AUTO min_kereses(AUTO *autok, int n){
    if(n==0){
        return *autok;
    }
    else{
        AUTO minn= min_kereses(autok+1,n);
        if(minn.ev<autok->ev){
            return minn;
        }
        else{
            return *autok;
        }
    }
}
 */