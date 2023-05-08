#include <stdio.h>
#include <string.h>
#define MAX 20

void infixtoprefix(char infix[20], char prefix[20]);

int top = -1;
char stack[MAX];

char pop()
{
	char a;
	a = stack[top];
	top--;
	return a;
}

void push(char symbol)
{
	top++;
	stack[top] = symbol;
}

int precedence(char symbol) // returns the value that helps in the precedence
{
	switch (symbol)
	{
	case '$':
	case '^':
		return 6;
		break;

	case '*':
	case '/':
		return 4;
		break;
	case '+':
	case '-':
		return 2;
		break;

	case '#':
	case '(':
	case ')':
		return 1;
		break;
	}
}

int isOperator(char symbol)
{
	switch (symbol)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '$':
	case '&':
	case '(':
	case ')':
		return 1;
		break;
	default:
		return 0;
		// returns 0 if the symbol is other than given above
	}
}

void infixtoprefix(char infix[20], char prefix[20])
{
	int i, j = 0;
	char symbol;
	stack[++top] = '#';
	strrev(infix);
	
	for (i = 0; i < strlen(infix); i++)
	{

		symbol = infix[i];

		if (isOperator(symbol) == 0)
		{
			prefix[j] = symbol;
			j++;
		}
		else
		{
			if (symbol == ')')
			{
				push(symbol);
			}
			else if (symbol == '(')
			{
				while (stack[top] != ')')
				{
					prefix[j] = pop();
					j++;
				}
				pop();
			}
			else
			{
				if (precedence(stack[top]) <= precedence(symbol))
				{
					push(symbol);
				}
				else
				{
					while (precedence(stack[top]) >= precedence(symbol))
					{
						prefix[j] = pop();
						j++;
					}
					push(symbol);
				}
				// end for else
			}
		}
		// end for else
	}
	// end for for
	while (stack[top] != '#')
	{
		prefix[j] = pop();
		j++;
	}
	prefix[j] = '\0';
}
int main()
{
	char infix[20], prefix[20], postfix[20], temp;
	printf("\nEnter infix operation: ");
	gets(infix);
	printf("\nInfix to Prefix Conversion:  ");
	infixtoprefix(infix, prefix);
	strrev(prefix);
	puts((prefix));
}