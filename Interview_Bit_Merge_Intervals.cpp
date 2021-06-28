//Question Link : https://www.interviewbit.com/problems/merge-intervals/
// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary)
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
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> newIntervals;
    bool flag = false, startIndexFlag = true;
    int startIndex = -1, endIndex = -1;
    if(intervals.size() == 0){ // if the set of intervals is empty
        newIntervals.push_back(newInterval);
        return newIntervals;
    }

    for(int i = 0; i < intervals.size(); i++) {//looping to determine the indxes of START and END Intervals
        if( (fmax(intervals[i].start, newInterval.start) < fmin(intervals[i].end, newInterval.end) || intervals[i].end == newInterval.start) && (startIndexFlag == true) ) {
            startIndex = i;
            startIndexFlag = false;
        }
        if((fmax(intervals[i].start, newInterval.start) < fmin(intervals[i].end, newInterval.end) || intervals[i].start == newInterval.end) && startIndex != -1) {
            endIndex = i;
            continue;
        }
    }
    bool isIntervalMerged = false;
    if(startIndex == -1) { // if startIndex is not found means there will be no overlapping
        isIntervalMerged = true;
    } else if(endIndex == -1) {//means the end interval is not found so here we consider it as same as the starting index.
        endIndex = startIndex;
    }
    for(int i = 0; i < intervals.size(); i++) {
        if(i != startIndex || isIntervalMerged == true) {
            newIntervals.push_back(intervals[i]);
            continue;
        }
        if( i == startIndex) {//if starting index is found.
            if(startIndex == endIndex){
                int start = fmin(intervals[i].start, newInterval.start );
                int end = fmax(intervals[i].end, newInterval.end);
                struct Interval mergedInterval(start, end);
                newIntervals.push_back(mergedInterval);//adding the new merged interval
                isIntervalMerged = true;//now to add all the remaing interval after the END Interval (START INTERVAL is SAME as END Interval)
            } else {
                int start = fmin(fmin(intervals[i].start, intervals[endIndex].start), newInterval.start);
                int end = fmax(fmax(intervals[i].end, intervals[endIndex].end), newInterval.end);
                struct Interval mergedInterval(start, end);
                newIntervals.push_back(mergedInterval);//adding the new merged interval
                i = endIndex;//now we will add the remaining interval after the END isInterval (START INTERVAL is NOT SAME as END INTERVAL)
                isIntervalMerged = true;
            }
        }
    }
    if(startIndex == -1) {//means the new interval is not overlapping with any of the existing intervals.
        bool placeIndex = false;
        for(int i =0; i < intervals.size(); i++) {//finding the appropriate position of the new interval.( so that it is in sorted order).
            if(newInterval.start < intervals[i].start) {
                newIntervals.insert(newIntervals.begin()+i, newInterval);
                placeIndex = true;
                break;
            }
        }
        if(!placeIndex){
            newIntervals.push_back(newInterval);
        }
    }
    return newIntervals;
}
