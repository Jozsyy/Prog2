#include <stdio.h>

void readwrite(const char* filename,int,int,int**);

int main() {
    int **a,n,m;
    readwrite("be.txt",n,m,a);
    return 0;
}

void readwrite(const char* filename,int n,int m,int** a){
    int *f=fopen(filename,"rt");
    if(!f){
        printf("Cannot open %s",filename);
        return;
    }
    fscanf(f,"%i%i",&n,&m);
    a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;++i){
        a[i]=(int*)malloc(m*sizeof(int));
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            fscanf(f,"%i",&a[i][j]);
        }
    }
    fclose(f);
    for(int i=0;i<n;++i){
        if(i%2!=0){
            for(int j=m-1;j>=0;--j){
                printf("%i ",a[i][j]);
            }
        }
        else{
            for(int j=0;j<m;++j){
                printf("%i ",a[i][j]);
            }
        }
        printf("\n");
    }

}
