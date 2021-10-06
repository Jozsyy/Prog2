#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool prim(int);
int mirror(int);

int main() {
    int *a,n;
    scanf("%i",&n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        scanf("%i",&a[i]);
    }
    for(int i=0;i<n;++i){
        if(prim(a[i]) && prim(mirror(a[i]))){
            printf("%i ",a[i]);
        }
    }

    return 0;
}

bool prim(int n){
    if(n<2) return false;
    if(n!=2 && n%2==0) return false;
    for(int d=3;d*d<=n;d+=2){
        if(n%d==0) return false;
    }
    return true;
}

int mirror(int n){
    int m=0;
    while(n>0){
        m=m*10+n%10;
        n/=10;
    }
    return m;
}
