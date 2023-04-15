#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void encrypt(char *plaintext, int key);
void decrypt(char *ciphertext, int key);

int main() {
    char input[MAX_LEN];
    int key;
    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LEN, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);
    encrypt(input, key);
    printf("Encrypted string: %s\n", input);
    decrypt(input, key);
    printf("Decrypted string: %s\n", input);
    return 0;
}

void encrypt(char *plaintext, int key) {
    int len = strlen(plaintext);
    char ciphertext[MAX_LEN];
    int rows = (len + key - 1) / key;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            int index = i + j * rows;
            if (index < len) {
                ciphertext[i * key + j] = plaintext[index];
            } else {
                ciphertext[i * key + j] = ' ';
            }
        }
    }
    strcpy(plaintext, ciphertext);
}

void decrypt(char *ciphertext, int key) {
    int len = strlen(ciphertext);
    char plaintext[MAX_LEN];
    int rows = (len + key - 1) / key;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            int index = i * key + j;
            if (index < len) {
                plaintext[i + j * rows] = ciphertext[index];
            }
        }
    }
    strcpy(ciphertext, plaintext);
}