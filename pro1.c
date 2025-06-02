// 1. Design and implement C/C++ Program to find Minimum Cost Spanning Tree of a given connected undirected graph using Kruskal's algorithm.
#include<stdio.h> // Include standard input/output header

int ne=1, min_cost=0; // Initialize edge count (ne) and minimum cost (min_cost)

void main() // Main function
{
    int n,i,j,min,a,u,b,v,cost[20][20],parent[20]; // Declare variables and arrays

    printf("Enter the no. of vertices:"); // Prompt user for number of vertices
    scanf("%d",&n); // Read number of vertices

    printf("\nEnter the cost matrix:\n"); // Prompt user to enter cost matrix
    for(i=1;i<=n;i++) // Loop through rows
        for(j=1;j<=n;j++) // Loop through columns
            scanf("%d",&cost[i][j]); // Read cost for each edge

    for(i=1;i<=n;i++) // Initialize parent array for union-find
        parent[i]=0; 

    printf("\nThe edges of spanning tree are\n"); // Print header for output

    while(ne<n) // Loop until n-1 edges are selected (spanning tree)
    {
        min=999; // Set initial minimum to a large value

        for(i=1;i<=n;i++) // Loop through all vertices
        {
            for(j=1;j<=n;j++) // Loop through all vertices
            {
                if(cost[i][j]<min) // If current edge has lower cost
                {
                    min=cost[i][j]; // Update minimum cost
                    a=u=i; // Store current vertex as a and u
                    b=v=j; // Store current vertex as b and v
                }
            }
        }

        while(parent[u]) // Find root of u (for union-find)
            u=parent[u];

        while(parent[v]) // Find root of v (for union-find)
            v=parent[v];

        if(u!=v) // If u and v are in different sets (no cycle)
        {
            printf("Edge %d\t(%d->%d)=%d\n",ne++,a,b,min); // Print selected edge
            min_cost=min_cost+min; // Add edge cost to total minimum cost
            parent[v]=u; // Union the sets
        }

        cost[a][b]=cost[b][a]=999; // Mark edge as used by setting cost to high value
    }

    printf("\nMinimum cost=%d\n",min_cost); // Print total minimum cost
}
