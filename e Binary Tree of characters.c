#include<stdio.h>
#include<stdlib.h>
/*Program that uses functions to:-
a.	Create a binary search tree of characters.
b.	Traverse the above Binary search tree recursively in Postorder, Inorder and Preorder
*/
struct node
{
    char data;
    struct node *left;
    struct node *right;
};

/* newNode() allocates a new node with the given data and NULL left and
   right pointers. */
struct node* newNode(char data)
{
  // Allocate memory for new node
  struct node* node = (struct node*)malloc(sizeof(struct node));

  // Assign data to this node
  node->data = data;

  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void Inorder(struct node *t)

{

    if(t)

    {

    Inorder(t->left);

    printf(" %c",t->data);

    Inorder(t->right);

    }

}

void Preorder(struct node *t)

{

    if(t)

    {
    printf(" %c",t->data);

    Preorder(t->left);

    Preorder(t->right);

    }

}

void Postorder(struct node *t)

{

    if(t)

    {

    Postorder(t->left);

    Postorder(t->right);

    printf(" %c",t->data);

    }

}

int main()
{
  /*create root*/
  struct node *root = newNode('a');

  root->left        = newNode('b');

  root->right       = newNode('c');

  root->left->left  = newNode('d');

  root->left->right  = newNode('e');

  root->right->left  = newNode('f');

  root->right->right  = newNode('g');

Inorder(root);

printf(" is the Inorder traversal \n\n" );

Preorder(root);

printf(" is the Preorder traversal \n\n" );

Postorder(root);

printf(" is the Postorder traversal \n\n" );

  return 0;
}
