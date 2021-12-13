/*
Problem Description
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
Example:
Input:
1 2 3
4 5 6
7 8 9
Return the following:
[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
Input: 
1 2
3 4
Return the following: 
[
  [1],
  [2, 3],
  [4]
]
*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> v;

    int n = A.size();
    int startIndex = 0;
    int lastCount = -1;
    for(int i=0;i<2*n-1;i++) {
        vector<int> temp;
        if(i > n-1){
            startIndex++;
            lastCount--;
        }
        else
            lastCount++;

        int rowIndex = startIndex;
        int colIndex = i>n-1 ? n-1 : i + startIndex;    

        for(int j = 0; j <= lastCount; j++) {
            temp.push_back(A[rowIndex][colIndex]);
            rowIndex++;
            colIndex--;
        }
        v.push_back(temp);
    }
    return v;
}
