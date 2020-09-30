#include <iostream>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

int isBalanced(char *exp)
{

    // Create map
    map<char, char> mapping;
    mapping['}'] = '{';
    mapping[')'] = '(';
    mapping[']'] = '[';

    // Create map iterator
    map<char, char>::iterator itr;

    // Create stack
    stack<char> stk;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            stk.push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (stk.empty())
            {
                return false;
            }
            else
            {
                char temp = stk.top();      // returns value from top of stack eg: {
                itr = mapping.find(exp[i]); // eg: itr = mapping.find('}') -> itr -> first = '}'   itr -> second = '{'
                if (temp == itr->second)    // itr->first is key, itr->second is value
                {
                    stk.pop(); // Pops from stack
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return stk.empty() ? true : false;
}

int main()
{

    char A[] = "{([a+b]*[c-d])/e}"; // Balanced - 1
    cout << isBalanced(A) << endl;

    char B[] = "{([a+b]}*[c-d])/e}"; // Not balanced - 0
    cout << isBalanced(B) << endl;

    char C[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(C) << endl; // Not balanced - 0

    return 0;
}