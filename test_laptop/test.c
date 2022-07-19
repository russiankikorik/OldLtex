#include <stdio.h>

int kek(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    int j=a+b;
    h+=i;
    return j;
}

int main() {
    printf("kek\n");
    int a = kek(1, 2, 3, 4, 5, 6, 7, 8, 9);
    printf("%d\n", a);
    return 0;
}


