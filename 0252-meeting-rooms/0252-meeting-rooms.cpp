class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i-1][1];
            if(start<end) return false;
        }
        return true;
    }
};