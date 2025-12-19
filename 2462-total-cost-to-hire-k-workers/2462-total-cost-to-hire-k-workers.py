class Solution(object):

    def totalCost(self, costs, k, candidates):
        """
        :type costs: List[int]
        :type k: int
        :type candidates: int
        :rtype: int
        """
        # we have to take n candidates from starting of costs and n from last of list
        import heapq

        pqLeft=[]
        pqRight=[]

        i=0
        j=len(costs)-1

        while i<candidates:
            heapq.heappush(pqLeft,costs[i])
            i+=1
        
        count=0
        while count<candidates and j>=i:
            heapq.heappush(pqRight,costs[j])
            j-=1
            count+=1


        cost =0

        while k!=0:
            topL = pqLeft[0] if pqLeft else float('inf')
            topR = pqRight[0] if pqRight else float('inf')

            if(topR<topL):
               # print(topR, pqRight)
                cost+=topR
                heapq.heappop(pqRight)
                if(i<=j):
                    heapq.heappush(pqRight,costs[j])
                    j-=1
            else:
               # print(topL, pqLeft)
                cost+=topL
                heapq.heappop(pqLeft)
                if(i<=j):
                    heapq.heappush(pqLeft,costs[i])
                    i+=1
                #print(i,j,pqLeft)
            k-=1
        
        return cost
