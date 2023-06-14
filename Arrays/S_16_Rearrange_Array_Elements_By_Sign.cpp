#include <bits/stdc++.h>
using namespace std;

// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.
void RearrangebySign_Variety_1(vector<int> arr)
{
    int n = arr.size(), posIndex = 0, negIndex = 1;
    vector<int> answer(n, 0); // Declaring vector with size n and all elements to be 0.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            answer[posIndex] = arr[i];
            posIndex += 2;
        }
        else
        {
            answer[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
}

// Here the number of +ve and -ve elements are not same. If any of the +ve or -ve elements are left, add them at the end without altering the order.
// The only way is to use an array to store +ve and -ve seperately. There is no more optimal for this.
// So this follow up Qn is one of the favourite for interviewer as we think that we can optimise it just like the above one, but actually we can't optimise and waste time thinking about it.
// 
void RearrangebySign_Variety_2(vector<int> arr)
{
    int n = arr.size();
    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);

    int posSize = pos.size(), negSize = neg.size(), count = 0;

    if (posSize > negSize)
    {
        // First, fill array alternatively till the point where positives and negatives ar equal in number.
        for (int i = 0; i < negSize; i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        // Fill the remaining positives at the end of the array.
        int index = negSize * 2;
        for (int i = negSize; i < posSize; i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    else
    {
        // First, fill array alternatively till the point where positives and negatives ar equal in number.
        for (int i = 0; i < pos.size(); i++)
        {

            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        // Fill the remaining negatives at the end of the array.
        int index = posSize * 2;
        for (int i = posSize; i < negSize; i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

int main()
{
    vector<int> A = {1, 2, -4, -5};
    RearrangebySign_Variety_1(A);
    cout << endl;
    vector<int> B = {-1, 2, 3, 4, -3, 1};
    RearrangebySign_Variety_2(B);

    return 0;
}