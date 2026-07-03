#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int v;
    int w;
    struct Node *next;
} Node;

#define INF ((long long)4e18)

bool check(int limit, int n, Node **adj, int *topo, bool *online, long long k) {
    long long *dist = (long long *)malloc(sizeof(long long) * n);

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[0] = 0;

    for (int i = 0; i < n; i++) {
        int u = topo[i];

        if (dist[u] == INF)
            continue;

        if (u != 0 && u != n - 1 && !online[u])
            continue;

        Node *cur = adj[u];

        while (cur) {
            int v = cur->v;
            int w = cur->w;

            if (w >= limit && (v == n - 1 || online[v])) {
                if (dist[v] > dist[u] + (long long)w)
                    dist[v] = dist[u] + (long long)w;
            }

            cur = cur->next;
        }
    }

    bool ok = (dist[n - 1] <= k);
    free(dist);
    return ok;
}

int findMaxPathScore(int **edges, int edgesSize, int *edgesColSize,
                     bool *online, int onlineSize, long long k) {
    int n = onlineSize;

    Node **adj = (Node **)calloc(n, sizeof(Node *));
    int *indegree = (int *)calloc(n, sizeof(int));

    int maxCost = 0;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        Node *node = (Node *)malloc(sizeof(Node));
        node->v = v;
        node->w = w;
        node->next = adj[u];
        adj[u] = node;

        indegree[v]++;

        if (w > maxCost)
            maxCost = w;
    }

    // Topological Sort (Kahn's Algorithm)
    int *queue = (int *)malloc(sizeof(int) * n);
    int *topo = (int *)malloc(sizeof(int) * n);

    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int idx = 0;

    while (front < rear) {
        int u = queue[front++];
        topo[idx++] = u;

        Node *cur = adj[u];
        while (cur) {
            indegree[cur->v]--;
            if (indegree[cur->v] == 0)
                queue[rear++] = cur->v;
            cur = cur->next;
        }
    }

    if (!check(0, n, adj, topo, online, k)) {
        for (int i = 0; i < n; i++) {
            Node *cur = adj[i];
            while (cur) {
                Node *tmp = cur;
                cur = cur->next;
                free(tmp);
            }
        }
        free(adj);
        free(indegree);
        free(queue);
        free(topo);
        return -1;
    }

    int lo = 0, hi = maxCost, ans = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (check(mid, n, adj, topo, online, k)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        Node *cur = adj[i];
        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }

    free(adj);
    free(indegree);
    free(queue);
    free(topo);

    return ans;
}