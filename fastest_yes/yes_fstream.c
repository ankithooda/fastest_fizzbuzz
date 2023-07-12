#include <stdio.h>

int main() {
    FILE *stream;

    stream = fdopen(1, "w");

    static char buf[BUFSIZ];

    setvbuf (stream, buf, _IOFBF, BUFSIZ);

    while(1) {
        fwrite("y\n", 2, 1, stream);
    }
    return 0;
    
}