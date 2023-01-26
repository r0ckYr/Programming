#include<stdio.h>
#include <stdlib.h>

typedef struct tree{
    int info;
    struct tree* left;
    struct tree* right;
}tree_type;

tree_type* create(int n)
{
    tree_type *p;
    p = (tree_type*)malloc(sizeof(tree_type));
    p->info = n;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(tree_type **rt,tree_type *temp)
{
    if(*rt==NULL)
    {
        *rt = temp;
    }
    else
    {
        if((temp->info)<((*rt)->info))
        {
            insert(&((*rt)->left),temp);
        }
        else if((temp->info)>((*rt)->info))
        {
            insert(&((*rt)->right),temp);
        }
    }
}

void preorder(tree_type *root)
{
    if(root!=NULL)
    {
        printf("%d,",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(tree_type *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d,",root->info);
        inorder(root->right);
    }
}

void postorder(tree_type *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d,",root->info);
    }
}

void countNodes(tree_type *r, tree_type *root,int c)
{
    if(root!=NULL)
    {
        countNodes(r, root->left,c++);
        printf("\r%d", c);
        countNodes(r, root->right,c++);
    }
}


tree_type* minValueNode(tree_type* node)
{
    tree_type *current = node;
    while(current && current->left)
        current = current->left;
    return current;
}

tree_type* deleteNode(tree_type *root, int key)
{
    if(root==NULL)
        return root;

    if(key > root->info)
        root->right = deleteNode(root->right, key);
    
    else if(key < root->info)
        root->left = deleteNode(root->left, key);

    else
    {
        if(root->right==NULL)
        {
            tree_type *temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            tree_type *temp = root->right;
            free(root);
            return temp;
        }

        tree_type *temp = minValueNode(root->right);
        root->info = temp->info;

        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}


void printEven(tree_type *root)
{
    if(root!=NULL)
    {
        printEven(root->left);
        if((root->info)%2==0)
            printf("%d,",root->info);
        printEven(root->right);
    }
}

int main()
{
    int num;
    tree_type*root = NULL, *temp;
    int opt = 0;
    do{
        printf("\n1. for insert\n2. for preorder\n3. for inorder\n4. for postorder\n5. for number of nodes\n6. for deleting a node\n7. Print even value nodes\n8. for exit.");
        printf("\nEnter the option :");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("\nEnter the element:");
                scanf("%d",&num);
                temp = create(num);
                insert(&root,temp);
                break;
            case 2:
                printf("preorder:");
                preorder(root);
                break;
            case 3:
                printf("inorder:");
                inorder(root);
                break;
            case 4:
                printf("postorder:");
                postorder(root);
                break;
            case 5:
                countNodes(root, root,0);
                break;
            case 6:
                printf("Enter element to delete :");
                scanf("%d", &num);
                root = deleteNode(root, num);
                printf("Node deleted : %d", num);
                break;
            case 7:
                printEven(root);
                break;
            case 8:
                printf("exit!");
                exit(0);
                break;
            default:
                printf("\nwrong input!");
                break;
        }   
    }while(1);
}
