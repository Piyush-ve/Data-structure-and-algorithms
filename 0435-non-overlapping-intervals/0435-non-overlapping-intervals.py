class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """

        intervals.sort()
        #print(intervals)

        start=intervals[0][0]
        end=intervals[0][1]
        j = 0
        
        overlappingInter = []
        ans=0

        n=len(intervals)
        for i in range(1, n):
            if(intervals[i][0]<end):
                
                if(intervals[i][1]<end):
                    #delete previous elemnt
                    overlappingInter.append(intervals[j])
                    j=i
                    start=intervals[j][0]
                    end=intervals[j][1]
                    #inc the count
                else:
                    # delete current element
                    overlappingInter.append(intervals[i])
            else:
                j=i
                start=intervals[j][0]
                end=intervals[j][1]

        print(overlappingInter)
        return len(overlappingInter)
        
                    

        