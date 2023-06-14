#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
                st.pop();
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty())
        ans = false;
    return ans;
}

int main()
{
    string str;
    cout << "\nBalanced Parenthesis!" << endl;
    cout << "Enter the string - ";
    cin >> str;
    if (isValid(str))
        cout << "\nValid String!";
    else
        cout << "\nInvalid String!";
    return 0;
}