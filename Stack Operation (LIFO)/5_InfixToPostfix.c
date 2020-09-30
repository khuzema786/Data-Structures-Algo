// Infix to Postfix Conversion

// Left to Right If Same Precedence
// Symbol   Precedence
//  + -         1
//  * /         2
//  ( )         1

//        Associativity
// Symbol   Precedence  Associativity
//  + -         1          l to R
//  * /         2          l to R
//   ^          3          R to L
//   -          4          R to L
//  ( )         5          l to R

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    struct Node *t;
    char x = -1;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// Parenthesis Matching
int isBalanced(char *exp)
{
    int i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}
// To ge the precedence
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}
// To check whether the element is operand or operator
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}
// To convert infix expression into postfix
char *InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 1) * sizeof(char)); // len + 1 for extra null character

    while (infix[i] != '\0') // For loop cant be used because i is not always to be incremented
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop(); // Note: in this case we don't increment i
            }
        }
    }
    // To pop remaining elements currently present in stack and append it to postfix expression
    while (top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0'; // Append null character to end of postfix expression string
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    push('#');

    char *postfix = InToPost(infix);

    printf("%s ", postfix);

    return 0;
}