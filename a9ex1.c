//Randomized Select

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(&arr[random], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

int randomized_select(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = partition(arr, low, high);
    int length = pivot - low + 1;

    if (k == length) {
        return arr[pivot];
    } else if (k < length) {
        return randomized_select(arr, low, pivot-1, k);
    } else {
        return randomized_select(arr, pivot+1, high, k-length);
    }
}

int main() {
    int n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int kth_smallest = randomized_select(arr, 0, n-1, k);
    printf("The %dth smallest element is %d\n", k, kth_smallest);

    return 0;
}
