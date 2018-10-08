#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long n;
long *nums;

void crearArreglo();
void filtrarPrimos();
void imprimirArreglo();

int main(){
    clock_t start, end;
    double cpu_time_used;
    scanf("%ld",&n);
    start=clock();
    crearArreglo();
    filtrarPrimos();
    imprimirArreglo();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTiempo CPU: %lf segs.\n",cpu_time_used);
    return 0;
}
void crearArreglo(){
    long i=0;
    nums=(long*) calloc(n,sizeof(long));
    for(;i<n;i++)
        nums[i]=i+1;
    return;
}

void filtrarPrimos(){
    long i=1;
    long j;
    nums[0]=-1;
    for(;i<sqrt(n);i++)
        for(j=i+1;nums[i]!=-1 && j<n;j++)
            if(nums[j]%nums[i]==0)
                nums[j]=-1;
    return;
}

void imprimirArreglo(){
    long i=0;
    for(;i<n;i++)
        if(nums[i]!=-1)
            printf("%ld ",nums[i]);
    return;
}
