class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        my_dict ={}
        
        for el in arr:
            if(el in my_dict):
                newVal=my_dict.get(el)+1
                my_dict.update({el : newVal})
            else:
                my_dict.update({el:1})

        val=my_dict.values()
        key=my_dict.keys()


        set1 = set()
        for el in val:
            set1.add(el)
        

        if(len(set1)==len(key)):
            return True
        else:
            return False

            