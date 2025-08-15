class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();

        vector<vector<int>>ans;

        for(int i=0;i<n;i++)
        {
            
            vector<int>a;

            int startInt=intervals[i][0];
            int endInt=intervals[i][1];

            for(int j=i+1;j<n;j++)
            {
                if(endInt>=intervals[j][0])
                {
                    endInt=max(endInt,intervals[j][1]);
                    i++;

                }
                else {
                    break;
                }
            }
            a.push_back(startInt);
            a.push_back(endInt);

            ans.push_back(a);
        }

        return ans;
    }
};