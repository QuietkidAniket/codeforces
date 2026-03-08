#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE];

// Remove duplicate characters and J
void prepareKey(char key[], char finalKey[]) {
    int used[26] = {0};
    int idx = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch < 'A' || ch > 'Z') continue;
        if (ch == 'J') ch = 'I';

        if (!used[ch - 'A']) {
            finalKey[idx++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    // Add remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!used[ch - 'A']) {
            finalKey[idx++] = ch;
        }
    }

    finalKey[idx] = '\0';
}

// Build 5×5 matrix
void buildMatrix(char key[]) {
    int idx = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = key[idx++];
}

// Find letter in matrix
void findPos(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

// Prepare plaintext into digraphs
void prepareText(char text[], char out[]) {
    int k = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = toupper(text[i]);
        if (ch < 'A' || ch > 'Z') continue;
        if (ch == 'J') ch = 'I';

        out[k++] = ch;

        // If two same letters in pair → insert X
        if (text[i+1] != '\0' && ch == toupper(text[i+1])) {
            out[k++] = 'X';
        }
    }

    // If odd length → add X at end
    if (k % 2 == 1) out[k++] = 'X';

    out[k] = '\0';
}

// Encrypt digraphs
void encrypt(char digraphs[], char out[]) {
    int k = 0;

    for (int i = 0; digraphs[i] != '\0'; i += 2) {
        char a = digraphs[i];
        char b = digraphs[i+1];

        int r1, c1, r2, c2;
        findPos(a, &r1, &c1);
        findPos(b, &r2, &c2);

        if (r1 == r2) {                         // same row
            out[k++] = matrix[r1][(c1 + 1) % SIZE];
            out[k++] = matrix[r2][(c2 + 1) % SIZE];
        }
        else if (c1 == c2) {                    // same column
            out[k++] = matrix[(r1 + 1) % SIZE][c1];
            out[k++] = matrix[(r2 + 1) % SIZE][c2];
        }
        else {                                   // rectangle rule
            out[k++] = matrix[r1][c2];
            out[k++] = matrix[r2][c1];
        }
    }

    out[k] = '\0';
}


//
int main() {
    char key[100], finalKey[30], plaintext[500], prepared[500], ciphertext[500];

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    prepareKey(key, finalKey);
    buildMatrix(finalKey);

    printf("\n5x5 Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    prepareText(plaintext, prepared);
    encrypt(prepared, ciphertext);

    printf("\nPrepared Text: %s\n", prepared);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
