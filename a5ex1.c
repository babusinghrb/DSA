//Fibonacci number in the array

#include <stdio.h>

int fibonacci(int n) {
    int fib[n+1]; // Array to store the Fibonacci numbers
    int i;

    fib[0] = 0; // Base case
    fib[1] = 1; // Base case

    for (i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2]; // Recurrence relation
    }

    return fib[n]; // Return the nth Fibonacci number
}

int main() {
    int n;

    printf("Enter the index of the Fibonacci number you want to find: ");
    scanf("%d", &n);

    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));

    return 0;
}
