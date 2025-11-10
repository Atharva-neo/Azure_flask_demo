#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int countnode(struct node * root)
{
   if(root == NULL)
   {
    return 0;
   }
   return 1 + countnode(root->left) + countnode(root->right);
 
}
struct node * createnode(int data)
{
    struct node* x;
    x = (struct node*)malloc(sizeof(struct node));
    x -> data = data;
    x -> left = NULL;
    x -> right = NULL;
    return x;
    
}
void insert(struct node * root, int key)
{
    struct node * prev = NULL;
    while(root != NULL)
    {
        
        if(root -> data == key)
        {
            printf("cannot insert the given node\n");
        }
        else if(root -> data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct node * ptr = createnode(key);
    
        if(key > prev -> data)
        {
            prev->right = ptr;
        }
        else 
        {
            prev -> left = ptr;
        }
    
}
struct node* inorderpredecessor(struct node* root)
{
    root = root -> left;
    while(root -> right != NULL)
    {
        root = root -> right;
    }
    return root;
}

struct node* delete_leaf_node(struct node* root, int key)
{
    struct node* inpre; 
    if(root == NULL)
    {
        printf("Deletion not possible\n");
        return NULL;
    }
    if(root->right == NULL && root->left == NULL)
    {
        printf("Leaf node found:\n");
        free(root);
    }
    if(root->data > key)
    {
        root-> left = delete_leaf_node(root->left, key);
    }
    else if(root->data < key)
    {
        root->right = delete_leaf_node(root->right, key);
    }
    else
    {
        inpre = inorderpredecessor(root);
        root->data = inpre->data;
        root-> left = delete_leaf_node(root->left, inpre->data);
    }
    return root;
}
int inorder(struct node * root, int arr[], int * index)
{    if(root != NULL)
    {
        inorder(root->left, arr, index);
        arr[(*index)++] = root->data;
        inorder(root->right, arr, index);
    }
}

int main() 
{
    int arr[100];
    int index = 0;
    struct node * p = createnode(9);
    struct node * p1 = createnode(3);
    struct node * p2 = createnode(14);
    struct node * p3 = createnode(1);
    struct node * p4 = createnode(7);
    struct node * p5 = createnode(5);
     p->left = p1;
     p->right = p2;
     p1->left = p3;
     p1->right = p4;
     p4->left = p5;
    
    int m = countnode(p);
    inorder(p ,arr, &index);
    for(int i = 0; i < m; i++)
    {
        printf("Array Elements: %d\n",arr[i]);
    }
    insert(p , 15);
    printf(" %d ",p->right->right->data);

    delete_leaf_node(p,5);
    printf("\n");
     inorder(p ,arr, &index);
    for(int i = 0; i < m; i++)
    {
        printf("Array Elements: %d\n",arr[i]);
    }

    return 0;
}