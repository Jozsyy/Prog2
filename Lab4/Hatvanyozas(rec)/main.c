#include <stdio.h>

int power(int, int);

int main() {
    int x,n;
    scanf("%i%i",&x,&n);
    printf("%i", power(x,n));
    return 0;
}

int power(int x, int n){
    if(n>0){
        return power(x,n-1)*x;
    }
    else{
        return 1;
    }
}
