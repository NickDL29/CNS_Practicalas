#include <stdio.h>

#define MAX_LEN 100

void encrypt(char message[], int shift);
void decrypt(char message[], int shift);

int main() {
  char message[MAX_LEN];
  int shift;
  char operation;

  printf("Enter message: ");
  fgets(message, MAX_LEN, stdin);

  printf("Enter shift: ");
  scanf("%d", &shift);

  printf("Enter operation (e for encrypt, d for decrypt): ");
  scanf(" %c", &operation);

  switch(operation) {
    case 'e':
      encrypt(message, shift);
      printf("Encrypted message: %s\n", message);
      break;
    case 'd':
      decrypt(message, shift);
      printf("Decrypted message: %s\n", message);
      break;
    default:
      printf("Invalid operation\n");
      break;
  }

  return 0;
}

void encrypt(char message[], int shift) {
  int i;
  char ch;

  for(i = 0; message[i] != '\0'; i++) {
    ch = message[i];

    if(ch >= 'a' && ch <= 'z') {
      ch = (ch + shift - 'a') % 26 + 'a';
    }
    else if(ch >= 'A' && ch <= 'Z') {
      ch = (ch + shift - 'A') % 26 + 'A';
    }

    message[i] = ch;
  }
}

void decrypt(char message[], int shift) {
  encrypt(message, 26 - shift);
}
