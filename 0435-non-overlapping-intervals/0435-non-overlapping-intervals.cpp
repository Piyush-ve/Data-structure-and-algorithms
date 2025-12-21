class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        for(int i=0;i<intervals.size();i++)
        {
            reverse(intervals[i].begin(),intervals[i].end());
        }

        sort(intervals.begin(),intervals.end());
        int time=INT_MIN;

        int n=intervals.size();
        int meetings=0;

        

        for(int i=0;i<n;i++)
        {
            if(time<=intervals[i][1])
            {
                meetings++;
                time=intervals[i][0];
            }
        }
    //    cout<<meetings;

        return n-meetings;
    }
};