#include <stdio.h>
#include "functions.h"

int main() {
    int a[]={1, 6, 3, 19, 5},n=5;
    //msort(a,0,n-1);
    QS(a,0,n-1);
    for(int i=0;i<n;++i){
        printf("%i ",a[i]);
    }
    return 0;
}
