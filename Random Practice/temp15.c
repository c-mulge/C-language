#include<stdio.h>
#include<stdlib.h>

#define maxsz 50

void bst(int tree[], int values[], int n);
void inorderTraversal(int tree[], int index);

int main() {
    int i, n;
    int values[maxsz];
    int tree[maxsz];

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Initialize the tree
    for (i = 0; i < maxsz; i++) {
        tree[i] = -1; // Initialize all elements to -1 (indicating empty node)
    }

    // Build the binary search tree
    bst(tree, values, n);

    // Print the in-order traversal of the BST
    printf("In-order traversal of the Binary Search Tree:\n");
    inorderTraversal(tree, 0);

    return 0;
}

// Function to build the binary search tree
void bst(int tree[], int values[], int n) {
    int i, p;
    tree[0] = values[0];
    
    for (i = 1; i < n; i++) {
        p = 0;
        while (1) {
            if (tree[p] <= values[i]) {
                if ((2 * p + 2) < maxsz && tree[2 * p + 2] == -1) {
                    tree[2 * p + 2] = values[i];
                    break;
                } else {
                    if ((2 * p + 2) < maxsz)
                        p = 2 * p + 2;
                    else {
                        printf("Array size exceeded!\n");
                        exit(1);
                    }
                }
            } else {
                if ((2 * p + 1) < maxsz && tree[2 * p + 1] == -1) {
                    tree[2 * p + 1] = values[i];
                    break;
                } else {
                    if ((2 * p + 1) < maxsz)
                        p = 2 * p + 1;
                    else {
                        printf("Array size exceeded!\n");
                        exit(1);
                    }
                }
            }
        }
    }
}

// Function to perform in-order traversal of the binary search tree
void inorderTraversal(int tree[], int index) {
    if (tree[index] != -1) {
        inorderTraversal(tree, 2 * index + 1); // Traverse left subtree
        printf("%d ", tree[index]); // Print current node
        inorderTraversal(tree, 2 * index + 2); // Traverse right subtree
    }
}
