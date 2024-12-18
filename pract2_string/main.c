#include <stdio.h>

int main() {
    printf("ASCII Table (from 32 to 255):\n");
    printf("Code\tCharacter\n");
    printf("-----------------\n");

    for (int code = 32; code <= 255; code++) {
        printf("%3d\t%c\n", code, (char)code);
    }

    return 0;
}
