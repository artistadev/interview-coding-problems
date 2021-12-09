/*
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.
Input Format:
    The first and the only argument contains an integer, A.
Output Format:
    Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:
    1 <= A <= 1000
Examples:
Input 1:
    A = 3
Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]
Input 2:
    4
Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ]
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> v;
    if(A == 0)
        return v;
    vector<int> emptyVector = vector<int>(A, 0);
    for(int i = 0;i < A;i++) {
        v.push_back(emptyVector);
    }

    int initRow = 0, lastRow = A-1, initCol = 0, lastCol = A-1;
    int counter = 1;
    while(initRow <= lastRow && initCol <= lastCol) {
        for(int i = initCol; i <= lastCol; i++) {
            v[initRow][i] = counter++;
        }
        initRow++;
        for(int i = initRow;i <= lastRow;i++) {
            v[i][lastCol] = counter++;
        }
        lastCol--;
        for(int i = lastCol;i>=initCol; i--) {
            v[lastRow][i] = counter++;
        }
        lastRow--;
        for(int i = lastRow; i>= initRow;i--) {
            v[i][initCol] = counter++;
        }
        initCol++;
    }
    return v;
}
