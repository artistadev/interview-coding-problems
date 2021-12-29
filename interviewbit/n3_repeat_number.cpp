/*
Problem Description
    You're given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
    If so, return the integer. If not, return -1.
    If there are multiple solutions, return any one.
Example:
Input: 
    [1 2 3 1 1]
Output: 
    1 
1 occurs 3 times which is more than 5/3 times.
*/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int occurance = A.size()/3;
    int count1 = 0, count2 = 0;
    int firstMax = INT_MAX, secMax = INT_MAX;

    for(int i = 0; i < A.size(); i++) {
        if(A[i] == firstMax)
            count1++;
        else if(A[i] == secMax)
            count2++;
        else if(count1 == 0) {
            firstMax = A[i];
            count1++;
        }
        else if(count2 == 0) {
            secMax = A[i];
            count2++;
        }
        else {
            count2--;
            count1--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(int i = 0; i < A.size(); i++) {
        if(firstMax == A[i])
            count1++;
        if(secMax == A[i])
            count2++;
    }

    if(count1 > occurance)
        return firstMax;
    if(count2 > occurance)
        return secMax;

    return -1; 
}
