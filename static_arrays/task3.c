#include <stdio.h>
#include <stdlib.h>
#define SIZE 24

void arr_print( const int* a, int n){ 
    int i, j;
    for (i = 0; i < n; i++){
        j = 0;
        for (j; j < n; j++){
            printf("%d ", *(a+SIZE*i + j));
        }
        printf("\n");
    }
}

int main(){
    int n;
    int i, j;
    int k;
    
    int a[SIZE][SIZE];
    printf("Print integer (<=%d) ", SIZE);
    scanf("%d",&n);
    if (n > SIZE) { n = SIZE; }
    k = n - 1;
    
    for (i = 0; i < n; i++){
        j = 0;
        for (j; j < k; j++){
            a[i][j]=0;
        }
        for (j; j < n; j++){
            a[i][j]=1;
        }
        k--;
    }
    
    arr_print(a,n);
}