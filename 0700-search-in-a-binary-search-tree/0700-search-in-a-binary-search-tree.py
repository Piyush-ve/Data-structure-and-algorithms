# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def helper(self,root,val):
        if(root==None):
            return None
        if(root.val==val):
            return root
        ans1=self.helper(root.left,val)
        ans2=self.helper(root.right,val)

        if(ans1):
            return ans1
        return ans2

    def searchBST(self, root, val):
        """
        :type root: Optional[TreeNode]
        :type val: int
        :rtype: Optional[TreeNode]
        """
        ans=self.helper(root,val)

        return ans
        