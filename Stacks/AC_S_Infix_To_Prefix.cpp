#include <iostream>
#include <stack>
#include <algorithm>
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

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    // Now we can either reverse the brackets or we can change the below conditions such the opening is closing and closing is opening.
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i];
        else if (s[i] == ')') // Bracket here is opposite of used in InfixToPostfix
            st.push(s[i]);
        else if (s[i] == '(') // Bracket here is opposite of used in InfixToPostfix
        {
            while (!st.empty() && st.top() != ')') // Bracket here is opposite of used in InfixToPostfix
            {
                res += st.top();
                st.pop();
            }
            // Below will happen when we reach the opening bracket
            if (!st.empty())
                st.pop(); // Pop the '('
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
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
     string str;
    cout << "Infix to prefix" << endl;
    cout << "Enter the expression - ";
    cin >> str;
    cout << "Result: " << infixToPrefix(str);

    return 0;
}