class Solution(object):
    def equalPairs(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        dict1 = {}
        count=0

        for l in grid:
            tup=tuple(l)
            if(tup in dict1):
                newVal = dict1.get(tup)+1
                dict1.update({tup: newVal})
            else:
                dict1.update({tup: 1})

        grid2=[]

        n=len(grid)
        for i in range(0,n,1):
            l=[]
            for j in range(0,n,1):
                l.append(grid[j][i])
            grid2.append(tuple(l))


        for tu in grid2:
            if(tu in dict1):
                count+=dict1.get(tu)
        
        
        return count