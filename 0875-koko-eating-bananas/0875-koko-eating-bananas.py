class Solution(object):
    def check(self,speed, piles, h):
        count=0
        if(speed==0):
            return False
        for el in piles:
            if(speed > el):
                count+=1 
               # print("if condition 1;- ",speed, el)
            elif(el %speed ==0):
                count+=(el/speed)
                # print("elif condition 2- ",speed/el, el)
            else:
                count+=((el/speed)+1)
               # print("else condition 3- ",(speed/el)+1, el)
        print(speed, count)
        return count<=h
            
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        
        piles.sort()
        n=len(piles)

        if(n==h):
            return piles[n-1]
        
        ans=float('inf')
        i=0
        j=piles[n-1]
        
        while(i<=j):
            mid=(i+j)/2

            if(self.check(mid,piles,h)):
                ans=min(ans,mid)
                j=mid-1
            else:
                i=mid+1

        return ans
        