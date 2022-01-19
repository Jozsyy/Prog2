#include <stdio.h>

int sum_rec(int *a,int n){
    if(n==0){
        return a[n];
    }
    else{
        return a[n]+sum_rec(a,n-1);
    }
}

int is_0_in_array(int *a, int n){
    if(n==0){
        if(a[n]==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(a[n]==0){
            return 1;
        }
        else{
            return is_0_in_array(a,n-1);
        }
    }
}

void print_digit(int n){
    if(n<10){
        printf("%i ",n);
    }
    else{
        print_digit(n/10);

        printf("%i ",n%10);
    }
}

int paratlan_dupla(int n){
    if(n==0){
        return 0;
    }
    else{
        if(n%2!=0){
            if(n%10*2>9){
                return paratlan_dupla(n/10)*100+n%10*2;
            }
            else{
                return paratlan_dupla(n/10)*10+n%10*2;
            }
        }
        else{
            return paratlan_dupla(n/10)*10+n%10;
        }
    }
}

int paros_torles(int n){
    if(n==0){
        return 0;
    }
    else{
        if(n%2==0){
            return paros_torles(n/10);
        }
        else{
            return paros_torles(n/10)*10+n%10;
        }
    }
}

int max_kereses(int *a,int n){
    if(n==0){
        return *a;
    }
    else{
        int maxx= max_kereses(a+1,n-1);
        if(maxx>*a){
            return maxx;
        }
        else{
            return *a;
        }
    }
}

int *maxkereses(int *a,int n){
    if(n==0){
        return a;
    }
    else{
        int *maxx= maxkereses(a+1,n-1);
        if(*maxx>*a){
            return maxx;
        }
        else{
            return a;
        }
    }
}

int binary_search(int *a, int l, int r, int x){
    if(l>r) {return -1;}
    int mid=(l+r)/2;
    if(a[mid]==x){return mid;}
    if(a[mid]>x){return binary_search(a,l,mid-1,x);}
    else{ return binary_search(a,mid+1,r,x);}

}

int power(int x,int n){
    if(n==0){
        return 1;
    }
    else{
        if(n%2==0){
            int h=power(x,n/2);
            return h*h;
        }
        else{
            int h=power(x,n/2);
            return h*h*x;
        }
    }
}

int lnko(int a,int b){
    if(a==0) { return b;}
    else{
        return lnko(b%a,a);
    }
}

int main() {
    int n=4,a[5]={2,4,5,43};
    printf("2 a 10-en:%i\n",power(2,10));
    printf("LNKO 150-25:%i", lnko(150,25));
    return 0;
}