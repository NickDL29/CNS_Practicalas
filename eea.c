#include <stdio.h>

int gcdExtended(int a, int b, int *x, int *y);

void modInverse(int A, int M)
{
    int x, y, g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        printf("Inverse doesn't exist");
    else
        printf("Modular multiplicative inverse is %d", (x % M + M) % M);
}

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1, gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1, *y = x1;
    return gcd;
}

int main()
{
    int A, M;
    printf("Enter A and M: ");
    scanf("%d%d", &A, &M);
    modInverse(A, M);
    return 0;
}
