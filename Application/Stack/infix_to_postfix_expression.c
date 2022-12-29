/*
-------------
- Algorithm -
-------------

Scan the symbols of the expression from left to right and for each symbol do the
following:
    a) if symbol is operand 
        print that symbol on the screen
    b) if symbol is left paranthesis 
        push it on the stack
    c) if the symbol is right parenthesis 
        pop all the operator from the stack upto the first left parenthesis and store
        them in the postfix array.
        discard the left and right parenthesis
    d) If symbol is operator 
        if the precendence of the operator in the stack are greater than or equal to the
        current operator then,
            Pop the operators out of stack and print onto the screen and push the current
            operator onto the stack
        else
            push the current operator onto the stack

    Evaluation (Calculation):
        Scan the expression from left to right for each symbol do the following:
            a)If the symbol is operand 
                Push it on the stack
            b) if the symbol is operator 
                Pop two symbols from the stack and apply operator on those symbol
                push result on the stack
            c) After scanning all the symbols of the of the postfix expression, pop
            the remaining symbol from the stack and print it on the screen. The 
            remaining symbol is the result obtained after evaluating the postfix opeartion


    ASCII Code:
    '0' = 48
    '1' = 49
    '2' = 50
    '3' = 51
    '4' = 52
    '5' = 53
    '6' = 54
    '7' = 55
    '8' = 56
    '9' = 57
*/



#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;


void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();

		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}


int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;

	push('(');
	strcat(infix_exp,")");

	i=0;
	j=0;
	item=infix_exp[i];

	while(item != '\0')
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if(is_operator(item) == 1)
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
			push(x);
			push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i];
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0';

}

int main()
{
	char infix[SIZE], postfix[SIZE];
	printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
	gets(infix);

	InfixToPostfix(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);

	return 0;
}