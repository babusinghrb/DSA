//minimum cost of traversing all cities

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Number of cities
#define N 3

// Function to find the minimum edge cost excluding visited vertices
int findMin(int graph[N][N], bool visited[N], int u)
{
    int min = INT_MAX;
    for (int v = 0; v < N; v++) {
        if (graph[u][v] < min && !visited[v]) {
            min = graph[u][v];
        }
    }
    return min;
}

// Function to find the second minimum edge cost excluding visited vertices
int findSecondMin(int graph[N][N], bool visited[N], int u)
{
    int min = INT_MAX, secondMin = INT_MAX;
    for (int v = 0; v < N; v++) {
        if (graph[u][v] <= min && !visited[v]) {
            secondMin = min;
            min = graph[u][v];
        }
        else if (graph[u][v] <= secondMin && !visited[v]) {
            secondMin = graph[u][v];
        }
    }
    return secondMin;
}

// Function to find the lower bound of the current node
int bound(int graph[N][N], bool visited[N], int u)
{
    return findMin(graph, visited, u) + findSecondMin(graph, visited, u);
}

// Function to find the minimum cost of traversing all cities once
int tsp(int graph[N][N], bool visited[N], int currPos, int cost, int level, int *minCost)
{
    if (level == N) {
        if (graph[currPos][0] && cost + graph[currPos][0] < *minCost) {
            *minCost = cost + graph[currPos][0];
        }
        return 0;
    }

    int boundValue = bound(graph, visited, currPos);

    if (boundValue + cost >= *minCost) {
        return 0;
    }

    int min = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (graph[currPos][i] && !visited[i]) {
            visited[i] = true;
            int temp = tsp(graph, visited, i, cost + graph[currPos][i], level + 1, minCost);
            if (temp < min) {
                min = temp;
            }
            visited[i] = false;
        }
    }

    return min;
}

int main()
{
    int graph[N][N];

    // Getting input from user
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    bool visited[N];
    memset(visited, false, sizeof(visited));

    // Start from the first city (0)
    visited[0] = true;

    int minCost = INT_MAX;
    tsp(graph, visited, 0, 0, 1, &minCost);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}
