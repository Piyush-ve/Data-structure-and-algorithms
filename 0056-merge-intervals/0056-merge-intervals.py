class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """

        intervals.sort()

        st=intervals[0][0]
        end=intervals[0][1]

        ans=[]

        n=len(intervals)
        for i in range(1,n):
            el=intervals[i]
            if(el[0]>end):
                #it will add in it
                lis=[]
                lis.append(st)
                lis.append(end)
                ans.append(lis)
                st=el[0]
                end=max(end,el[1])
            else:
                end=max(end,el[1])
        
        lis=[]
        lis.append(st)
        lis.append(end)
        ans.append(lis)

        return ans


                


            
        