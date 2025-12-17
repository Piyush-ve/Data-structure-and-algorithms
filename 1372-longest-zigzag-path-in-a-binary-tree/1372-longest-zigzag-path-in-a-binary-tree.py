# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def helper(self, root, dir, step):
        if not root:
            return step
        
        self.ans = max(self.ans, step)

        if dir:  # go left
            a1 = self.helper(root.left, False, step + 1)
            a2 = self.helper(root.right, True, 1)
        else:    # go right
            a1 = self.helper(root.right, True, step + 1)
            a2 = self.helper(root.left, False, 1)

        return max(a1, a2)


    def longestZigZag(self, root):

        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if not root:
            return 0

        self.ans = 0
        self.helper(root.left, False, 1)
        self.helper(root.right, True, 1)

        return self.ans
        
        