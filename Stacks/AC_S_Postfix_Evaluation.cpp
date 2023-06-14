#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
int postfixEval(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // If u minus the ASCII value of '0' from any string, then you get is integer ASCII value.
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string str;
    cout << "\nEnter string to el=valuate the postfix - ";
    cin >> str;
    cout << "\nResult = " << postfixEval(str);
    return 0;
}