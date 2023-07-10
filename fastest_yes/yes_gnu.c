#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *buf;

    buf = malloc(BUFSIZ * sizeof(char));

    for (int i = 0; i < BUFSIZ / 2; i = i + 2) {
        buf[i] = 'y';
        buf[i+1] = '\n';
    }

    while (1) {
        // fwrite(buf, BUFSIZ, 1, stdout);
        write(1, buf, 8192);
    }

    free(buf);
}