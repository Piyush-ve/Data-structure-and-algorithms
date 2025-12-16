# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def storeLeaf(self,root,list1):
        if(root==None):
            return 
        if(root.left is None and root.right is None):
            list1.append(root.val)

        self.storeLeaf(root.left,list1)
        self.storeLeaf(root.right,list1)

        return
    def leafSimilar(self, root1, root2):
        """
        :type root1: Optional[TreeNode]
        :type root2: Optional[TreeNode]
        :rtype: bool
        """

        list1 = []
        list2 =[]

        self.storeLeaf(root1,list1)
        self.storeLeaf(root2,list2)

        print(list1)
        print(list2)

        return list1==list2

        