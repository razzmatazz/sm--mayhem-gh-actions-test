#include <stdio.h>

void fn() {
    printf("fn\n");
}

int main(int argc, char** argv)
{
    volatile void (*pfn0)(void);
    char buffer[10];
    volatile void (*pfn1)(void);
    int buffer_i = 0;
    volatile void (*pfn2)(void);

    pfn0 = fn;
    pfn1 = fn;
    pfn2 = fn;

    pfn0();
    pfn1();
    pfn2();

    while (1) {
        int c = getchar();

        if (c < 0) {
            break;
        }

        buffer[buffer_i++] = c;
    }

    buffer[buffer_i] = 0; // add terminator

    pfn0();
    pfn1();
    pfn2();

    printf("buffer=%s\n", buffer);

    pfn0();
    pfn1();
    pfn2();

    return 0;
}
