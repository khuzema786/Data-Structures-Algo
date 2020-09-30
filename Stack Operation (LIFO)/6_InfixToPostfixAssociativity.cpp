//         Associativity
// Symbol   Precedence  Associativity
//  + -         1          l to R
//  * /         2          l to R
//   ^          3          R to L
//   -          4          R to L
//  ( )         5          l to R

// Symbol   Out Stack Pre.  In Stack Pre.
//  + -         1               2
//  * /         3               4
//   ^          6               5
//   (          7               0
//   )          0               ? (Since closing bracket not pushed into stack)

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')')
    {
        return 0;
    }
    return 1;
}

int outPrecedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 6;
    }
    else if (x == '(')
    {
        return 7;
    }
    else if (x == ')')
    {
        return 0;
    }
    return -1;
}

int inPrecedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 5;
    }
    else if (x == '(')
    {
        return 0;
    }
    return -1;
}

char *convert(char *infix)
{
    char *postfix = new char[strlen(infix) + 1];

    stack<char> stk;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top()))
            {
                stk.push(infix[i++]);
            }
            else if (outPrecedence(infix[i]) == inPrecedence(stk.top())) // This will only happen in case of opening and closing brackets, where opening bracket will be popped out of stack
            {
                stk.pop();
            }
            else
            {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }

    while (!stk.empty() && stk.top() != ')') // To pop remaining ekements from stack and append them to the postfix expression
    {
        postfix[j++] = stk.top();
        stk.pop();
    }

    postfix[j] = '\0'; // Append null character to end of postfix string

    return postfix;
}

int main()
{

    char infix[] = "((a+b)*c)-d^e^f"; // ab+c*def^^-

    cout << convert(infix) << endl;
}