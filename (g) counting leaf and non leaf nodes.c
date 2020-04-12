#include <stdio.h>
#include <stdlib.h>
//Program to calculate leaf and non leaf nodes
struct node
            {

                int data;

                struct node *left;

                struct node *right;

            }*Node=NULL;

int * create()

{

 int x;

struct node *newnode=(struct Node*)malloc(sizeof(Node));

 printf("Enter the data for the nodes(-1 for no data)");

 scanf("%d", &x);

 if(x==-1)

 {
     return NULL;

 }

      newnode->data=x;

      printf("Enter the left child data rooted at %d \n",newnode->data);

      newnode->left=create();

      printf("Enter the right child data rooted at %d\n",newnode->data);

      newnode->right=create();

      return newnode;

}

void traverse(struct node *t)

{

    if(!t==NULL)

    {

     printf("Left child data is %d ",t->data);

       traverse(t->left);

       t=t->right;

      }



   if(!t==NULL)

      {

       printf("Right child data is %d\n",t->data);

       traverse(t->right);

      }

}

int nlcount(struct node *temp)//Function to calculate non leaf nodes
{
    if(temp)
    {
        int res=0;
        if(temp->left==NULL&&temp->right==NULL||temp==NULL)
        {
            return 0;
        }
        res=nlcount(temp->left)+nlcount(temp->right)+1;
        return res;
    }
}
int lcount(struct node *temp)//Function to calculate leaf nodes
{
    if(temp)
    {
        int res=0;
        if(temp->left==NULL&&temp->right==NULL)
        {
            return res=lcount(temp->left)+lcount(temp->right)+1;
        }
        res=lcount(temp->left)+lcount(temp->right);
        return res;
    }
}

int main()

{

struct node *root=create();

struct node *t=root;

printf("Root child is %d\n ",t->data);

traverse(t);

printf("\nThe No. of non leaf nodes are : %d",nlcount(root));

printf("\nThe No. of leaf nodes are : %d",lcount(root));

    return 0;
}
