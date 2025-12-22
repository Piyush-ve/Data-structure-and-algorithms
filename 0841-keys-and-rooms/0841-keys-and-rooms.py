class Solution(object):
    def helper(self, vis, rooms, u):
        vis[u]=True
        neigh=rooms[u]
        for v in neigh:
            if(not vis[v]):
                self.count+=1
                self.helper(vis, rooms, v)



    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """

        n=len(rooms)
        vis=[False]* n 
        self.count=0

        
        self.count+=1
        self.helper(vis,rooms,0)

        print(self.count)
        print(n)
        if(self.count==n):
            return True
        else:
            return False
        