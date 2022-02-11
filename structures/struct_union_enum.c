#include <stdio.h>

struct test1{
    char a;
    int b;
};

struct test2{
    char a;
    int b;
} __attribute__((packed));

union test3{
    unsigned char a;
    int b;
};

enum colors {RED, GREEN=10, BLUE};

int main()
{
    char a[10] = {'A', 0, 0, 0, 0, 'B', 0, 0, 0, 0};
    struct test1* t1=&a;
    struct test2* t2=&a;
    printf("simple %c %d\n", t1->a, t1->b);
    printf("attr packed %c %d\n", t2->a, t2->b);
    
    int b = 0xff0f;
    union test3* t3=&b;
    printf("union %x %x\n", t3->a, t3->b);
    
    enum colors cr, cg, cb;
    cr = RED;
    cg = GREEN;
    cb = BLUE;
    
    printf("RED %d\n", cr);
    printf("GREEN %d\n", cg);
    printf("BLUE %d\n", cb);
    
    return 0;
}
