/*
Given an integer array A of size N.
You can pick B elements from either left or right end of the array A to get maximum sum.
Find and return this maximum possible sum.
NOTE: Suppose B = 4 and array A contains 10 elements then
You can pick first four elements or can pick last four elements or can pick 1 from front and 3 from back etc . you need to return the maximum possible sum of elements you can pick.
*/
int Solution::solve(vector<int> &A, int B)
{
    int maxPossibleSum = 0;
    for (int i = 0; i < B; i++)
    {
        maxPossibleSum += A[i];
    }
    int k = B - 1;
    int maxSum = maxPossibleSum;

    for (int j = A.size() - 1; j > A.size() - B - 1; j--)
    {
        maxSum = maxSum + A[j] - A[k];
        maxPossibleSum = max(maxPossibleSum, maxSum);
        k--;
    }
    return maxPossibleSum;
}
