#include <stdio.h>
#include <string.h>

void encryptMsg(char msg[], int key) {
    int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0;
    char railMatrix[key][msgLen];

    for (i = 0; i < key; ++i)
        for (j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for (i = 0; i < msgLen; ++i) {
        railMatrix[row][col++] = msg[i];

        if (row == 0 || row == key - 1)
            k = k * (-1);

        row = row + k;
    }

    printf("\nEncrypted Message: ");

    for (i = 0; i < key; ++i)
        for (j = 0; j < msgLen; ++j)
            if (railMatrix[i][j] != '\n')
                printf("%c", railMatrix[i][j]);
}

void decryptMsg(char enMsg[], int key) {
    int msgLen = strlen(enMsg), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];

    for (i = 0; i < key; ++i)
        for (j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for (i = 0; i < msgLen; ++i) {
        railMatrix[row][col++] = '*';

        if (row == 0 || row == key - 1)
            k = k * (-1);

        row = row + k;
    }

    for (i = 0; i < key; ++i)
        for (j = 0; j < msgLen; ++j)
            if (railMatrix[i][j] == '*')
                railMatrix[i][j] = enMsg[m++];

    row = col = 0;
    k = -1;

    printf("\nDecrypted Message: ");

    for (i = 0; i < msgLen; ++i) {
        printf("%c", railMatrix[row][col++]);

        if (row == 0 || row == key - 1)
            k = k * (-1);

        row = row + k;
    }
}

int main() {
    char plaintext[100];
    int key, choice;

    

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the plaintext: ");
        scanf("%s", plaintext);
        printf("Enter the key: ");
        scanf("%d", &key);
        printf("Original Message: %s", plaintext);
        encryptMsg(plaintext, key);
    } else if (choice == 2) {
        char ciphertext[100];
        printf("Enter the ciphertext: ");
        scanf("%s", ciphertext);
        printf("Enter the key: ");
        scanf("%d", &key);
        printf("Encrypted Message: %s", ciphertext);
        decryptMsg(ciphertext, key);
    } else {
        printf("Invalid choice.");
    }

    return 0;
}
