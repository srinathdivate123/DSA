// https://takeuforward.org/data-structure/count-reverse-pairs
// https://leetcode.com/problems/reverse-pairs/description/

// NOTE: You will not be able to invent this solution in the interview. You will have to know it beforehand

// Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
// Refer TUF for the explanation as it is long

// Time Complexity: O(2N*logN), Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).

// Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
#include <bits/stdc++.h>
using namespace std;


// This merge function is faster because it uses array and not vector
// void merge(vector<int> &nums, int low, int mid, int high)
// {
//     int *temp = new int[high - low + 1];
//     int i = low;
//     int j = mid + 1;
//     int k = 0;
//     while ((i <= mid) && (j <= high))
//     {
//         if (nums[i] < nums[j])
//         {
//             temp[k++] = nums[i++];
//         }
//         else
//         {
//             temp[k++] = nums[j++];
//         }
//     }
    
//     while (i <= mid)
//     {
//         temp[k++] = nums[i++];
//     }
//     while (j <= high)
//     {
//         temp[k++] = nums[j++];
//     }
//     int ind = 0;
//     for (int i = low; i <= high; i++)
//     {
//         nums[i] = temp[ind++];
//     }
// }

// This merge function is slower because it uses array and not vector
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr
    
    // storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else // right is smaller
        {
            temp.push_back(arr[right++]);
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2LL * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);      // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    // Call countPairs before the merge step
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high); // merging sorted halves
    return cnt;
}

int reversePairs(vector<int> arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    cout << reversePairs(arr, arr.size());
    return 0;
}