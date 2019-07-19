#define MAXSIZE 1000
struct stack
{
	char stk[MAXSIZE][50];
	int top;
};

typedef struct stack STACK;

STACK place={.top=0};

void pushS(char* num);
void popS(void);
int SP;

void pushS(char* num)
{
	   if (place.top == (MAXSIZE - 1))
    {
        //printf ("Stack is Full\n");
        return;
    }
	else
	{
		place.top=place.top+1;
        //printf("out of while");
		int i=0;
		while(num[i]!='\0')
		{
		   place.stk[place.top][i]=num[i];
		   i++;
           printf(" inwhile\n");
		}
        //printf(" out of while before return\n");
		place.stk[place.top][i]=num[i];

	}
	return;
}
void popS ()
{
    char* num;
    if (place.top == - 1)
    {
        printf ("Stack is Empty\n");
        
    }
    else
    {
        //num = place.stk[place.top];
        //printf ("poped element is = %sn", place.stk[place.top]);
        place.top = place.top - 1;
    }
    //return(num);
}

void display ()
{
    int i;
    if (place.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is %d \n",place.top);
        for (i = place.top; i > 0; i--)
        {
	    int j = 0;
            //printf ("%s\n", place.stk[i]);
	    for (j = 0; place.stk[i][j] != '\0'; j++)
		{
			printf ("%c\n", place.stk[i][j]);
		}
        
        }
    }
    printf ("\n");
}