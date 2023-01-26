#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    struct tree *left;
    int info;
    struct tree *right;
} tree_type;


tree_type* create(int info)
{
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


tree_type* in_succ(tree_type *root, tree_type *node, int *succ_check)
{
    if(root!=NULL)
    {
        if(*succ_check == 1)
            printf("%d", root->info);
        if(root->info == node->info)
        {
            *succ_check = 1;
        }
        in_succ(root->left, node, succ_check);
        in_succ(root->right, node, succ_check);
    }
    return root;

}

int main()
{
    tree_type *root = NULL;
    tree_type *temp = NULL;
    int choice = 0;
    int key = 0;
    int succ_check = 0;
        
    while(1)
    {
        printf("\nMenu\n1. Insert element\n2. Delete Element\n3. Display\n4. Inorder Successor\n-1. Exit\n\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter data :");
                scanf("%d", &info);
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
                in_succ(root, root->left, &succ_check);
                break;
            case -1:
                return 0;
                break;
        }
    }
}
