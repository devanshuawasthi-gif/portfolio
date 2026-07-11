#include <stdlib.h>
#include <stdbool.h>

void dfs(int node, int** graph, int* graphSize, bool* visited,
         int* vertexCount, int* degreeSum)
{
    visited[node] = true;
    (*vertexCount)++;
    *degreeSum += graphSize[node];

    for (int i = 0; i < graphSize[node]; i++)
    {
        int next = graph[node][i];
        if (!visited[next])
        {
            dfs(next, graph, graphSize, visited,
                vertexCount, degreeSum);
        }
    }
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize)
{
    // Allocate adjacency list
    int** graph = (int**)malloc(n * sizeof(int*));
    int* graphSize = (int*)calloc(n, sizeof(int));

    // Count degrees
    for (int i = 0; i < edgesSize; i++)
    {
        graphSize[edges[i][0]]++;
        graphSize[edges[i][1]]++;
    }

    // Allocate memory for adjacency lists
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int*)malloc(graphSize[i] * sizeof(int));
        graphSize[i] = 0;
    }

    // Build graph
    for (int i = 0; i < edgesSize; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u][graphSize[u]++] = v;
        graph[v][graphSize[v]++] = u;
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));
    int complete = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int vertexCount = 0;
            int degreeSum = 0;

            dfs(i, graph, graphSize, visited,
                &vertexCount, &degreeSum);

            int edgeCount = degreeSum / 2;
            int requiredEdges = vertexCount * (vertexCount - 1) / 2;

            if (edgeCount == requiredEdges)
                complete++;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++)
        free(graph[i]);

    free(graph);
    free(graphSize);
    free(visited);

    return complete;
}