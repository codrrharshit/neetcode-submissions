/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a.start<b.start;
        });
        // we will maintain the minheap for the earliest end time 
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int i=0;i<intervals.size();i++){
           // for  reuse of the same day we have to assure that minheap top  should be ;ess than the start
           if(!minHeap.empty() && minHeap.top()<=intervals[i].start){
                minHeap.pop(); // we will reuse and take out and update the endtime 
           }
           minHeap.push(intervals[i].end);
        }


        return minHeap.size();
        
    }
};
