#include <stdio.h>
#include <stdlib.h>

void bubblesort(int*,int);
void bubble(int *,int);
void bubblesort2(int*,int);
int bubble2(int*,int);

int main() {
    int *a,n;
    scanf("%i",&n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        scanf("%i",&a[i]);
    }
    bubblesort2(a,n);
    for(int i=0;i<n;++i){
        printf("%i ",a[i]);
    }
    return 0;
}

void bubblesort(int *a,int n){
    for(int i=n-1;i>=1;--i){
        bubble(a,i);
    }
}

void bubble(int *a,int n){
    for(int i=0;i<n;++i){
        if(a[i]>a[i+1]){
            int aux=a[i];
            a[i]=a[i+1];
            a[i+1]=aux;
        }
    }
}

/**
 * Bemenet:
 5
19 10 15 20 11
 */

void bubblesort2(int *a,int n){
    int last=n-1;
    while(last>0){
        last=bubble2(a,last);
        printf("%i\t",last);
    }
}

int bubble2(int *a,int n){
    int last;
    for(int i=0;i<n;++i){
        if(a[i]>a[i+1]){
            int aux=a[i];
            a[i]=a[i+1];
            a[i+1]=aux;
            last=i;
        }
    }
    return last;
}
