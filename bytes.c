#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 123456789;
    int b = a;
    int c;
    int i;
    void* ptr = &a;
    unsigned char buf;
    
    // вывод по байтам
    printf("hex form of 123456789\n%x\n",a);
    for (i = 0; i < 4; i++){
        buf = b & 0xFF;
        printf("byte %d is %x\n", i, buf);
        b = b >> 8;
    }
    
    // замена байта
    c = a & 0xFF00FFFF;
    c = c | 0xDD0000;
    printf("byte 2 changed to DD\n%x\n",c);
    
    // вывод через указатель для little-endian памяти
    for (i = 0; i < 4; i++){
        buf = *( (char*)ptr + i);
        printf("byte %d is %x\n", i, buf);
    }
    
    // замена байта по указателю
    *( (unsigned char*)ptr + 2) = 0xDD;
    printf("byte 2 changed to DD\n%x\n",c);
    
    
    return 0;
}
