#include <stdio.h>
#include <stdlib.h>

int binary_search(int*,int,int,int,int);
int min_search(int *x,int n);
int max_search(int *x,int n);
int max2_search(int *x,int n);
int lnko(int , int );

int main() {
    FILE *f=freopen("input.txt","rt",stdin);
    if(!f){
        printf("Error. Cannot open the input file!");
        return 0;
    }
    int *x,y,n;
    scanf("%i",&n);
    x=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        scanf("%i",&x[i]);
    }
    scanf("%i",&y);
    fclose(f);

    printf("\nMinimum kereses:%i",min_search(x,n-1));
    printf("\nMaximum kereses:%i",max_search(x,n-1));
    printf("\nMaximum 2. kereses:%i",max2_search(x,n-1));
    //Bubble_sort rendezes
    int ok;
    do{
       ok=0;    //feltetelezzuk, hogy a tomb rendezve van
       for(int i=0;i<n-1;++i){
           if(x[i]>x[i+1]){
               int aux=x[i];
               x[i]=x[i+1];
               x[i+1]=aux;
               ok=1;
           }
       }
    }while(ok);

    printf("\nRendezes utan:\n");
    for(int i=0;i<n;++i){
        printf("%i ",x[i]);
    }

    printf("\n%i",binary_search(x,n,0,n-1,y));

    printf("\nLNKO 100,150:%i", lnko(100,150));
    return 0;
}

int binary_search(int *x,int n,int l,int r,int y){
    if(l>r){ return 0;}
    int mid=(l+r)/2;
    if(x[mid]==y){return mid;}
    if(x[mid]<y){ return binary_search(x,n,mid+1,r,y);}
    if(x[mid]>y){ return binary_search(x,n,l,mid-1,y);}
}

int min_search(int *x,int n){
    if(n==0){ return *x;}
    else{
        int minn= min_search(x,n-1);
        if(x[n]<minn){return x[n];}
        else{
            return minn;
        }
    }
}

int max_search(int *x,int n){
    if(n==0){ return *x;}
    else{
        int maxx= max_search(x,n-1);
        if(x[n]>maxx){return x[n];}
        else{
            return maxx;
        }
    }
}

int max2_search(int *x,int n){
    if(n==0){ return *x;}
    else{
        int maxx= max2_search(x+1,n-1);
        if(maxx>*x){ return maxx;}
        else{ return *x;}
    }
}

int lnko(int x, int y){
    if(x==0){ return y;}
    else{ return lnko(y%x,x);}
}
