/*
Problem Description

Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.
You need to return the length of longest palindromic subsequence in A.
NOTE:
Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.
Problem Constraints
    1 <= |A| <= 1005
Input Format
    First and only argument is an string A.
Output Format
    Return a integer denoting the length of longest palindromic subsequence in A.
Example Input
Input 1:
    A = "bebeeed"
Example Output
Output 1:
    4
Example Explanation
Explanation 1:
    The longest common pallindromic subsequence is "eeee", which has a length of 4
*/

int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());
    int p = A.size(), q = B.size();
    int v[p+1][q+1];

    for(int i = 0; i <= p; i++) {
        for(int j = 0; j <= q; j++) {
            if(i == 0 || j == 0) {
                v[i][j] = 0;
            }
            else if(A[i-1] == B[j-1])
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }
    return v[p][q];
}
