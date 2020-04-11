#include<stdio.h>
#include<stdlib.h>
/*Program that uses functions to perform the following:
a.	Create a singly linked list of integers.
b.	Delete a given integer from the above linked list.
c.	Display the contents of the above list after deletion.
*/

struct node
{
    int data;
    struct node*next;
}*head;
void create(int a[])
{
    int j=0;
    struct node*temp=(struct node*)malloc(sizeof(struct node*));
        temp->data=a[0];
        temp->next=NULL;
        head=temp;

    for(j=1;j<5;j++)
    {
        struct node*t=(struct node*)malloc(sizeof(struct node*));
        t->data=a[j];
        t->next=NULL;
        temp->next=t;
        temp=t;
    }

}
void delete(int a)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node*));
    temp=head;
    while(temp->next->data!=a)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
}
void display()
{
    struct node*p=head;
    printf("The List is:");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;

    }
}
int main()
{
    head=NULL;
    int num;
    int a[]={1,2,3,4,5};
    create(a);
    printf("Original List is:");
    display();
    printf("\nEnter the no. to be deleted");
    scanf("%d",&num);
    delete(num);
    printf("\nNew List is:");
    display();
}
