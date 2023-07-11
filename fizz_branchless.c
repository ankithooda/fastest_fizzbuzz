#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#define EXTRA_BUF 30
#define BUFSIZ 20


/*
We allocate a buffer of length BUFSIZ (8192) + 208.
BUFSIZ is written to STDOUT, the additional 208 to handle overflow.

*/
int main() {

  int additional_buffer = 208;
  char* buf = malloc((BUFSIZ + EXTRA_BUF) * sizeof(char));
  int buf_count = 0;
  int byte_count;


  char* template = "%ld\n%ld\nFizz\n%ld\nBuzz\nFizz\n%ld\n%ld\nFizz\nBuzz\n%ld\nFizz\n%ld\n%ld\nFizzBuzz\n";

  unsigned long i = 0;
  byte_count = sprintf(
    buf + buf_count,
    "%ld\n%ld\nFizz\n%ld\nBuzz\nFizz\n%ld\n%ld\nFizz\nBuzz\n%ld\nFizz\n%ld\n%ld\nFizzBuzz\n",
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

  /*Replace the below two lines with write syscall.*/
  // int print_count = printf("%s", buf);
  // printf("Wrote bytes to STDOUT - %ld", print_count);

  /* Handle overflow*/
  if (buf_count > BUFSIZ) {
    write(1, buf, BUFSIZ);
    memmove(buf, buf+BUFSIZ, BUFSIZ-buf_count);
    buf_count = BUFSIZ - buf_count;
  }

  i = i + 15;
}
