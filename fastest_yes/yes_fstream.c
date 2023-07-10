#include <stdio.h>
#define BUF_SIZE 8192

int main() {
    // FILE *stream;
    // int close_err;
    
    // stream = fdopen(1, "w");

    static char buf[BUF_SIZE];

    setvbuf (stdout, buf, _IOFBF, BUF_SIZE);

    while(1) {
        fwrite("y\n", 2, 1, stdout);
    }
    return 0;
    
}