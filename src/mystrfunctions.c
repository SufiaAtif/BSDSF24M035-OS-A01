#include "../include/mystrfunctions.h"
#include <stddef.h>   // <-- add this line, defines NULL
// Returns the length of the string, NOT counting the null terminator.
// Same logic as the standard strlen().
int mystrlen(const char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// Copies src into dest, including the null terminator.
// Returns the number of characters copied (not counting '\0'), or -1 on error.
int mystrcpy(char* dest, const char* src) {
    if (dest == NULL || src == NULL) {
        return -1;
    }

    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // terminate the destination string

    return i;
}

// Copies at most n characters from src into dest.
// If src is shorter than n, the rest of dest is padded with '\0' (like strncpy).
// Returns number of characters copied, or -1 on error.
int mystrncpy(char* dest, const char* src, int n) {
    if (dest == NULL || src == NULL || n < 0) {
        return -1;
    }

    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    // pad remaining space with null bytes, standard strncpy behavior
    while (i < n) {
        dest[i] = '\0';
        i++;
    }

    return i;
}

// Appends src to the end of dest. dest must have enough allocated space.
// Returns the new total length of dest, or -1 on error.
int mystrcat(char* dest, const char* src) {
    if (dest == NULL || src == NULL) {
        return -1;
    }

    int dest_len = mystrlen(dest); // find where dest currently ends
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';

    return dest_len + i;
}
