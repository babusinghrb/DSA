//Coin Changing Problem

#include <stdio.h>
#include <stdlib.h>

void coinChange(int coins[], int n, int amount) {
    int count = 0;
    printf("Coins used to make amount %d are:\n", amount);
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            printf("%d ", coins[i]);
            amount -= coins[i];
            count++;
        }
    }
    printf("\nTotal number of coins used = %d\n", count);
}

int main() {
    int n, amount;
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter the value of each coin:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount to be changed: ");
    scanf("%d", &amount);

    coinChange(coins, n, amount);

    return 0;
}
