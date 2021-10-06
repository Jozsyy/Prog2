#include <stdio.h>

int small(int );

int main() {
    int x,s=0;
    scanf("%i",&x);
    while(x!=0){
        s+= small(x);
        scanf("%i",&x);
    }
    printf("%i",s);
    return 0;
}

int small(int a){
    int small=9;
    while(a){
        if(a%10<small){
            small=a%10;
        }
        a/=10;
    }
    return small;
}

