// We're assuming that repetition of elements in the interArr is allowed
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

// TC is n1*n2 in worst case
// SC is n2 in worst case
void IntersectionBrute(int a[], int n1, int b[], int n2)
{
    int i = 0, j = 0, vs[n2] = {0}; // vs is visited array to store that the array number has been visited
    // We can take vs[n1] also but in tht case we'd have to run the outer for loop over the n2 array
    vector <int> interArr;

    for (int i = 0; i < n1; i++)
        for (j = 0; j < n2; j++)
        {
            if (a[i] == b[j] && vs[j] == 0)
            {
                interArr.push_back(a[i]);
                vs[j] = 1;
                break;
            }
            if (b[j] > a[i]) 
                break; // Because this is a sorted array and you can't find an element equal to it afterwards in the array if you come at an element that is greater than it.
        }

    cout << "Intersection array of brute is - " << endl;
    printArray(interArr, interArr.size());
}




// Ts in (n1+n2) in worst case
// SC is (n1 + n2) to return the answer
void IntersectionOptim(int a[], int n1, int b[], int n2)
{
    int i = 0, j = 0;
    vector<int> interArr;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            interArr.push_back(a[i]);
            i++;
            j++;
        }
    }

    cout << "Intersection array of optimal is - " << endl;
    printArray(interArr, interArr.size());
}

int main()
{
    int n1, n2;
    cout << "Enter 1st array size - ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter array - ";
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    cout << "Enter 2nd array size - ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter array - ";
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    IntersectionBrute(arr1, n1, arr2, n2);
    IntersectionOptim(arr1, n1, arr2, n2);

    return 0;
}