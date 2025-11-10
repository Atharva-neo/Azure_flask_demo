#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create_node(int data)
{
    struct node* x = (struct node*)malloc(sizeof(struct node));
    x->data = data;
    x->left = NULL;
    x->right = NULL;
    return x;
}
struct node* insert_node(struct node* root, int key)
{
    struct node* new_node = create_node(key);

        if(root == NULL)
        {
            return new_node;
        }
        if(key > root->data)
        {
           root->right = insert_node(root->right, key);
        }
        else if(key < root->data)
        {
            root->left = insert_node(root->left, key);
        }
        return root;
}
struct node* inorderpredecessor(struct node* root)
{
    if (root == NULL || root->left == NULL)
        return NULL;

    root = root->left;
    while(root->right != NULL)
    {
        root =  root->right;
    }
    return root;
}
struct node* delete_node(struct node * root, int key)
{
    struct node* inpre;
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if(root->data > key)
    {
        root->left = delete_node(root->left, key);
    }
    else if(root->data < key)
    {
        root->right = delete_node(root->right, key);
    }
    else
    {
        inpre = inorderpredecessor(root);
        if(inpre != NULL)
        {
            root->data = inpre->data;
            root->left = delete_node(root->left, inpre->data);
        }
        else
        {
            //node has no left child so replace the current node with its right child
            struct node* temp = root->right;
            free(root);
            return temp;
        }
    }
    return root;
}   


   
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    
}
int main() 
{
    struct node * p = create_node(9);
    struct node * p1 = create_node(3);
    struct node * p2 = create_node(14);
    struct node * p3 = create_node(1);
    struct node * p4 = create_node(7);
    struct node * p5 = create_node(5);
     p->left = p1;
     p->right = p2;
     p1->left = p3;
     p1->right = p4;
     p4->left = p5;
   inorder(p);
   insert_node(p,15);
   printf("\n");
   inorder(p);
   printf("\n");
   printf("%d\n",p->right->right->data);
   delete_node(p, 14);
   inorder(p);
    return 0;
}