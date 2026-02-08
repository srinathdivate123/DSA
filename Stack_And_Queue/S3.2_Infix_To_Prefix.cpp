// https://takeuforward.org/data-structure/infix-to-prefix

// Reverse the expression
// Swap the '(' and ')'
// Convert the expression to postfix expression under some controlled conditions (check the conditions below lol)
// Reverse the expression

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
    // If the character is neither alphabetic nor numeric, it's an operator
}

// Function to return the precedence of operators
int getPriority(char C)
{
    if (C == '-' || C == '+') // Addition and subtraction have lowest precedence
        return 1;
    else if (C == '*' || C == '/') // Multiplication and division have higher precedence
        return 2;
    else if (C == '^') // Exponent operator has highest precedence
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')'; // Add parentheses to handle edge cases
    int l = infix.size();
    stack<char> st; // Stack to store operators
    string output;  // String to store the resulting postfix expression

    for (int i = 0; i < l; i++)
    {
        // If it is an operand, add it to output
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        // If it is ‘(’, push it to the stack
        else if (infix[i] == '(')
            st.push('(');

        // If it is ‘)’, pop the output from the stack until an ‘(‘ is encountered
        else if (infix[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop(); // Remove '(' from the stack
        }

        // If an operator is found
        else
        {
            // Check if st.top() has an operator or not
            if (isOperator(st.top()))
            {
                if (infix[i] == '^')
                {
                    while (!st.empty() && getPriority(infix[i]) <= getPriority(st.top()))
                    {
                        output += st.top();
                        st.pop();
                    }
                }
                else
                {
                    while (!st.empty() && getPriority(infix[i]) < getPriority(st.top()))
                    {
                        output += st.top();
                        st.pop();
                    }
                }
                // Push current operator on stack
                st.push(infix[i]);
            }
        }
    }

    // Pop all remaining elements from the stack
    while (!st.empty())
    {
        output += st.top();
        st.pop();
    }
    return output;
}

string infixToPrefix(string infix)
{
    int l = infix.size();
    reverse(infix.begin(), infix.end());

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < l; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string s = "(p+q)*(c-d)";
    cout << endl;
    cout << infixToPrefix(s) << endl;
    return 0;
}