#include <stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int data)
{
    struct node* x;
    x = (struct node *)malloc(sizeof(struct node));
    x->data = data;
    x->left = NULL;
    x->right = NULL;
    return x;
}
// struct node* search(struct node* root, int key)
// {
//     if(root == NULL)
//     {
//         return NULL;
//     }
//     if(root->data == key)
//     {
//         return root;
//     }
//     else if(root->data >= key)
//     {
//         return search(root->left, key);
//     }
//     else{
//         return search(root->right, key);
//     }
// }
struct node* searchitr(struct node * root, int key)
{
    while(root != NULL)
    {    if(root -> data == key)
        {
            return root;
        }
        else if(root -> data > key)
        {
             root = root->left;
        }
        else 
        {
             root = root->right;
        }
       
    }
     return NULL;
}
int is_bst(struct node*root)
{   static struct node* prev = NULL;
    if(root != NULL)
    {
        if(!is_bst(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return is_bst(root->right);
    }
    else{
        return 1;
    }
}

int main() 
{
    struct node *p = createnode(10);
    struct node *p1 = createnode(7);
    struct node *p2 = createnode(14);
    struct node *p3 = createnode(3);
    struct node *p4 = createnode(8);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct node* n = searchitr(p, 14);
    if(n != NULL)
    {
        printf("Found: %d \n",n->data);
    }
    else
    {
        printf("Not found\n");
    }
 
    if(is_bst(p) == 1)
    {
        printf("BST is possible");
    }
    else
    {
        printf("BST not possible");
    }
    return 0;
}