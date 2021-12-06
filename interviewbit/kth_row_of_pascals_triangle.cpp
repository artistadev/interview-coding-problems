/*
Problem Description
Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.
Example:
    Input : k = 3
Return : 
    [1,3,3,1]
Note: k is 0 based. k = 0, corresponds to the row [1]. 
Note: Could you optimize your algorithm to use only O(k) extra space?
*/

vector<int> Solution::getRow(int A) {
    vector<int> v;
    v.push_back(1);
    if(A == 0)
        return v;
    int counter = 1;
    while(1) {
        vector<int> temp;
        temp.push_back(1);
        for(int i=1;i < v.size();i++) {
            temp.push_back(v[i] + v[i-1]);
        }
        temp.push_back(1);
        if(counter == A)
            return temp;
        v = temp;
        counter++;
    }
}
