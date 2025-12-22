class Solution(object):
    def helper(self, candidates, target, i, curr):
        
        if(i>=len(candidates)):
            return 

        curr+=candidates[i]

        if(curr==target):
            self.ans.append(candidates[i])
            self.answers.add(tuple(self.ans))
            self.ans.pop()
            curr-=candidates[i]
            self.helper(candidates,target,i+1, curr)
        elif(curr<target):
            # there are two options you shoul take elements or you shoul not take 


            # 2 the option is take the current element
            self.ans.append(candidates[i])
            self.helper(candidates,target,i,curr)
            self.helper(candidates,target,i+1,curr)
            self.ans.pop()
            curr-=candidates[i]
            
            #1 option is don't take the current element
            self.helper(candidates, target, i+1, curr)
        elif(curr>target):
            curr-=candidates[i]
            self.helper(candidates,target,i+1, curr)
        
        return 

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        idx=0
        self.answers=set()
        self.ans=[]

        self.helper(candidates, target, 0, 0)
        return list(self.answers)



        