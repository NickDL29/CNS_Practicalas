#include <stdio.h>
#include <string.h>

void vernam(const char* plaintext, const char* key, char* ciphertext) {
    int len = strlen(plaintext);
    int i;
    for (i = 0; i < len; i++) {
        int encryptedChar = ((plaintext[i] - 'A') ^ (key[i] - 'A')) % 26;
        ciphertext[i] = encryptedChar + 'A';
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    vernam(plaintext, key, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);
    
    vernam(ciphertext, key, plaintext);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
