#include <bits/stdc++.h>
using namespace std;
// Given an array, find the element that appears MORE than n/2 times, where n is array length
// Better is to use hashMap and store the number of times each element occours
// TC = N*log(N) {to add elements to map} + N {to traverse map} because time complexity of ordered map is log(N). If we use unordered_map we can reduce this to N*(1) in best & avg case.
// SC = N to store all elements in worst case
void better()
{
}

// When we start & count=0, then we allot the first array element to 'element'.
// In the next itertions, if elements we encounter are equal to the 'element' then we do count++ which means that the 'element' is the largest in the array till now
// If we get elements that are not equal to 'element' then we do count-- which means that the 'element' is not the majority so far.
// While doing this count++ & count-- if count becomes 0 then we again initialize 'element' with arr[i];
// At the end of iteration, the 'element' variable will store the element that appears maximum number of times. The count variable is not of any significance at the end of loop.
// TC = N if it is stated that "there is a majority element in the array"
// TC = N + N if it is not guaranteed that there will be a majority element in the array
void moores_Voting_Algorithm(int arr[], int n)
{
    int count = 0, element;
    for (int i = 0; i < n; i++)
        if (count == 0)
        {
            element = arr[i];
            count = 1;
        }
        else if (arr[i] == element)
            count++;
        else
            count--;
    

    // If it is stated that there will definitely be a majority element in the array, then we don't need to do the below part. We can just print 'element' then!
    int no_of_times_max_element_occours_in_array = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == element)
            no_of_times_max_element_occours_in_array++;
    if (no_of_times_max_element_occours_in_array > n / 2)
        cout << element;
}

int main()
{
    int arr[] = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    moores_Voting_Algorithm(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}