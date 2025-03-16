// take adjcency matrix as input and convert it into list
#include <stdio.h>
#include <stdlib.h>
#define maxsz 50

struct edge
{
    int ver;
    struct edge *next;
};
struct edge *getnode(int value)
{
    struct edge *temp = (struct edge *)malloc(sizeof(struct edge));
    temp->ver = value;
    temp->next = NULL;
    return temp;
}

void addedge(struct edge *G[], int v1, int v2, int n)
{
    struct edge *p = NULL;
    if (G[v1] == 0)
    {
        G[v1] = getnode(v2);
        return;
    }
    p = G[v1];
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = getnode(v2);
}

void display(struct edge *G[], int n)
{
    struct edge *p = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        p = G[i];
        printf("%d : ", i);
        while (p != 0)
        {
            printf("%d ", p->ver);
            p = p->next;
        }
        printf("\n");
    }
}

void out(struct edge *G[], int n)
{
    struct edge *temp;
    int i, sum;
    printf("Outdegree: \n");
    for (i = 0; i < n; i++)
    {
        temp = G[i];
        sum = 0;
        while (temp)
        {
            sum = sum + 1;
            temp = temp->next;
        }
        printf("%d: %d\n", i, sum);
    }
}

int main()
{
    // int g[maxsz][maxsz];
    struct edge *G[maxsz] = {0}; // You defined G with size 10, but it's better to use maxsz
    int m, n, i, v1, v2;         // Changed i to v1 and v2
    printf("How many ver: ");
    scanf("%d", &m);
    printf("How many edges: ");
    scanf("%d", &n);
    printf("Enter the edges: ");
    for (i = 1; i <= n; i++) // Changed loop index to i
    {
        scanf("%d %d", &v1, &v2); // Read vertices of the edge
        addedge(G, v1, v2, m);    // Pass vertices to addedge function
        addedge(G, v2, v1, m);    // undirected graph
    }
    printf("Display: \n");
    display(G, m); // Pass number of vertices to display function
    printf("\n");
    // out(G, n);
    return 0;
}

// #include <stdio.h>

// #define MAX_VERTICES 100

// int main()
// {
//     int vertices, edges;
//     int G[MAX_VERTICES][MAX_VERTICES] = {0};

//     printf("Enter the number of vertices: ");
//     scanf("%d", &vertices);

//     printf("Enter the number of edges: ");
//     scanf("%d", &edges);

//     printf("Enter the edges (format: vertex1 vertex2):\n");
//     for (int i = 0; i < edges; i++)
//     {
//         int vertex1, vertex2;
//         scanf("%d %d", &vertex1, &vertex2);
//         // Assuming vertices are 0-indexed
//         G[vertex1][vertex2] = 1;
//         G[vertex2][vertex1] = 1; // Assuming undirected graph
//     }

//     printf("Adjacency Matrix:\n");
//     for (int i = 0; i < vertices; ++i)
//     {
//         for (int j = 0; j < vertices; ++j)
//         {
//             printf("%d ", G[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }
