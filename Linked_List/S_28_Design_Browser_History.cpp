/*

You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

-   BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
-   void visit (string url) visits url from the current page. It clears up all the forward history.
-   string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
-   string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

-   Your BrowserHistory object will be instantiated and called as such:
    ->   BrowserHistory* obj = new BrowserHistory(homepage);
    ->   obj->visit(url);
    ->   string param_2 = obj->back(steps);
    ->   string param_3 = obj->forward(steps);
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *back;
    Node() : data(0), next(nullptr), back(nullptr) {};
    Node(string x) : data(x), next(nullptr), back(nullptr) {};
    Node(string x, Node *next, Node *back) : data(x), next(next), back(back) {};
};

class BrowserHistory
{
    Node *currentPage;

public:
    BrowserHistory(string &homepage)
    {
        currentPage = new Node(homepage);
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        currentPage->next = newNode;
        newNode->back = currentPage;
        currentPage = newNode;
    }

    string back(int steps)
    {
        while (steps--)
        {
            if (currentPage->back)
                currentPage = currentPage->back;
            else
                break;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        while (steps--)
        {
            if (currentPage->next)
                currentPage = currentPage->next;
            else
                break;
        }
        return currentPage->data;
    }
};

int main()
{
    // The above code was accepted on LeetCode so no need to test it
    return 0;
}