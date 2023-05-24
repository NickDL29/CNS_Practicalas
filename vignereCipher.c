#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void vignere(char* message, char* key, char* result, int factor)
{
    int m_len = strlen(message);
    int k_len = strlen(key);
    int i, j;
    for (i = 0, j = 0; i < m_len; i++, j++)
    {
        if (j == k_len)
        {
            j = 0;
        }
        int m = message[i] - 'a';
        int k = key[j] - 'a';
        int r = (m + (factor ? k : -k) + 26) % 26;
        result[i] = r + 'a';
    }
    result[i] = '\0';
}

int main()
{
    char message[MAX_LEN], key[MAX_LEN], cipher[MAX_LEN], decrypted[MAX_LEN];

    printf("Enter the Messsage:");
    scanf("%s", &message);

    printf("Enter the Key:");
    scanf("%s", &key);

    // message[strcspn(message, "\n")] = '\0';
    // key[strcspn(key, "\n")] = '\0';

    vignere(message, key, cipher, 1);
    printf("\nThe CipherText is: %s", cipher);

    vignere(cipher, key, decrypted, 0);
    printf("\nThe CipherText is: %s", decrypted);

    return 0;
}
