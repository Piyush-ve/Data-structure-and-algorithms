class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        import heapq
        pq =[]

        for el in nums:
            heapq.heappush(pq,-el)
            
        ans=None
        while k>0:
            ans=-heapq.heappop(pq)
            k-=1

        return ans
        
        