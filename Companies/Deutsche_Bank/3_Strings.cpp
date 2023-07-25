// Given an array consisting of N non-negative integers. You have to find sum of consecutive numbers that was greater than or equal to the K.

#include <bits/stdc++.h>
using namespace std;

int find_shortest_substring(const string &input)
{
    unordered_set<char> target_chars;
    for (char c = 'A'; c <= 'Z'; c++)
        target_chars.insert(c);

    int left = 0, right = 0;
    unordered_set<char> current_chars;
    int shortest_length = INT_MAX;

    while (right < input.length())
    {
        current_chars.insert(input[right]);
        while (current_chars.size() == target_chars.size())
        {
            if (current_chars == target_chars)
            {
                int current_length = right - left + 1;
                shortest_length = min(shortest_length, current_length);
            }
            if (current_chars.count(input[left]) > 0)
                current_chars.erase(input[left]);
            left++;
        }
        right++;
    }
    return shortest_length;
}

int main()
{
    string input = "ABCDEFGHIDIVJKLMNOPQRSTUVWXYZOP";
    int result = find_shortest_substring(input);
    cout << "Shortest substring length: " << result << endl;

    return 0;
}
