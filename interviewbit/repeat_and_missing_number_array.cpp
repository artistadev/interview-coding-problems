/*
You are given a read only array of n integers from 1 to n.
Each integer appears exactly once except A which appears twice and B which is missing.
Return A and B
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Note that in your output A should precede B.
Example:
Input:
    [3 1 2 5 3] 
Output:
    [3, 4] 
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size();
    long long int sum = n*(n+1)/2, squareSum = n*(n+1)*(2*n+1)/6;
    long long int actualSum = 0, actualSquareSum = 0;

    for(int i = 0; i < n; i++) {
        actualSum += (long long int)A[i];
        actualSquareSum += (long long int)A[i]*(long long int)A[i];
    }

    long long int b = ((actualSquareSum - squareSum)/(actualSum - sum) - (actualSum - sum))/2;
    long long int a = actualSum - sum + b;
    
    return vector<int>{ a, b };
}
