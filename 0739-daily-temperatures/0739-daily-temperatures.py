class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """

        ans=[]
        stack=[]
        n=len(temperatures)

        for i in range(n-1, -1, -1):
            if(not stack):
                ans.append(0)
                stack.append(i)
            else:
                top=temperatures[stack[-1]]
                
                if(top>temperatures[i]):
                    idx=stack[-1]#greater element idx
                    ans.append(idx-i)
                    stack.append(i)
                    
                else:
                    #top=temperatures[stack[len(stack)-1]]
                    while stack and top<=temperatures[i]:
                        stack.pop()
                        if(stack):
                            top=temperatures[stack[-1]]


                    if(stack):
                        top=temperatures[stack[-1]]
                        
                        idx=stack[-1]
                        ans.append(idx-i)
                        stack.append(i)
                    else:
                        ans.append(0)
                        stack.append(i)

        ans.reverse()
        return ans
  
                    

                        

            
            
