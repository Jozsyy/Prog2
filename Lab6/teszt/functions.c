//
// Created by Jozsi on 10/27/2021.
//

#include "functions.h"

void read_rec(FILE *f, int *a, int n, int i){
    if(i<n){
        fscanf(f,"%i",&a[i]);
        read_rec(f,a,n,++i);
    }
}

int sum_pair(int *a, int n, int i){
    if(i==n-1){
        if(i%2==0){ return a[i];}
        else{
            return 0;
        }
    }
    else{
        if(i%2==0){
            return a[i]+ sum_pair(a,n,++i);
        }
        else{
            return sum_pair(a,n,++i);
        }
    }
}

int sum_impair(int *a, int n, int i){
    if(i==n-1){
        if(i%2!=0){ return a[i];}
        else{
            return 0;
        }
    }
    else{
        if(i%2!=0){
            return a[i]+ sum_impair(a,n,++i);
        }
        else{
            return sum_impair(a,n,++i);
        }
    }
}

int binary_search(int *a, int l, int r, int n){
    int mid= (l + r) / 2;
    if(l > r){ return -1;}
    if(a[mid] == n){ return mid;}
    if(a[mid] < n){
        return binary_search(a,mid+1, r, n);
    }
    if(a[mid] > n){
        return binary_search(a, l, mid - 1, n);
    }
}

int int_cmp(const void *p1, const void *p2){
    int *q1 = (int *)p1;
    int *q2 = (int *)p2;
    if ( *q1 < *q2 ) { return -1; }
    else if ( *q1 > *q2 ) { return 1; }
    else { return 0; }
}

int maxindex(int *a,int i,int j){
    if(i==j){
        return i;
    }
    else{
        int m1= maxindex(a,i,(i+j)/2);
        int m2= maxindex(a,(i+j)/2+1,j);
        if(a[m1]>a[m2]){
            return m1;
        }
        else{
            return m2;
        }
    }
}

int power(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        if (n % 2 == 0) {
            int h = power(x, n / 2);
            return h * h;
        } else {
            int h = power(x, (n - 1) / 2);
            return h * h * x;
        }
    }
}