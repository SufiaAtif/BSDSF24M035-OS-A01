#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");

    char buf[100];

    int len = mystrlen("Hello World");
    printf("mystrlen(\"Hello World\") = %d\n", len);

    mystrcpy(buf, "Copied Text");
    printf("mystrcpy result: %s\n", buf);

    char buf2[10];
    mystrncpy(buf2, "TruncateThis", 5);
    buf2[5] = '\0'; // ensure printable
    printf("mystrncpy (5 chars): %s\n", buf2);

    char buf3[50] = "Hello, ";
    mystrcat(buf3, "World!");
    printf("mystrcat result: %s\n", buf3);

    printf("\n--- Testing File Functions ---\n");

    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Could not open test.txt (create one to test file functions)\n");
        return 1;
    }

    int lines, words, chars;
    if (wordCount(fp, &lines, &words, &chars) == 0) {
        printf("Lines: %d, Words: %d, Chars: %d\n", lines, words, chars);
    }

    rewind(fp); // reset file pointer to reuse it for mygrep

    char** matches;
    int match_count = mygrep(fp, "test", &matches);
    printf("Found %d line(s) containing \"test\":\n", match_count);
    for (int i = 0; i < match_count; i++) {
        printf("  %s\n", matches[i]);
        free(matches[i]);
    }
    free(matches);

    fclose(fp);
    return 0;
}
