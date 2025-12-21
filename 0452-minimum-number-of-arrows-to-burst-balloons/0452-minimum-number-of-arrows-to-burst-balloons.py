class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """

        points.sort()

        start=points[0][0]
        end=points[0][1]
        j=0
        arrow=1

        n=len(points)

        for i in range(1,n):
            if(points[i][0]<=end):
                #means it is overlapping
                if(end<points[i][1]):
                    None
                else:
                    j=i
                    start=points[j][0]
                    end=points[j][1]

                
            else:
                #it is not overlapping
                j=i
                start=points[j][0]
                end=points[j][1]
                 # so we need one more arrow
                arrow+=1
        
        return arrow
        