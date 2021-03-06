/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
    Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
Example 2:
    Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Make sure the returned intervals are also sorted.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> finalIntervals;
    bool isNewIntervalPushed = false;
    int x = newInterval.start, y = newInterval.end;
    for(Interval v : intervals) {
        if(v.end < newInterval.start)
            finalIntervals.push_back(v);
        else if(v.start > newInterval.end) {
            if(!isNewIntervalPushed) {
                finalIntervals.push_back({ x, y });
                isNewIntervalPushed = true;
            }
            finalIntervals.push_back(v);
        }
        else {
            x = min(x, v.start);
            y = max(y, v.end);
        }
    }
    if(!isNewIntervalPushed)
        finalIntervals.push_back({x, y});
    return finalIntervals;
}
