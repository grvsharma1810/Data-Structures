#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * prev;
    struct node * next;
};
struct node * start;

struct node * createnode(int data)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

int pop()
{
    if(start==NULL)
    {
        printf("\nSTACK UNDERFOLW\n");
        return -99999;
    }
    int data;
    data=start->data;
    if(countst()==1)
    {
        free(start);
        start=NULL;
    }
    else{
        struct node * p=start;
        start=start->prev;
        p->prev=NULL;
        p->next=NULL;
        free(p);
    }
    return data;
}
void push(int data)
{
    struct node *temp=createnode(data);
    if(start==NULL)
    {
        start=temp;
    }
    else{
        struct node * p=start;
        temp->prev=p;
        p->next=temp;
        start=temp;
    }
}
int countst()
{
    struct node *p=start;
    int count=0;
    while(p)
    {
        count++;
        p=p->prev;
    }
    return count;
}
void peek()
{
    printf("\npointer points:%d\n",start->data);
}
void traverse()
{
    struct node * p=start;
    while(p)
    {
        printf("%d|",p->data);
        p=p->prev;
    }
    countst();
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    peek();
    int x=pop();
    x=pop();
    x=pop();
    x=pop();
    x=pop();
    push(10);
    traverse();
}
