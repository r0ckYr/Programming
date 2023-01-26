#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    struct tree *left;
    int info;
    struct tree *right;
} tree_type;


//for level ordered traversal
typedef struct node{
    int info;
    struct node *next;
}node;


node* enqueue(node *rear, int info)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    p->next = NULL;
    p->info = info;

    rear->next = p;
    rear = p;
    return rear;
}

node* dequeue(node *front)
{
    if(front == NULL)
    {
        printf("\nUnderflow\n");
        return front;
    }
    front = front->next;
    return front;
}

void dispalyQueue(node *front)
{
    while(front)
    {
        printf("%d", front->info);
        front = front->next;
    }

}

//for level ordered traversal


tree_type* create()
{
    int info = 0;
    printf("\nEnter data :");
    scanf("%d", &info);
    tree_type *temp = (tree_type*)malloc(sizeof(tree_type));
    temp->left = NULL;
    temp->right = NULL;
    temp->info = info;
    return temp;
}

tree_type* insert(tree_type **root, tree_type* temp)
{
    if(*root==NULL)
    {
        *(root) = temp;
    }
    else if((*root)->info > temp->info)
    {
        insert(&(*root)->left, temp);
    }
    else if((*root)->info < temp->info)
    {
        insert(&(*root)->right, temp);
    }
    return *root;

}

tree_type* minValueNode(tree_type *root)
{
    tree_type *current = root;
    while(current->left)
    {
        current = current->left;
    }
    return current;
}

tree_type* delete(tree_type *root, int key)
{
    if(root==NULL)
        return root;
    else if(key > root->info)
        root->right = delete(root->right, key);
    else if(key < root->info)
        root->left = delete(root->left, key);

    else
    {
        if(root->right==NULL)
        {
            tree_type* temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left == NULL)
        {
            tree_type* temp = root->right;
            free(root);
            return temp;
        }

        tree_type *temp = minValueNode(root->right);
        root->info = temp->info;
        root->right = delete(root->right, temp->info);
    }
    return root;
}

void display(tree_type **root)
{
    if(*root!=NULL)
    {
        display(&(*root)->left);
        printf("%d ", (*root)->info);
        display(&(*root)->right);
    }
}


void printLevelOrdered(tree_type *root)
{
    node *front = NULL;
    node *rear = NULL;
    if(root == NULL)
        return;
    else
    {

    }
}


int main()
{
    tree_type *root = NULL;
    tree_type *temp = NULL;
    int choice = 0;
    int key = 0;
    while(1)
    {
        printf("\nMenu\n1. Insert element\n2. Delete Element\n3. Display\n4. Print Level Ordered\n-1. Exit\n\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                temp = create();
                root = insert(&root, temp);
                break;
            case 2:
                printf("Enter key to delete :");
                scanf("%d", &key);
                root = delete(root, key);
                break;
            case 3:
                display(&root);
                break;
            case 4:
                printLevelOrdered(root);
                break;
            case 5:
                break;
            case -1:
                return 0;
                break;
        }
    }
}
