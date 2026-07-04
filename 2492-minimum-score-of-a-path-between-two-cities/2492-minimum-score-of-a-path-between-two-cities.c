#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int city;
    int dist;
    struct Node *next;
} Node;

void dfs(int u, Node **graph, int *visited, int *ans) {
    visited[u] = 1;

    Node *curr = graph[u];
    while (curr) {
        if (curr->dist < *ans)
            *ans = curr->dist;

        if (!visited[curr->city])
            dfs(curr->city, graph, visited, ans);

        curr = curr->next;
    }
}

int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    Node **graph = (Node **)calloc(n + 1, sizeof(Node *));

    // Build adjacency list
    for (int i = 0; i < roadsSize; i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int d = roads[i][2];

        Node *node1 = (Node *)malloc(sizeof(Node));
        node1->city = v;
        node1->dist = d;
        node1->next = graph[u];
        graph[u] = node1;

        Node *node2 = (Node *)malloc(sizeof(Node));
        node2->city = u;
        node2->dist = d;
        node2->next = graph[v];
        graph[v] = node2;
    }

    int *visited = (int *)calloc(n + 1, sizeof(int));
    int ans = INT_MAX;

    dfs(1, graph, visited, &ans);

    return ans;
}