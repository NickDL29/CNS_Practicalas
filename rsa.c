#include <stdio.h>
#include <math.h>

int extended_euclid(int m, int b) {
    int a1 = 1, a2 = 0, a3 = m;
    int b1 = 0, b2 = 1, b3 = b;

    while(b3 != 1) {
        if(b3 == 0) {
            return -1;
        }

        int q = a3 / b3;
        int t1 = a1 - q * b1;
        int t2 = a2 - q * b2;
        int t3 = a3 % b3;
        a1 = b1; a2 = b2; a3 = b3;
        b1 = t1; b2 = t2; b3 = t3; 

        if(b3 == 1) {
            if(b2 < 0) {
                b2 = b2 % m;
            }
            return b2;
        }
    }
}

int crypt(int base, int exp, int mod) {
    int result = 1;
    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int p, q, e;
    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);
    
    printf("Enter the value of e: ");
    scanf("%d", &e);

    int n = p * q;
    int fn = (p - 1) * (q - 1);
    int d = extended_euclid(fn, e);

    int message;
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);

    long long encryption = crypt(message, e, n);
    long long decryption = crypt(encryption, d, n);

    printf("e: %d, d: %d\n", e, d);
    printf("Message:\t%d\n", message);
    printf("Encryption:\t%d\n", encryption);
    printf("Decryption:\t%d\n", decryption);

    return 0;
}
