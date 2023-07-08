#include <stdio.h>

int main() {
    printf("Hello World\n");
    FILE *stream;
    int close_err;
    
    stream = fdopen(1, "w");

    if (fclose(stream)) {
        perror("Error in opening STDOUT");
        return 1;
    }

    return 0;
    
}