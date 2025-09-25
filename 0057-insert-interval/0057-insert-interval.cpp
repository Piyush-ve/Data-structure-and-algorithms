class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;
        int i=0;
        int n=intervals.size();

        

        while(i<n)
        {
            int startI=intervals[i][0];
            int endI=intervals[i][1];
            for(int j=i+1;j<n;j++)
            {
                if(intervals[j][0]>=startI && intervals[j][0]<=endI)
                {
                    endI=max(endI,intervals[j][1]);
                    i=j;
                }
            }
           

            ans.push_back({startI,endI});
            i++;
            
        }
        return ans;
    }
};