#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void vigenere(char* message, char* key, char* result, int encrypt) {
    int m_len = strlen(message);
    int k_len = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < m_len; i++, j++) {
        if (j == k_len) {
            j = 0;
        }
        int m = message[i] - 'a';
        int k = key[j] - 'a';
        int r = (m + (encrypt ? k : -k) + 26) % 26;
        result[i] = r + 'a';
    }
    result[i] = '\0';
}

int main() {
    char message[MAX_LEN];
    char key[MAX_LEN];
    char ciphertext[MAX_LEN];
    char decrypted[MAX_LEN];

    printf("Do you want to encrypt or decrypt? (e/d): ");
    char choice;
    scanf("%c", &choice);
    getchar();

    printf("Enter message: ");
    fgets(message, MAX_LEN, stdin);

    printf("Enter key: ");
    fgets(key, MAX_LEN, stdin);

    // Remove newline character from inputs
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    if (choice == 'e') {
        vigenere(message, key, ciphertext, 1);
        printf("Encrypted message: %s\n", ciphertext);
    } else if (choice == 'd') {
        vigenere(message, key, decrypted, 0);
        printf("Decrypted message: %s\n", decrypted);
    } else {
        printf("Invalid choice. Please choose 'e' or 'd'.\n");
        return 1;
    }

    return 0;
}
