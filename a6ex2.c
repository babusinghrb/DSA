//Interval Scheduling Problem

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct interval {
    int start;
    int end;
} interval;

int compare(const void* a, const void* b) {
    interval* interval1 = (interval*)a;
    interval* interval2 = (interval*)b;
    return interval1->end - interval2->end;
}

void intervalScheduling(interval intervals[], int n) {
    int i, j;
    int count = 1;
    interval stack[MAX_SIZE];

    stack[0] = intervals[0];

    for (i = 1, j = 0; i < n; i++) {
        if (intervals[i].start >= stack[j].end) {
            stack[++j] = intervals[i];
            count++;
        }
    }

    printf("Max number of non-overlapping intervals = %d\n", count);
    printf("Selected intervals:\n");
    for (i = 0; i < count; i++) {
        printf("[%d, %d] ", stack[i].start, stack[i].end);
    }
}

int main() {
    int n, i;
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    interval intervals[n];

    printf("Enter the start and end times for each interval:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    qsort(intervals, n, sizeof(interval), compare);

    intervalScheduling(intervals, n);

    return 0;
}
