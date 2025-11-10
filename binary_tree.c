#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};
struct node* createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}
void preorder(struct node*root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
  
}
void postorder(struct node*root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(struct node*root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
       
    }
}
int main()
{
    // struct node* p;
    // p = (struct node *)malloc(sizeof(struct node));
    // p->data = 2;
    // p->left = NULL;
    // p->right  = NULL;

    // struct node*p1;
    // p1 = (struct node*)malloc(sizeof(struct node));
    // p1->data = 3;
    // p1->left = NULL;
    // p1->right = NULL;

    // struct node*p2;
    // p1 = (struct node*)malloc(sizeof(struct node));
    // p1->data = 4;
    // p1->left = NULL;
    // p1->right = NULL;

    // p->left = p1;
    // p->right = p2;
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    return 0;
}

