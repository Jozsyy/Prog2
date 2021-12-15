#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int db = 0;

void bt(int *x, int n, int k);
bool igeretes(int *x, int k);
void kiir(int *x, int n);

int main()
{
    int n, x[100];
    scanf("%i", &n);
    bt(x,n,1);
    return 0;
}

void bt(int *x, int n, int k){
    for( x[k] = 1 ; x[k] <= n ; ++x[k] ){
        if( igeretes(x,k) ){
            if( k < n ){
                bt(x,n,k+1);
            }
            else{
                kiir(x,n);
            }
        }
    }
}
/* Descartes szorzat
bool igeretes(int *x, int k){
    return true;
}
*/

/* permutacio, bastyak
bool igeretes(int *x, int k){
    for( int i = 1 ; i < k ; ++i ){
        if( x[k] == x[i] ){ return false; }
    }
    return true;
}
*/

//n-kiralyno
bool igeretes(int *x, int k){
    for( int i = 1 ; i < k ; ++i ){
        if( x[k] == x[i] || k-i == abs(x[k]-x[i]) ){ return false; }
    }
    return true;
}

void kiir(int *x, int n){
    /*
    printf("%i: ", ++db);
    for( int i = 1 ; i <= n ; ++i ){
        printf("%i ", x[i]);
    }
    */
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= n ; ++j ){
            if( j == x[i] ){
                printf("**");
            }
            else{
                if( (i+j)%2 ){ printf("%c%c", 178, 178); }
                else { printf("%c%c", 176, 176); }
            }
        }
        printf("\n");
    }
    printf("\n\n");
}