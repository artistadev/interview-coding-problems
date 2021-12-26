/*
Problem Description
Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.
You need to return the length of such longest common subsequence.
Problem Constraints
    1 <= |A|, |B| <= 1005
Input Format
    First argument is an string A.
    Second argument is an string B.
Output Format
    Return the length of such longest common subsequence between string A and string B.
Example Input
Input 1:
    A = "abbcdgf"
    B = "bbadcgf"
Example Output
Output 1:
    5
Example Explanation: 
Explanation 1:
    The longest common subsequence is "bbcgf", which has a length of 5
*/

int Solution::solve(string A, string B) {
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
