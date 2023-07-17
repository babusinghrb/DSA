//String matching problem

#include <stdio.h>
#include <string.h>

int bruteForce(char* pattern, char* text) {
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;

    for (i = 0; i <= n-m; i++) {
        j = 0;
        while (j < m && text[i+j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }

    return -1;
}

int main() {
    char pattern[100], text[100];
    printf("Enter the text: ");
    fgets(text, 100, stdin);
    printf("Enter the pattern to search: ");
    fgets(pattern, 100, stdin);

    text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;

    int index = bruteForce(pattern, text);
    if (index != -1) {
        printf("Pattern found at index %d\n", index);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}
