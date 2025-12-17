# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        list1 = []
        i=0
        q=[]
        if(root is None):
            return list1
        q.append(root)
        while q:
            l=[]
            n=len(q)
            for i in range(0,n):
                curr=q.pop(0)
                if(curr):
                    l.append(curr.val)
                    if(curr.left):
                        q.append(curr.left)
                    if(curr.right):
                        q.append(curr.right)
            list1.append(l[len(l)-1])

        return list1


                


        