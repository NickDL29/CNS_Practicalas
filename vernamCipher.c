#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* stringCipher(char* text, char* key, int isEncrypt) {
    char* cipherText = (char*)malloc(strlen(text) + 1);
    int len = strlen(key);
    int factor = isEncrypt ? 1 : -1; // set factor based on whether we're encrypting or decrypting
    for (int i = 0; text[i]; i++) {
        int c = (text[i] - 'A' + factor * (key[i % len] - 'A') + 26) % 26 + 'A';
        cipherText[i] = c;
    }
    cipherText[strlen(text)] = '\0';
    return cipherText;
}

int main() {
    char text[100], key[100], choice;
    printf("Enter the plain text: ");
    scanf("%s", text);
    printf("Enter the key: ");
    scanf("%s", key);
    printf("Do you want to encrypt or decrypt the text? (e/d) ");
    scanf(" %c", &choice);

    for (int i = 0; text[i]; i++) text[i] = toupper(text[i]);
    for (int i = 0; key[i]; i++) key[i] = toupper(key[i]);

    if (choice == 'e') {
        char* encryptedText = stringCipher(text, key, 1);
        printf("Cipher Text - %s\n", encryptedText);
        // free(encryptedText);
    } else if (choice == 'd') {
        char* decryptedText = stringCipher(text, key, 0);
        printf("Plain Text - %s\n", decryptedText);
        // free(decryptedText);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
