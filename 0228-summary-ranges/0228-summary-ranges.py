class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        ans = []
        if(len(nums)==0):
            return ans

        if(len(nums)==1):
            ans.append(str(nums[0]))
            return ans
        
        st = nums[0]
        end = nums[0]
        n=len(nums)

        for i in range(1,n):
            if((nums[i]-end)>1):
                if(st==end):
                    ans.append(str(st))
                    st=nums[i]
                    end=nums[i]
                else:
                    el=str(st)+"->"+ str(end)
                    st=nums[i]
                    end=nums[i]
                    ans.append(el)
            else:
                end=nums[i]

        if(st==end):
            ans.append(str(st))
            st=nums[i]
            end=nums[i]
        else:
            el=str(st)+"->"+ str(end)
            st=nums[i]
            end=nums[i]
            ans.append(el)


        return ans







