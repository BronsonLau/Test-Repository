#include<stdio.h>
#include<string.h>
#define max 50;
char ch1[100];
int flag1=0,flag2=0;  //一定要赋值0，避免什么都没有的情况
typedef struct stack
{
    char arr[max];
    int count;
}st;

bool init(stack *st)
{
    st->count=0;
}

void push(stack *st,char item)
{
    st->arr[st->count++]=item;
}

// item1
char pop(stack *st)
{
    return st->arr[st->count--];
}

char gettop(stack *st ,char item)
{
    item=st->arr[st->count];
    return item;
}

int main()
{
    stack run;
    scanf("%s",ch1);
    int l=strlen(ch1);

    for(int i=0;i<l;i++)
    {
        push(&run,ch1[i]);
        if (ch1[i]=='(')
        {
            flag1=1;
        }
        if (ch1[i]==')' && flag1==1)
        {
            while(pop(&run)!='(')
            {
                // if( run.arr[run.count+1]=='[')
                // {
                //     flag1=1;
                //     printf("1");
                //     return 0;
                //     break;
                    
                // }
                if(run.arr[run.count]=='(')
                {
                    flag1=0;
                    break;
                }
                
            }
            
        }
        if (ch1[i]=='[')
        {
            flag2=1;
        }
         
        if (ch1[i]==']' && flag2==1)
        {
            while(pop(&run)!='[')
            {
                // if( run.arr[run.count+1]=='(')
                // {
                //     flag2=1;
                //     printf("1");
                //     return 0;
                //     break;
                    
                // }
                if(run.arr[run.count]=='[')
                {
                    flag2=0;
                    break;
                }
                
            }
            
        }
    }

    for(int i=0;i<run.count;i++)     //检查剩下的有没有括号的半边
    {
        if(run.arr[i]=='(' || run.arr[i]==')' ||run.arr[i]=='[' || run.arr[i]==']')
        {
            printf("1");
            return 0;
        }
    }
    if(flag1==0 && flag2 ==0)
    {
        printf("0");
    }
    else 
    {
        printf("1");
    }
    return 0;
}