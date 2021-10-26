#include <stdio.h>
#include <stdlib.h>

void hanoi(int,int*,int*,int*);

int main() {
    int n,*s,*h,*d;
    printf("Add meg hany szintu legyen a Hanoi tornya:");
    scanf("%i",&n);
    s=(int*)malloc(n*sizeof(int));
    h=(int*)malloc(n*sizeof(int));
    d=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        s[i]=n-i;
        printf("%i ",s[i]);
    }
    hanoi(n,s,d,h);
    return 0;
}

void hanoi(int k,int *s,int *d,int *h){
    if(k==1){
        printf("\nAtrakunk s-rol a d-re");
    }
    else{
        hanoi(k-1,s,h,d);
        printf("\nAtrakunk s-rol a d-re");
        hanoi(k-1,h,d,s);
    }
}
