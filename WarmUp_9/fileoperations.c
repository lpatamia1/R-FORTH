#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* filename = "example.txt";

    // Writing to file
    FILE* fw = fopen(filename, "w");
    if (fw == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        return 1;
    }

    fprintf(fw, "Hello, World!");
    fclose(fw);

    // Reading from file
    FILE* fr = fopen(filename, "r");
    if (fr == NULL) {
        fprintf(stderr, "Error opening file for reading\n");
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fr) != NULL) {
        printf("%s", buffer);
    }

    fclose(fr);

    return 0;
}
