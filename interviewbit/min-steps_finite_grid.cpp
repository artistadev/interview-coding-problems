/*
You are in an infinite 2D grid where you can move in any of the 8 directions
    (x,y) to 
    (x-1, y-1), 
    (x-1, y)  , 
    (x-1, y+1), 
    (x  , y-1),
    (x  , y+1), 
    (x+1, y-1), 
    (x+1, y)  , 
    (x+1, y+1) 
You are given a sequence of points and the order in which you need to cover the points.. 
Give the minimum number of steps in which you can achieve it. 
You start from the first point.

Example Input
Input 1:
    A = [0, 1, 1]
    B = [0, 1, 2]
Example Output
Output 1:
    2
*/

int Solution::coverPoints(vector<int> &A, vector<int> &B)
{
    int totalDistance = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        int distance = max(abs(A[i + 1] - A[i]), abs(B[i + 1] - B[i]));
        totalDistance += distance;
    }
    return totalDistance;
}
