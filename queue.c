#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * start;
struct  node * last;

struct node * createnode(int data)
{
    struct  node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

void traverse()
{
    if(start==NULL)
    {
        printf("\nNothing to print queue is empty\n");
    }
    else{
        struct node * p=start;
        while(p)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
}

void enque(int data)
{
    struct node * temp=createnode(data);
    if(start==NULL)
    {
        start=temp;
        last=temp;
    }
    else{
        struct node * p=last;
        last->next=temp;
        temp->prev=last;
        last=temp;
    }
}

int countqueue()
{
    struct node *p=start;
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

int deque()
{
    if(start==NULL)
    {
        printf("\nQueue is empty\n");
    }
    else if(start==last)
    {
        start=NULL;
        last=NULL;
    }
    else{
        start=start->next;
        start->prev->next=NULL;
        start->prev=NULL;
    }
}

int main()
{
    enque(10);
    enque(20);
    enque(30);
    enque(40);
    int x=deque();
    enque(50);
    enque(60);
    enque(70);
    enque(80);
    x=deque();
    traverse();
    printf("\n%d",countqueue());
}
