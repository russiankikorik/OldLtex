#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 123456789;
    int b = a;
    int c;
    int i;
    unsigned char buf;
    
    printf("hex form of 123456789\n%x\n",a);
    
    for (i = 0; i < 4; i++){
        buf = b & 0xFF;
        printf("byte %d is %x\n", i, buf);
        b = b >> 8;
    }
    
    c = a & 0xFF00FFFF;
    c = c | 0xDD0000;
    printf("byte 2 changed to DD\n%x\n",c);
    
    return 0;
}
