class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        # find number of overlapping intervals
        points.sort()
        en=points[0][1]
        count=1
        n=len(points)
        
        for i in range(1,n):
            if(points[i][0]<=en):
                en=min(points[i][1],en)
                print("if",en)
            else:
                count+=1
                en=points[i][1]
                print(en)


        return count
