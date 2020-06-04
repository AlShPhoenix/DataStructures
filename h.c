#include<stdio.h>
#include<stdlib.h>
//tree node structure
struct node
{
    int a;
    struct node *left,*right;
};
struct node* newnode(int data)
{
  struct node* temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->a=data;
  temp->left=0;
  temp->right=0;
  return temp;
}
//insertion in binary search tree
struct node* create(struct node* root, int item)
{
    if(root==0)
        return newnode(item);
    else if(item<root->a)
    {
        root->left=create(root->left,item);
    }
     else if(item>root->a)
    {
        root->right=create(root->right,item);
    }
}
int h(struct node* root)
{
    if(root==NULL)
        return 0;
    else{
        int ldepth=h(root->left);
        int rdepth=h(root->right);
        if(ldepth>rdepth)
            return ldepth;
        else
            return rdepth;
    }
}
void inorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
        inorder(root->left);
        printf("%d ",root->a);
        inorder(root->right);
}
void main()
{
    struct node *root;
    root=0;
    root=create(root,10);
    create(root,90);
    create(root,60);
    create(root,40);
    create(root,30);
    create(root,50);
    create(root,70);
    create(root,80);
    create(root,100);
    create(root,20);
    printf("height is %d",h(root)+1);
    printf("\n");
    printf("inorder is : ");
    inorder(root);
}
