#include <stdio.h>

void fn() {
    printf("fn\n");
}

int main(int argc, char** argv)
{
    char buffer[10];
    void (*pfn0)(void);
    int buffer_i = 0;
    void (*pfn1)(void);

    pfn0 = fn;
    pfn1 = fn;

    while (1) {
        int c = getchar();

        if (c < 0) {
            break;
        }

        buffer[buffer_i++] = c;
    }

    buffer[buffer_i] = 0; // add terminator

    pfn0();
    printf("buffer=%s\n", buffer);
    pfn1();

    return 0;
}
