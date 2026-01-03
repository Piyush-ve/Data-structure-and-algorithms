class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """

        ans=[]

        if(len(intervals)==0):
            ans.append(newInterval)
            return ans
        
        intervals.append(newInterval)


        intervals.sort()
        
        s=intervals[0][0]
        e=intervals[0][1]

        n=len(intervals)
        for i in range(1,n):
            if(s<=intervals[i][0] and e>=intervals[i][0]):
                s=min(s,intervals[i][0])
                e=max(e,intervals[i][1])
                
            else:
                
                lis=[]
                lis.append(s)
                lis.append(e)
                ans.append(lis)

                s=intervals[i][0]
                e=intervals[i][1]

        lis=[]
        lis.append(s)
        lis.append(e)
        ans.append(lis)

        return ans

            

                

                
            
            
                
