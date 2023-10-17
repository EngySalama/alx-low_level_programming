i#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int append_text_to_file(const char *filename, char *text_content) {
    if (filename == NULL || text_content == NULL) {
        return -1; // Return -1 for invalid arguments
    }

    FILE *file = fopen(filename, "a"); // Open the file in append mode

    if (file == NULL) {
        return -1; // Return -1 if the file couldn't be opened
    }

    if (fputs(text_content, file) == EOF) {
        fclose(file);
        return -1; // Return -1 for a write error
    }

    fclose(file);
    return 1; // Return 1 on success
}

int main() {
    const char *filename = "example.txt";
    char *text_to_append = "This is some new content to append to the file.";

    int result = append_text_to_file(filename, text_to_append);

    if (result == 1) {
        printf("Text appended to the file successfully.\n");
    } else {
        printf("Failed to append text to the file.\n");
    }

    return 0;
}

