/*
Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.

NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: 
for this problem, following are some good questions to ask :

Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

Input Format
    First argument is an array of digits.
Output Format
    Return the array of digits after adding one.
Example Input
Input 1:
    [1, 2, 3]
Example Output
Output 1:
    [1, 2, 4]
Example Explanation
Explanation 1:
Given vector is [1, 2, 3].
The returned vector should be [1, 2, 4] as 123 + 1 = 124.
*/

vector<int> Solution::plusOne(vector<int> &A)
{
    int carry = 1;
    int firstPositiveIndex = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > 0)
        {
            firstPositiveIndex = i;
            break;
        }
    }

    vector<int> newArr;
    if (firstPositiveIndex == -1)
    {
        newArr.push_back(1);
        return newArr;
    }

    for (int i = A.size() - 1; i >= firstPositiveIndex; i--)
    {
        int temp = A[i] + carry;
        if (temp == 10)
        {
            A[i] = 0;
            carry = 1;
        }
        else
        {
            A[i] = temp;
            carry = 0;
            break;
        }
    }

    if (carry == 1)
        newArr.push_back(carry);
    for (int i = firstPositiveIndex; i < A.size(); i++)
    {
        newArr.push_back(A[i]);
    }
    return newArr;
}
