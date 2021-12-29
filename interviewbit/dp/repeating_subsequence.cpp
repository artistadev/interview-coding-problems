/*
Problem Description
    Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,
    i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
NOTE: Sub-sequence length should be greater than or equal to 2.
Problem Constraints
    1 <= |A| <= 100
Input Format
    The first and the only argument of input contains a string A.
Output Format
Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Example Input
Input 1:
    A = "abab"
Input 2:
    A = "abba"
Example Output
Output 1:
    1
Output 2:
    0
Example Explanation
Explanation 1:
    "ab" is repeated.
Explanation 2:
    There is no repeating subsequence.
*/


int Solution::anytwo(string A) {
    string B = A;
    int p = A.size(), q = B.size();
    int v[p+1][q+1];

    for(int i = 0; i <= p; i++) {
        for(int j = 0; j <= q; j++) {
            if(i == 0 || j == 0) {
                v[i][j] = 0;
            }
            else if(A[i-1] == B[j-1] && i != j)
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }
    return v[p][q] <= 1 ? 0 : 1;
}
