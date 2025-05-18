#include <stdio.h>
#include <conio.h>

typedef struct node{
    int data;
    struct node *left,*right;
}Node;

Node* createNode(int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node* insert(Node* root,int data)
{
    if(root==NULL)
        return createNode(data);
    if(data < root->data)
        root->left = insert(root->left,data);
    else if(data > root->data)
        root->right = insert(root->right,data);
    return root;
}

Node* preorder(Node* root)
{
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

Node* postorder(Node* root)
{
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

Node* inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int height(Node* root)
{
    if(root==NULL)
        return 0;
    else{
        int leftheight = height(root->left);
        int rightheight = height(root->right);

        if(leftheight<rightheight)
            return (rightheight+1);
        else
            return (leftheight+1);
    }
}

int countLeafnodes(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left ==NULL && root->right ==NULL)
        return 1;
    return countLeafnodes(root->left)+countLeafnodes(root->right);
}

int countInternalnodes(Node* root)
{
    if(root==NULL || (root->left ==NULL && root->right ==NULL))
        return 0;
    else
        return 1+countInternalnodes(root->left)+countInternalnodes(root->right);
}

int countNodes(Node* root)
{
    if(root==NULL)
        return 0;
    else
        return 1+countNodes(root->left)+countNodes(root->right);
}

Node* smallest(Node* root)
{
    if(root==NULL)
    {
        printf("tree is empty");
    }
    while(root->left!= NULL)
        root = root->left;
    return root;
}

Node* max(Node* root)
{
    if(root==NULL)
    {
        printf("tree is empty");
    }
    while(root->right!=NULL)
        root = root->right;
    return root;
}

int search (Node* root,int key)
{
    if(root==NULL)
        return 0;
    if(root->data == key)
        return 1;
    if(key < root->data)
        return search(root->left, key);
    else
    {
        return search(root->left,key);
    }
}

struct Node* Delete(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = Delete(root->left, data);
    } else if (data > root->data) {
        root->right = Delete(root->right, data);
    } else {
        // Node found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One child (right)
        else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        }
        // Case 2: One child (left)
        else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else {
            struct Node* temp = smallest(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, data;

    do {
        printf("\n\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Height of Tree\n");
        printf("6. Count Total Nodes\n");
        printf("7. Count Leaf Nodes\n");
        printf("8. Count Internal Nodes\n");
        printf("9. Find Smallest Element\n");
        printf("10. Find Largest Element\n");
        printf("11. Search Element\n");
        printf("12.Delete\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Preorder: ");
            preorder(root);
            break;
        case 3:
            printf("Inorder: ");
            inorder(root);
            break;
        case 4:
            printf("Postorder: ");
            postorder(root);
            break;
        case 5:
            printf("Height of tree: %d", height(root));
            break;
        case 6:
            printf("Total nodes: %d", countNodes(root));
            break;
        case 7:
            printf("Leaf nodes: %d", countLeafnodes(root));
            break;
        case 8:
            printf("Internal nodes: %d", countInternalnodes(root));
            break;
        case 9:
            printf("Smallest element: %d", smallest(root)->data);
            break;
        case 10:
            printf("Largest element: %d", max(root)->data);
            break;
        case 11:
            printf("Enter value to search: ");
            scanf("%d", &data);
            if (search(root, data))
                printf("Element found.");
            else
                printf("Element not found.");
            break;
        case 12:
            Delete();
            break;
        case 13:
            printf("Exiting program.\n");
            break;
        }
    } while (choice != 12);

    return 0;
}
