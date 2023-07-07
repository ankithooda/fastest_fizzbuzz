#include <stdio.h>

int print_with_no_lines() {
    printf("H");
    printf("e");
    printf("l");
    printf("l");
    printf("o");    
}
int print_with_1_line() {
    printf("H");
    printf("e");
    printf("l\n");
    printf("l");
    printf("o");    
}

int print_loop() {
    int i = 0;
    while (i < pow(2, 11)) {
        printf("H");
        if (i == 400 || i == 800) {printf("X");}
        i++;
    }
}

int main() {
    print_loop();
}