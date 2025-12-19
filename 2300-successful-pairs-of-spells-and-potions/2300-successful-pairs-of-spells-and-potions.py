class Solution(object):
    def helper(self,potions,success,el):
        i=0
        j=len(potions)-1
        idx=-1
        while i<=j:
            mid=(i+j)/2
            if (success <= potions[mid]*el):
                idx=mid
                j=mid-1
            else:
                i=mid+1
        
        if(idx>-1):
            self.ans.append(len(potions)-idx)
        else:
            self.ans.append(0)




    def successfulPairs(self, spells, potions, success):
        """
        :type spells: List[int]
        :type potions: List[int]
        :type success: int
        :rtype: List[int]
        """

        potions.sort()
        self.ans=[]
        for el in spells:
            self.helper(potions,success,el)


        return self.ans


        