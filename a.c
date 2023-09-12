#include <stdio.h>

void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);

#define MOD 100

// Function to calculate the nth Fibonacci number using matrix exponentiation
int fib(int n)
{
    if (n == 0)
        return 0;

    int F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

// Helper function to calculate matrix multiplication
void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x % MOD;
    F[0][1] = y % MOD;
    F[1][0] = z % MOD;
    F[1][1] = w % MOD;
}

// Helper function to perform matrix exponentiation
void power(int F[2][2], int n)
{
    if (n <= 1)
        return;

    int M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

int main()
{
    int n = 3;
    int result = fib(n) % 100;
    printf("Fibonacci(%d) modulo %d = %d\n", n, 100, result);
    return 0;
}
