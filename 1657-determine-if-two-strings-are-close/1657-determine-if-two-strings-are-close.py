class Solution(object):
    def closeStrings(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: bool
        """

        # step1 store the occurence of each character 
        # step2 now store them into list and comapre list if list = another list then return true

        dict1= {}
        dict2 ={}

        i=0
        while i<len(word1):
            if(word1[i] in dict1):
                newVal = dict1.get(word1[i])+1
                dict1.update({word1[i]: newVal})
            else:
                dict1.update({word1[i]: 1})
            
            i+=1

        j=0

        while j<len(word2):
            if(word2[j] in dict2):
                newVal = dict2.get(word2[j])+1
                dict2.update({word2[j]: newVal})
            else:
                dict2.update({word2[j]: 1})
            
            j+=1

        l1=dict1.values()
        l2=dict2.values()

        k1=dict1.keys()
        k2=dict2.keys()

        k1.sort()
        k2.sort()

        l1.sort()
        l2.sort()

        if(k1==k2 and l1==l2):
            return True
        else:
            return False





        