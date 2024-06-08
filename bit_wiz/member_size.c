#include <stdio.h>

#define member_size(type, member) (sizeof( ((type *)0)->member ))

typedef struct {
    float calc;
    char text[255];
    int used;
} Parent;

typedef struct {
    char flag;
    char text[member_size(Parent, text)];
    int used;
} Child;

int main() {
    printf("Size of Parent text: %lu\n", member_size(Parent, text));
    printf("Size of Child text: %lu\n", member_size(Child, text));
    printf("Size of Child: %lu\n", sizeof(Child));

    return 0;
}
