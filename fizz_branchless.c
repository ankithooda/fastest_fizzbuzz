#include <stdio.h>

int main() {
  unsigned int i = 0;

  while (1) {
    printf("%d\n%d\nFizz\n%d\nBuzz\nFizz\n%d\n%d\nFizz\nBuzz\n%d\nFizz\n%d\n%d\nFizzBuzz\n",
        i + 1,
        i + 2,
        i + 4,
        i + 7,
        i + 8,
        i + 11,
        i + 13,
        i + 14
    );

    i = i + 15;
  }
}
