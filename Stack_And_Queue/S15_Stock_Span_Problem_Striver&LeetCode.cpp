// https://takeuforward.org/data-structure/stock-span-problem
// https://leetcode.com/problems/online-stock-span/description

// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

// For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
// Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
// Implement the StockSpanner class:

// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is 'price'.

// The brute force is, for each element, traverse beckward to find the previous day with a stock price less than or equal to the curernt day's price. Then store the calculated stock span for each day in the array

// OPTIMAL: Previous Greater Element

// Initialize an empty stack to maintain elements in decreasing order
// Traverse through the given stock prices array
// For each element, pop elements from the stack until the current price is greater than the price at the top of the stack
// If the stack is not empty, the index at the top of the stack is the previous greater element
// Calculate the stock span as the difference between the current index and the index of the previous greater element
// If the stack is empty, the current stock price is the largest so far, and the span is the current index + 1
// Push the current index onto the stack
// After completing the traversal, return the array of stock spans

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int ind = -1;
    StockSpanner()
    {
        ind = -1;
    }

    vector<int> findPGE(vector<int> arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int currEle = arr[i];
            while (!st.empty() && arr[st.top()] <= currEle)
            {
                st.pop();
            }

            // If the greater element is not found, stack will be empty
            if (st.empty())
                ans[i] = -1;
            // Else store the answer
            else
                ans[i] = st.top();
            // Push the current index in the stack
            st.push(i);
        }
        return ans;
    }

    int next(int price)
    {
        ind++;
        while (!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        int ans;
        if (st.empty())
        {
            ans = ind + 1;
        }
        else
        {
            ans = ind - st.top().second;
        }
        st.push({price, ind});
        return ans;
    }
};

int main()
{
}