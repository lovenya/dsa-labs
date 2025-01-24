#include <stdio.h>

int main() {
    printf("Hello, World!\n");

    FILE *fp = fopen(__FILE__, "r");
    if (fp) {
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    }
    else {
        printf("Error opening file!\n");
    }
    return 0;
}


