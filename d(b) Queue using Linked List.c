#include <stdio.h>
#include <stdlib.h>
//Program to implement queue using linked list
struct node
{
    int data;
    struct node *next;
}*front,*rear,*temp,*front1;

int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();

int count = 0;

int main()
{
    int no, ch, e;

    printf("\n 1 - Enqueue");
    printf("\n 2 - Dequeue");
    printf("\n 3 - Front element");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Queue size");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

// Create an empty queue
void create()
{
    front = rear = NULL;
}

// Returns queue size
void queuesize()
{
    printf("\n Queue size : %d", count);
}

// Enqueuing the queue
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->next = NULL;
        rear->data = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->next = temp;
        temp->data = data;
        temp->next = NULL;

        rear = temp;
    }
    count++;
}

// Displaying the queue elements
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->data);
        front1 = front1->next;
    }
    if (front1 == rear)
        printf("%d", front1->data);
}

// Dequeuing the queue
void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\n Error: queue is empty");
        return;
    }
    else
        if (front1->next != NULL)
        {
            front1 = front1->next;
            printf("\n Dequeued value : %d", front->data);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequeued value : %d", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}

// Returns the front element of queue
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->data);
    else
        return 0;
}

// Display if queue is empty or not
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}
