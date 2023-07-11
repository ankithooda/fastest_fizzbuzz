#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#define EXTRA_BUF 223
#define LOCAL_BUF BUFSIZ
// #define BUFSIZ 20


/*
We allocate a buffer of length BUFSIZ (8192) + 208.
BUFSIZ is written to STDOUT, the additional 208 to handle overflow.

*/
int main() {
    char* buf = malloc((LOCAL_BUF + EXTRA_BUF) * sizeof(char));
    int buf_count = 0;
    int byte_count;
        unsigned long i = 0;



    char* template = "%ld\n%ld\nFizz\n%ld\nBuzz\nFizz\n%ld\n%ld\nFizz\nBuzz\n%ld\nFizz\n%ld\n%ld\nFizzBuzz\n";

    while (1) {

        byte_count = sprintf(
            buf + buf_count,
            template,
            i + 1,
            i + 2,
            i + 4,
            i + 7,
            i + 8,
            i + 11,
            i + 13,
            i + 14
        );
        buf_count = buf_count + byte_count;

        // fprintf(stderr, "%d, %d\n", buf_count, byte_count);
        
        /* Handle overflow*/
        if (buf_count > LOCAL_BUF) {
            write(1, buf, LOCAL_BUF);
            memmove(buf, buf+LOCAL_BUF, LOCAL_BUF-buf_count);
            buf_count = buf_count - LOCAL_BUF;
            // write(1, buf, buf_count);
            // fprintf(stderr, "%d\n", buf_count);
        }

        i = i + 15;
    }
}
