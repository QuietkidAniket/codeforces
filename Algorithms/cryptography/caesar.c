#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char text[], int key){
  for (int i = 0; text[i] != '\0'; i++) {
    char ch = text[i];

    if (islower(ch)) {
        ch = (ch - 'a' + key) % 26 + 'a';
    }
    else if (isupper(ch)) {
        ch = (ch - 'A' + key) % 26 + 'A';
    }
    else if (isdigit(ch)) {
        ch = (ch - '0' + key) % 10 + '0';
    }
    else {
        // SYMBOLS → leave unchanged
    }

    text[i] = ch;
  }
}

void decrypt(char text[], int key) {
  for (int i = 0; text[i] != '\0'; i++) {
    char ch = text[i];

    if (islower(ch)) {
        ch = (ch - 'a' - key + 26) % 26 + 'a';
    }
    else if (isupper(ch)) {
        ch = (ch - 'A' - key + 26) % 26 + 'A';
    }
    else if (isdigit(ch)) {
        ch = (ch - '0' - key + 10) % 10 + '0';
    }
    else {
        // SYMBOLS → unchanged
    }

    text[i] = ch;
  }
}

int main() {
    char text[500];
    int key, option;

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key: ");
    scanf("%d", &key);

    printf("1. Encrypt\n2. Decrypt\nChoose: ");
    scanf("%d", &option);

    if (option == 1) {
        encrypt(text, key);
        printf("Encrypted message: %s\n", text);
    }
    else if (option == 2) {
        decrypt(text, key);
        printf("Decrypted message: %s\n", text);
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}
