#include <stdio.h>

#define MAX_LEN 100

void ceaser(char message[], int shift) {

  char ch;
  for(int i = 0; message[i] ; i++) {
      ch = (message[i] + shift - 'a') % 26 + 'a';
      message[i] = ch;
  }
}

int main() {
  char message[MAX_LEN];
  int shift;

    printf("Enter message: ");
    scanf("%s", &message);
    
    printf("Enter shift: ");
    scanf("%d", &shift);
    
    
    ceaser(message, shift);
    printf("\nEncrypted message: %s", message);
    
    ceaser(message, 26 - shift);
    printf("\nDecrypted message: %s", message);

  return 0;
}

// OUTPUT
// Enter message: abc
// Enter shift: 3
// Encrypted message: def
// Decrypted message: abc
