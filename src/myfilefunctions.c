#include "../include/myfilefunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Counts lines, words, and characters in the given file stream.
// Returns 0 on success, -1 on failure.
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL || lines == NULL || words == NULL || chars == NULL) {
        return -1;
    }

    *lines = 0;
    *words = 0;
    *chars = 0;

    int c;
    int in_word = 0; // tracks whether we're currently inside a word

    while ((c = fgetc(file)) != EOF) {
        (*chars)++;

        if (c == '\n') {
            (*lines)++;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            in_word = 0; // we hit a separator, word ended
        } else if (in_word == 0) {
            in_word = 1;   // we just entered a new word
            (*words)++;
        }
    }

    return 0;
}

// Searches the file for lines containing search_str.
// Allocates an array of matching line strings into *matches.
// Returns the number of matches found, or -1 on failure.
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL || search_str == NULL || matches == NULL) {
        return -1;
    }

    char buffer[1024];
    int capacity = 10;      // initial size of matches array
    int count = 0;

    char** result = malloc(capacity * sizeof(char*));
    if (result == NULL) {
        return -1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, search_str) != NULL) {
            // grow the array if needed
            if (count >= capacity) {
                capacity *= 2;
                char** temp = realloc(result, capacity * sizeof(char*));
                if (temp == NULL) {
                    // cleanup on failure
                    for (int i = 0; i < count; i++) free(result[i]);
                    free(result);
                    return -1;
                }
                result = temp;
            }

            // strip trailing newline before storing
            int len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0';
            }

            result[count] = malloc(strlen(buffer) + 1);
            if (result[count] == NULL) {
                for (int i = 0; i < count; i++) free(result[i]);
                free(result);
                return -1;
            }
            strcpy(result[count], buffer);
            count++;
        }
    }

    *matches = result;
    return count;
}
