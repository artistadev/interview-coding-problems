/*
Problem Description
Given an integer array A of size N.
You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.
If it exists return 1 else return 0.
NOTE:
    Do not consider the corner elements i.e A[0] and A[N-1] as the answer.
Problem Constraints
    3 <= N <= 105
    1 <= A[i] <= 109
Input Format
    First and only argument is an integer array A containing N integers.
Output Format
    Return 1 if there exist a element that is strictly greater than all the elements on left of it and strictly  smaller than all the elements on right of it else return 0.
Example Input
Input 1:
    A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
Input 2:
    A = [5, 1, 4, 4]
Example Output
Output 1:
    1
Output 2:
    0
*/

int Solution::perfectPeak(vector<int> &A) {
    vector<int> left(A.size()), right(A.size());
    int n = A.size()-1;
    left[0] = A[0];
    right[n] = A[n];
    for(int i = 1; i <= n; i++) {
        left[i] = max(A[i], left[i-1]);
        right[n-i] = min(A[n-i], right[n-i+1]);
    }
    int ans = 0;
    for(int i = 1;i < n; i++) {
        if(A[i] == left[i] && A[i] > left[i-1] && A[i] == right[i] && A[i] < right[i+1]) {
            ans = 1;
            break;
        }
    }
    return ans;
}
