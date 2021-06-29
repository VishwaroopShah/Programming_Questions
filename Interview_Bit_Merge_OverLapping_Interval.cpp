//Question : https://www.interviewbit.com/problems/merge-overlapping-intervals/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool customComparator( Interval first, Interval second){
     if(first.start < second.start){
         return true;
     }
     return false;     
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.begin() + A.size(), customComparator); //sorted the array
    vector<Interval> mergedInterval;
    for(int i = 0; i < A.size(); i++) {
        if(mergedInterval.empty() == true || A[i].start > mergedInterval.back().end ){
            mergedInterval.push_back(A[i]);
        } else {
            mergedInterval.back().end = fmax(mergedInterval.back().end, A[i].end);
        }
    }
    return mergedInterval;
    
}
