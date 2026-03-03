// TC is o(n1 + n2), sum of size of the arrays
// SC is (n1 + n2) (in worst case if all elements in both arrays are unique) to return the answer

#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr, int n);
void printArray(vector<int> &arr, int n)
{
    cout << "Printing array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

void Union(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0; // Two pointer approach
    vector<int> unionArr;

    while (i < n1 && j < n2)
        if (arr1[i] <= arr2[j]) // We always want to insert the smallest element because we want the unionArr to be a sorted one.
        {
            if (unionArr.size() == 0 || unionArr.back() != arr1[i]) // We take arr1[i] only if the last element in the unionArr is not equal to it, in order to avoid repetition in unionArr. Also for the first element being inserted in it, there wouldn't be any unionArr.back, so we just take it when the unionArr is empty.
                unionArr.push_back(arr1[i]);
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != arr2[j])
                unionArr.push_back(arr2[j]);
            j++;
        }

    // Only any one of the below loops wil run because the above loop will quit when i=n1 or when j=n2
    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr1[i])
            unionArr.push_back(arr1[i]);
        i++;
    }
    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr2[j])
            unionArr.push_back(arr2[j]);
        j++;
    };
    cout << "Union array is - " << endl;
    printArray(unionArr, unionArr.size());
}

int main()
{
    int arr1[] = {1, 1, 2, 3, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {4, 4, 5, 6, 6, 6, 7, 8, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Union(arr1, n1, arr2, n2);
    return 0;
}