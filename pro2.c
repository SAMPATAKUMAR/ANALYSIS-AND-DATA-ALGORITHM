#include <stdio.h>
int ne = 1, min_cost = 0;
void main()
{
    int n, i, j, min, cost[20][20], a, u, b, v, source, visited[20];
    printf("Enter the no. of nodes:");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("Enter the root node:");
    scanf("%d", &source);
    visited[source] = 1;
    printf("\nMinimum cost spanning tree is\n");
    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                    if (visited[i] == 0)
                        continue;
                    else
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\nEdge %d\t(%d->%d)=%d\n", ne++, a, b, min);
            min_cost = min_cost + min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost=%d\n", min_cost);
}

// Note: The code above is a C program that implements Prim's algorithm to find the minimum spanning tree of a graph represented by a cost matrix. It prompts the user for the number of nodes, the cost matrix, and the root node, then calculates and displays the edges of the minimum spanning tree along with the total minimum cost.