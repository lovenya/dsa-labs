#include <stdio.h>
#include <stdlib.h>

void move_file_contents(const char* source_file, const char* destination_file) {
    FILE *source, *destination;
    int ch;

    source = fopen(source_file, "r");
    if (source == NULL) {
        printf("Error: Cannot open source file\n");
        return;
    }

    destination = fopen(destination_file, "w");
    if (destination == NULL) {
        printf("Error: Cannot open destination file\n");
        fclose(source);
        return;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

  
    fclose(source);
    fclose(destination);

+
    printf("Contents moved successfully from %s to %s\n", source_file, destination_file);
}

int main() {
    const char* source_file = "first.txt";
    const char* destination_file = "second.txt";
    move_file_contents(source_file, destination_file);
    return 0;
}