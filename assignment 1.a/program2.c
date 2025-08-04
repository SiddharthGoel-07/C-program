#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int length, i;

    fgets(str, sizeof(str), stdin);

    length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }

    for (i = length - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    putchar('\n');

    return 0;
}
