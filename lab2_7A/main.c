#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,*a;
    scanf("%i",&n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;++i){
        scanf("%i",&a[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=2;j<n;++j){
            if(j==a[i]){
                for(int d=j+1;d<n;++d){
                    if(a[j]>a[d]){
                        int e=a[j];
                        for(int k=j;k<n-1;++k){
                            a[k]=a[k+1];
                        }
                        a[n-1]=e;
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            printf("%i ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
