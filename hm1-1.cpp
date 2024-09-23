#include<iostream>
#include<stdio.h>
const int max = 30;

enum error{underflow,successful,overflow};
typedef struct Stack
{
    char arr[100];
    int count;
}st;


bool initi(Stack *st)
{
    st->count=0;
    return true;
}

error push(Stack *st ,char item)
{
    if (st->count>= max)
    {
        return overflow;
    }
    st->arr[st->count++]=item;
    return successful;
}

error pop(Stack *st)
{
    if(st->count<=0)
    return underflow;
    --st->count;
    return successful;
}

error top(Stack *st ,char &item)
{
    item=st->arr[st->count-1];
    return successful;
}

bool empty(Stack *st)
{
    if(st->count>0)
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    char item;
    Stack run;
    initi(&run);
    //scanf("%d",&n);
    
    while((item=getchar())!='\n')
    {
        push(&run,item);
    }

    while(!empty(&run))
    {
        top(&run,item);
        printf("%c",item);
        pop(&run);
    }

    
    return 0;
}