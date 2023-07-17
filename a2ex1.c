#include <stdio.h>

int fibonacci(int n, int memo[]);

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    int memo[n+1];  // array to store previously calculated Fibonacci numbers
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;  // initialize all elements to -1
    }
    printf("The %dth Fibonacci number is %d.\n", n, fibonacci(n, memo));
    return 0;
}

int fibonacci(int n, int memo[]) {
    if (memo[n] != -1) {  // if Fibonacci number already calculated, return it
        return memo[n];
    }
    int result;
    if (n == 0 || n == 1) {
        result = n;
    } else {
        result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    }
    memo[n] = result;  // store calculated Fibonacci number in memo array
    return result;
}
