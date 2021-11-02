//
// Created by Jozsi on 10/27/2021.
//

#include <malloc.h>
#include "functions.h"

//osszefesules
void inter(int *a, int l, int m, int r){
    int i,j,k,*c;
    c=(int*)malloc(r * sizeof(int));
    i=l;
    j=m+1;
    k=1;
    while(i<=m && j <= r){
        if(a[i]<a[j]){ c[k++]=a[i++];}
        else{ c[k++]=a[j++];}
    }
    while(i<=m){ c[k++]=a[i++];}
    while(j<=r){ c[k++]=a[j++];}
    k=1;
    for(i=l; i <= r; ++i){
        a[i]=c[k++];
    }
}

///Merge sort (Osszefesuleses rendezes)
void msort(int *a, int l, int r)
{
    int m;
    if(l < r)
    {
        m= (l + r) / 2;
        msort(a, l, m);
        msort(a,m+1, r);
        inter(a, l, m, r);
    }
}



int poz(int *a, int l, int r){
    int i,j,di,dj,aux;
    i=l; j=r; di=0; dj=1;
    while(i<j)
    {
        if(a[i]>a[j])
        {
            aux=a[i]; a[i]=a[j]; a[j]=aux;
            di=1-di; dj=1-dj;
        }
        i=i+di;
        j=j-dj;
    }
    return j;
}

///Quick sort (Gyors rendezes)
void QS(int *a, int l, int r)
{
    int p;
    if(l < r)
    {
        p=poz(a, l, r);
        QS(a, l, p - 1);
        QS(a,p+1, r);
    }
}


