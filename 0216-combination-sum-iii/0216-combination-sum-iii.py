class Solution(object):
    def helper(self,k, n, lis, i, count, curr):

        if(curr==n and count==k):
            self.answers.add(tuple(self.ans))
            return

        if(i>=len(lis) or count>k or curr>n):
            return 


        if(curr<n and count<k):
            self.ans.append(lis[i])
            self.helper(k, n, lis, i+1, count+1, curr+lis[i]) #including element
            self.ans.pop()

            self.helper(k, n, lis, i+1, count, curr) #not including element


    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        lis=[1,2,3,4,5,6,7,8,9]
        self.answers=set()
        self.ans=[]

        self.helper(k,n,lis,0,0,0)

        return list(self.answers)