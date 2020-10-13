#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data        = data;
    newNode->left        = NULL;
    newNode->right       = NULL;
    return (newNode);
}

void printInorder(struct node *node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    /*
          1
       /    \
      2       3
     / \    /  \
    4  5  (-)  (-)
    */
    struct node *root = createNode(1);
    root->left        = createNode(2);
    root->right       = createNode(3);
    root->left->left  = createNode(4);
    root->left->right = createNode(5);

    printInorder(root);

    return 0;
}
