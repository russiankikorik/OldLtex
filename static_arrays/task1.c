#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int i;
    int j;
    int k = 1;
    printf("Print integer ");
    scanf("%d",&n);
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%3d ",k);
            k++;
        }
        printf("\n");
    }
}