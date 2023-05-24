#include <stdio.h>
#include <string.h>

void railfence(char msg[], int key) {
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
    int key;

        printf("Enter the plaintext: ");
        scanf("%s", plaintext);
        printf("Enter the key: ");
        scanf("%d", &key);
        printf("Original Message: %s", plaintext);
        railfence(plaintext, key);
    return 0;
}

// OUTPUT
// Enter the plaintext: meetme
// Enter the key: 2
// Original Message: meetme
// Encrypted Message: memete
// Decrypted Message: meetme
