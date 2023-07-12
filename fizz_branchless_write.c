#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#define EXTRA_BUF 207
#define LOCAL_BUF BUFSIZ


int main() {
    /*
    We iterate infintely in steps of 15.
    Each iteration produces a string in a buffer.

    We allocate a buffer of length BUFSIZ (8192) + 207.
    BUFSIZ is written to STDOUT, the additional 207 to handle overflow.

    */
    /*
    Calculation of Extra Buffer length.

    Unsigned Long Int has the maximum value of 18446744073709551614
    which is 20 Bytes. We are printing the following strings during an interation.

    FIZZ -     4 Bytes * 5   = 20
    BUZZ -     4 Bytes * 3   = 12
    newlines - 1 Bytes * 15  = 15
    Long Int - 20 Bytes * 8  = 160

    Thus the maximum length that any iteration can produce is 207 Bytes.
    See below for detailed breakdown of the printed string.

    
    i + 1    <String Rep. of Long Int> + \n    21 Bytes
    i + 2    <String Rep. of Long Int> + \n    21 Bytes
    i + 3    Fizz + \n                          5 Bytes
    i + 4    <String Rep. of Long Int> + \n    21 Bytes
    i + 5    Fizz + \n                          5 Bytes
    i + 6    Buzz + \n                          5 Bytes
    i + 7    <String Rep. of Long Int> + \n    21 Bytes
    i + 8    <String Rep. of Long Int> + \n    21 Bytes
    i + 9    Fizz + \n                          5 Bytes
    i + 10   Buzz + \n                          5 Bytes
    i + 11   <String Rep. of Long Int> + \n    21 Bytes
    i + 12   Fizz + \n                          5 Bytes
    i + 13   <String Rep. of Long Int> + \n    21 Bytes
    i + 14   <String Rep. of Long Int> + \n    21 Bytes
    i + 15   FizzBuzz + \n                      9 Bytes

    Total - 207 Bytes
    */

    char* buf = malloc((LOCAL_BUF + EXTRA_BUF) * sizeof(char));
    int buf_count = 0;
    int byte_count;
    unsigned long i = 0;



    char* template = "%ld\n%ld\nFizz\n%ld\nBuzz\nFizz\n%ld\n%ld\nFizz\nBuzz\n%ld\nFizz\n%ld\n%ld\nFizzBuzz\n";

    while (1) {

        /* 
            Completes the template replacing %ld with the integer value.
            Copies the resulting string into the buffer location.
         */
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

        /* Advance the buffer by the length of the generated string for this iteration.*/
        buf_count = buf_count + byte_count;
        

        /* If buffer has filled up to the BUFSIZ(8192)
           Write to STDOUT.
           Copy the overflowed string to the front of the buffer
           and reset buf_count.
        */
        if (buf_count > LOCAL_BUF) {
            write(1, buf, LOCAL_BUF);
            memmove(buf, buf+LOCAL_BUF, buf_count - LOCAL_BUF);
            buf_count = buf_count - LOCAL_BUF;
        }

        i = i + 15;
    }
}
