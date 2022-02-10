#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 123456789;
    int i;
    unsigned char buf;
    printf("hex form of 123456789\n%x\n",a);
    
    for (i = 0; i < 4; i++){
        buf = a & 0xFF;
        printf("byte %d is %x\n", i, buf);
        a = a >> 8;
    }
    
    return 0;
}
