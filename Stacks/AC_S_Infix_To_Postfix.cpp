#include <iostream>
#include <stack>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1; // Not an operator. This happens when we get a '(' or ')'
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            // Below will happen when we reach the opening bracket.
            if (!st.empty())
                st.pop(); // Pop the ')'
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]); // To push the current operator to stack.
        }
    }
    while (!st.empty()) // To check if any element is still left in stack.
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    string str;
    cout << "Infix to postfix" << endl;
    cout << "Enter the expression - ";
    cin >> str;
    cout << "Result: " << infixToPostfix(str);

    return 0;
}