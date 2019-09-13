#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*start;

int countlinks()
{
    int count=0;
    struct node *p=start;
    while(p)
    {
        p=p->next;
        count++;
    }
    return count;
}

void reverse()
{
    if(countlinks()==1)
    {
        return;
    }
    int len=1;
    int clink=countlinks();
    struct node *p,*q,*r;
    while(clink!=len)
    {
        p=start;
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        q=p->next;
        if(len==1)
        {
            r=q;
        }
        q->next=p;
        p->next=NULL;
        len++;
    }
    start=r;
}
void createfirstnode(int n)
{
    start =(struct node *)malloc(sizeof(struct node));
    start->data=n;
    start->next=NULL;
}
void traverse()
{
    struct node *p=start;
    while(p)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("\n%d\n",countlinks());
}

void createnextnode(int n)
{
    struct node *p=start;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;

    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=temp;
}
void insertfirst(int n)
{
    struct node * temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else{
        temp->next=start;
        start=temp;
    }
}

void insertinbetween(int n,int loc)
{
    if(start==NULL && loc==1)
    {
        insertfirst(n);
    }
    else if(loc==countlinks()+1)
    {
        createnextnode(n);
    }
    else{
        int count=2;
        struct node * temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=n;
        temp->next=NULL;
        struct node *p=start;
        while(count!=loc)
        {
            p=p->next;
            count++;
        }
        temp->next=p->next;
        p->next=temp;
    }
}
int search(int data)
{
    int index=0;
    struct node * p=start;
    while(p)
    {
        if(p->data==data)
        {
            return index;
        }
        index++;
        p=p->next;
    }
    return -99999;
}

int delete(int index)
{
    int len=1;
    int data;
    if(index==0)
    {
        data=start->data;
        start=start->next;
    }
    else{
        struct node * p=start;
        while(len!=index)
        {
            p=p->next;
            len++;
        }
        data=p->next->data;
        p->next=p->next->next;
    }
    return data;
}
int findatatindex(int index)
{
    if(index<countlinks())
    {
        int len=0;
        struct node * p=start;
        while(p)
        {
            if(index==len)
            {
                return p->data;
            }
            len++;
            p=p->next;
        }
    }
    return -99999;
}

void deleteall()
{
    if(start=NULL)
    {
        printf("Linklist is empty!\n");
    }
    else{
        struct node * p=start;
        struct node * q=start;
        int i=2;
        for(i;i<countlinks();i++)
        {
            p=p->next;
            if(p->next->next=NULL)
            {
                free(p->next);
                p->next=NULL;
                p=start;
            }
        }
        free(p);
        free(start);
    }
}
int main()
{
    deleteall();
    printf("LENGTH OF LINKLIST:%d",countlinks());
    createfirstnode(10);
    createnextnode(20);
    createnextnode(30);
    createnextnode(40);
    createnextnode(50);
    insertfirst(0);
    insertinbetween(5,2);
    insertinbetween(35,6);
    insertinbetween(100,9);
    traverse();
    int x=delete(0);
    traverse();
    x=delete(6);
    traverse();
    x=delete(6);
    traverse();
    printf("FOUND ELEMENT AT:%d INDEX OF LINKLIST\n",search(30));
    printf("FOUND %d AT INDEX OF LINKLIST\n",findatatindex(3));
    deleteall();
    traverse();
    createfirstnode(10);
    createnextnode(20);
    createnextnode(30);
    createnextnode(40);
    createnextnode(50);
    traverse();
    reverse();
    traverse();
}
