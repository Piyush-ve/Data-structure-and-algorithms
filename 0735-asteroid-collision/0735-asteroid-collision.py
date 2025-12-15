class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """

        stack= []
        i=0
        while(i<len(asteroids)):
            if(len(stack)==0):
                stack.append(asteroids[i])
            else:
                top = stack[-1]
                nextEl=asteroids[i]
                if((nextEl>0 and top>0) or (nextEl<0 and top<0) or (nextEl>0 and top<0)):
                    stack.append(nextEl)

                elif(nextEl<0 and top>0 ):
                    if(abs(nextEl) > abs(top)):
                        while len(stack)>0  and abs(nextEl)>abs(top):
                            print(stack," top:- ",top,"nextEl:- ",nextEl)
                            stack.pop()
                            if len(stack)>0:
                                top = stack[-1]
                        
                        if(abs(top)>abs(nextEl)):
                            pass
                        else:
                            stack.append(nextEl)
                    elif(abs(nextEl)==abs(top)):
                        stack.pop()
                
            i+=1

        return stack


        

