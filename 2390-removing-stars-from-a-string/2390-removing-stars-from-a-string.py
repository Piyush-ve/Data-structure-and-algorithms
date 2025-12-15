class Solution(object):
    def removeStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        i=0
        n=len(s)


        while i<n:
            if(s[i]=="*"):
                stack.pop()
            else:
                stack.append(s[i])
            i+=1
        

        ans=""
        j=0
        n=len(stack)
        while j<n:
            ans+=stack.pop()
            j+=1

        #ans.reverse()

        return ans[::-1]
        