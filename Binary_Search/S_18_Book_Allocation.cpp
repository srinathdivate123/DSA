// See images in the notes word doc.
/* Given an array arr of integer numbers, ar[i] represents the number of pages in the i-th book. There are m students, and the task is to allocate all the books to the students. Allocate books in such a way that:

- Each student gets at least one book.
- Each book should be allocated to only one student.
- Book allocation should be in a contiguous manner.

You have to allocate the book to m students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1. If allocation is possible, return the maximum number of pages assigned to the student is minimum. */


// https://leetcode.com/problems/split-array-largest-sum/description/ 
#include <bits/stdc++.h>
using namespace std;

// This function tells that if nPages numbe of pages are allowed to be taken per student, then how many students at most will be able to take the 'books'.
int countStudents(vector<int> &arr, int nPages)
{
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
        if (pagesStudent + arr[i] <= nPages)
            pagesStudent += arr[i]; // add pages to current student
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    // book allocation impossible:
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}