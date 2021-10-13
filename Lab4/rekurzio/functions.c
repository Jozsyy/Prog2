//
// Created by Jozsi on 10/13/2021.
//

#include "functions.h"

void read(FILE *f, int *a, int n){
    for(int i=0;i<n;++i){
        fscanf(f,"%i",&a[i]);
    }
}

void print(FILE *f, int *a, int n){
    for(int i=0;i<n;++i){
        fprintf(f,"%i ",a[i]);
    }
}

int sum(int *a,int n){
    int s=0;
    for(int i=0;i<n;++i){
        s+=a[i];
    }
    return s;
}

int is_in_array(int *a,int n){
    bool ok=false;
    for(int i=0;i<n;++i){
        if(a[i]==0){
            ok=true;
            break;
        }
    }
    if(ok){
        return 1;
    }
    return 0;
}

void read_rec(FILE *f, int *a, int n, int i){
    if(i<n){
        fscanf(f,"%i",&a[i]);
        read_rec(f,a,n,++i);
    }
}

void print_rec(FILE *f, int *a, int n, int i){
    if(i<n){
        fprintf(f,"%i ",a[i]);
        print_rec(f,a,n,++i);
    }
}

int sum_rec(int *a,int n,int i){
    if(i<n){
        return a[i]+ sum_rec(a,n,++i);
    }
    else{
        return 0;
    }

}

int is_in_array_rec(int *a,int n, int i){
    if(i<n){
        if(a[i]==0){ return 1;}
        return is_in_array_rec(a,n,++i);
    }
    return 0;
}

void print_digit_number(int n){
    if(n>9){
        print_digit_number(n/10);
        printf("%i ",n%10);
    }
    else{
        printf("%i ",n);
    }
}

int number_digit_number(int n){
    if(n>9){
        return number_digit_number(n/10)+1;
    }
    else{
        return 1;
    }
}

int delete_digit_number(int n){
    if(n>0) {
        if (n % 2 != 0) {
            return 10 * delete_digit_number(n / 10) + n % 10;
        } else {
            return delete_digit_number(n/10);
        }
    }
    else{
        return 0;
    }
}

int insert_digit_number(int n){
    if(n>0){
        if(n%2==0){
            return 100*insert_digit_number(n/10)+(n%10)*10+9;
        }
        else{
            return 10*insert_digit_number(n/10)+n%10;
        }
    }
    else{
        return 0;
    }
}
