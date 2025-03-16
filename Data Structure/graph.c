// // Graph- arr implementation

// #include <stdio.h>
// #define maxsz 50
// int main()
// {
//     int g[maxsz][maxsz];
//     int n;
//     printf("Enter size: ");
//     scanf("%d", &n);
//     printf("Enter %d number: \n", n);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &g[i][j]);
//         }
//     }

//     int count;
//     printf("Out degree: \n");
//     for (int i = 0; i < n; i++)
//     {
//         count = 0;
//         for (int j = 0; j < n; j++)
//             // if(g[i][j]!=0)
//             count += g[i][j];
//         printf("%d: %d \n", i, count);
//         printf("\n");
//     }

//     printf("In degree: \n");
//     for (int i = 0; i < n; i++)
//     {
//         count = 0;
//         for (int j = 0; j < n; j++)
//             // if(g[j][i]!=0)
//             count += g[j][i];
//         printf("%d: %d \n", i, count);
//         printf("\n");
//     }
//     return 0;
// }

#include <stdio.h>
#define maxsz 50
void outdegree(int g[maxsz][maxsz], int n)
{
    int sum;
    int i, j;
    printf("Outdegree: \n");
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            sum += g[i][j];
        }
        printf("%d: %d\n", i, sum);
    }
}

void indegree(int g[maxsz][maxsz], int n)
{
    int sum;
    int i, j;
    printf("Indegree: \n");
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            sum += g[j][i];
        }
        printf("%d: %d\n", i, sum);
    }
}

void total(int g[maxsz][maxsz], int n)
{
    int sum;
    int i, j;
    printf("Total degree: \n");
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            sum += g[i][j];
            sum += g[j][i];
        }
        printf("%d: %d\n", i, sum);
    }
    // printf("Total degree: %d\n", sum);
}

int main()
{
    int g[maxsz][maxsz];
    int i, j;
    int n;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("enter the matrices: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    outdegree(g, n);
    indegree(g, n);
    total(g, n);
    return 0;
}