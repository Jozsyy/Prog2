#include <stdio.h>
#include <stdlib.h>

void selection(int*,int);
int min_index(int*,int,int);
void swap(int*,int*);

int main() {
    int *a,n;
    scanf("%i",&n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        scanf("%i",&a[i]);
    }
    selection(a,n);
    for(int i=0;i<n;++i){
        printf("%i ",a[i]);
    }
    return 0;
}

void selection(int *a,int n){
    for(int i=0;i<n-1;++i){
        int j=min_index(a,i,n);
        swap(&a[i],&a[j]);
    }
}

void swap(int *x,int *y){
    int aux=*x;
    *x=*y;
    *y=aux;
}

int min_index(int *a,int i,int n){
    int min=a[i],index=i;
    for(int j=i+1;j<n;++j){
        if(a[j]<min){
            min=a[j];
            index=j;
        }
    }
    return index;
}
