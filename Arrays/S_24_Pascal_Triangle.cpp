// In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown below:

//          1
//        1   1
//      1   2   1
//    1   3   3   1
//  1   4   6   4   1

#include <bits/stdc++.h>
using namespace std;
void Variation_2(int n);

// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
// The value of element (r,c) is r-1 C c-1 = n! / r! * (n-r!)
// To find the combination 7C2 we have:
// 7 x 6 x (5 x 4 x 3 x 2 x 1)
// __________________________
// 2 x 1 x (5 x 4 x 3 x 2 x 1)
// So here the 5 x 4 x 3 x 2 x 1 gets cancelled
// We have 7x6 / 2x1
// So the denominator (2) moves 2 places and the numerator also moves 2 places
// So we do 7/1 * 6/2
// Numerator goes in descending and denominator goes in ascending, because if we in starting only divide 7/2 then we will not get whole number, after if we divide thn somewhere we may get whole number
void Variation_1(int n, int r) // We are finding nCr
{
    long long result = 1;
    for (int i = 0; i < r; i++) // We run till r as said above
    {
        result = result * (n - i);
        result = result / (i + 1);
    }
    cout << result;
}

// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// The nth row will have n elements
// The brute will be to run a loop from 1 to n, because each row will have n elements, and for each position (row, col) call the func Variation_1(row-1, col-1) and print
// Best: See https://takeuforward.org/data-structure/program-to-generate-pascals-triangle for explanation
void Variation_2(int n)
{
    int ans = 1;
    cout << "1 ";
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
}

// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle (need not be in the 'triangle shape' )
void Variation_3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        Variation_2(i);
        cout << endl;
    }
}

int main()
{
    int row = 5, col = 4;
    Variation_1(row - 1, col - 1); // We should do r-1 C c-1

    cout << endl;
    cout << endl;

    Variation_2(5);

    cout << endl;
    cout << endl;

    Variation_3(5);
    return 0;
}