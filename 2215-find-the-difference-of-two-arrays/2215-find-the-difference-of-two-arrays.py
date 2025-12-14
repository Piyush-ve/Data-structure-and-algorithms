class Solution(object):
    def findDifference(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """

        ans=[]
        set1=set()
        set2=set()

        i=0
        while i<len(nums1):
            set1.add(nums1[i])
            i+=1

        j=0
        while j<len(nums2):
            set2.add(nums2[j])
            j+=1

        a=[]
        b=[]
        for el in set1:
            if(el not in set2):  #not found
                a.append(el)
            
        for el in set2:
            if(el not in set1):  #not found
                b.append(el)

        ans.append(a)
        ans.append(b)

        return ans


        