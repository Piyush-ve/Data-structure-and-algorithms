class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

            sort(events.begin(),events.end());
            
            //Min heap
            //end day
            
            priority_queue<int,vector<int>,greater<int>>pq;

            int day=events[0][0];
            int event=0;

            int n=events.size();
            int i=0;

           
            
            while(i<n || !pq.empty())
            {

                while(i<n && events[i][0]==day)
                { 
                    pq.push(events[i][1]);
                    i++;
                }

                if(!pq.empty())
                {
                    event++;
                    pq.pop();                  
                }
                day++;

                while(!pq.empty() && pq.top()<day)
                {
                    pq.pop();
                }


               
            }
            return event;   
    }
};
