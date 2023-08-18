#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Stack{
	char arr[MAX_SIZE];
	int top;
}Stack;

int precedence(char ch){
	switch (ch) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}

bool isOperator(char ch){
	return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^');
}

char* convert(char* infix)
{
	int i, j;
	int len = strlen(infix);
	char* postfix=(char*)malloc(sizeof(char)*(len+1));
	Stack stack;
	stack.top=-1;

	for (i=0,j=0;i<len;i++) {
		if(infix[i]==' ')
			continue;
		
		if(isalnum(infix[i])) {
			postfix[j++] = infix[i];
		}
		
		else if (infix[i]=='(') {
			stack.arr[++stack.top]=infix[i];
		}
		
		else if (infix[i]==')') {
			while (stack.top>-1 && stack.arr[stack.top]!='(')
				postfix[j++]=stack.arr[stack.top--];
			if (stack.top>-1 && stack.arr[stack.top]!='(')
				return "Invalid Expression";
			else{
				stack.top--;
			}
		}
		
		else if(isOperator(infix[i])) {
			while ((stack.top>-1) && (precedence(stack.arr[stack.top])>= precedence(infix[i]))){
				postfix[j++]=stack.arr[stack.top--];
			}
			stack.arr[++stack.top]=infix[i];
		}
	}

	
	while (stack.top > -1) {
		if (stack.arr[stack.top] == '(') {
			return("Invalid Expression");
		}
		postfix[j++] = stack.arr[stack.top--];
	}
	postfix[j] = '\0';
	return postfix;
}


int main(){
	printf("Enter the expression(Eg:a+b*(c^d-e)^(f+g*h)-i):\n");
	char infix[100];
	scanf("%s",infix);

	char* postfix = convert(infix);
	printf("\nPostix:");
	printf("%s\n", postfix);
	return 0;
}











