// https://takeuforward.org/data-structure/postfix-to-infix

// Given a postfix expression (a string), convert it into an equivalent infix expression. The postfix expression is evaluated from left to right. The infix expression should have the proper parentheses to ensure correct operator precedence.

// Traverse the postfix expression from left to right.
// Use a stack to store operands.
// For each operator, pop the last two operands, combine them in infix order with parentheses, and push the result back.
// The final item in the stack will be the infix expression.

#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string postfix)
{
    stack<string> s; // A stack of strings
    int n = postfix.size();

    // Traverse left to right
    for (int i = 0; i < n; i++)
    {
        char c = postfix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else
        {
            // If it is an operator then pop two operands from the stack
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            // Place the operator in-between the operands and push to the stack
            s.push("(" + op1 + c + op2 + ")");
        }
    }

    // The final element in the stack is the result
    // At the end, the stack will only have one string
    return s.top();
}

int main()
{
    string postfix = "AB*C+";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}
