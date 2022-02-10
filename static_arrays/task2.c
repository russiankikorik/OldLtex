#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int a[25];
    int i;
    //int j;
    //int k = 1;
    printf("Print array size (<=25) ");
    scanf("%d",&n);
    n = (n <= 25) ? n : 25;
    printf("Print integer array ");
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for (i = n - 1; i >= 0; i--){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}