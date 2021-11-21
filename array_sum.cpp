/*
You are given two numbers represented as integer arrays A and B, where each digit is an element.
You have to return an array which representing the sum of the two given numbers.
The last element denotes the least significant bit, and the first element denotes the most significant bit.
Problem Constraints
    1 <= |A|, |B| <= 105
    0 <= Ai, Bi <= 9
Input Format
    The first argument is an integer array A. The second argument is an integer array B.
Output Format
    Return an array denoting the sum of the two numbers.
Example Input
Input 1:
A = [1, 2, 3]
B = [2, 5, 5]

Input 2:
A = [9, 9, 1]
B = [1, 2, 1]

Example Output
Output 1:
[3, 7, 8]

Output 2:
[1, 1, 1, 2]

Example Explanation
Explanation 1:
Simply, add all the digits in their place.
Explanation 2:

991 + 121 = 1112
Note that the resultant array size might be larger.
*/

vector<int> Solution::addArrays(vector<int> &A, vector<int> &B)
{
    int m = A.size() - 1;
    int n = B.size() - 1;
    vector<int> minArray, maxArray, v;
    int p, q;
    if (m > n)
    {
        p = m;
        q = n;
        minArray = B;
        maxArray = A;
    }
    else
    {
        p = n;
        q = m;
        minArray = A;
        maxArray = B;
    }

    int carry = 0;
    while (q >= 0)
    {
        int digitSum = minArray[q] + maxArray[p] + carry;
        v.push_back(digitSum % 10);
        carry = digitSum / 10;
        p--;
        q--;
    }

    while (p >= 0)
    {
        int digitSum = maxArray[p] + carry;
        v.push_back(digitSum % 10);
        carry = digitSum / 10;
        p--;
    }

    if (carry == 1)
        v.push_back(1);

    reverse(v.begin(), v.end());

    return v;
}
