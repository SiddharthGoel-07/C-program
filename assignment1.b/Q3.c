#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 50
#define PARA_LEN 1000

int main() {
    char paragraph[PARA_LEN];
    char words[MAX_WORDS][WORD_LEN];
    int freq[MAX_WORDS] = {0};
    int word_count = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, PARA_LEN, stdin);

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " ,.-\n\t");
    while (token != NULL) {
        // Convert word to lowercase
        for(int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

        // Check if word already exists
        int found = 0;
        for(int i = 0; i < word_count; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // If not found, add to list
        if (!found) {
            strcpy(words[word_count], token);
            freq[word_count] = 1;
            word_count++;
        }

        token = strtok(NULL, " ,.-\n\t");
    }

    // Print frequencies
    printf("\nWord frequencies:\n");
    for(int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
