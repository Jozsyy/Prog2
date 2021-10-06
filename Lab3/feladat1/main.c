#include <stdio.h>

int pow(int ,int);

int main() {
    int x,n;
    scanf("%i%i",&x,&n);
    printf("%i",pow(x,n));
    return 0;
}

int pow(int x,int n){
    int p=1;
    for(int i=0;i<n;++i){
        p*=x;
    }
    return p;
}
