#include <stdio.h>

int main(void) {

    FILE *in, *out;

    struct pirate {
        char name[100];
        unsigned int booty;
        unsigned int beard_len;
    };

    struct pirate s = {
        "Edward Teach",
        132213,
        12
    };

    struct pirate p;

    printf("%s,%u,%u\n", s.name, s.booty, s.beard_len);

    out = fopen("data", "w");

    if (!out) {
        perror("Error in opening data file.");
        return 1;
    }
    if (!fwrite(&s, sizeof(struct pirate), 1, out)) {
        perror("Error in writing to the data file.");
        return 1;
    }
    if (fclose(out)) {
        perror("Error in closing the data file.");
        return 1;
    }

    in = fopen("data", "r");
    if (!in) {
        perror("Error in opening data file.");
        return 1;
    }
    if (!fread(&p, sizeof(struct pirate), 1, in)) {
        perror("Error in reading data file.");
        return 1;
    }
    printf("%s,%u,%u\n", p.name, p.booty, p.beard_len);
    if (fclose(in)) {
        perror("Error in closing data file.");
        return 1;
    }
    
    return 0;
}