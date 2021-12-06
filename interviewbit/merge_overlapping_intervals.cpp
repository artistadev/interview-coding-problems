/*
Given a collection of intervals, merge all overlapping intervals.
For example:
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
Make sure the returned intervals are sorted.
*/

bool Comp(Interval A, Interval B) {
    return A.start < B.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> v;
    
    sort(A.begin(), A.end(), Comp);
    v.push_back(A[0]);

    for(int i = 1; i < A.size(); i++) {
        if(A[i].start <= v[v.size()-1].end) {
            v[v.size()-1].end = max(v[v.size()-1].end, A[i].end);
        }
        else {
            v.push_back(A[i]);
        }
    }
    return v;
}