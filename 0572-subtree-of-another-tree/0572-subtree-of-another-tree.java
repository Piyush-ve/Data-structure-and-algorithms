/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean check(TreeNode node, TreeNode subRoot)
    {
        if(node==null && subRoot==null)return true;
        if(node==null || subRoot==null)return false;

        if(node.val!=subRoot.val)return false;

        return check(node.left, subRoot.left) && check(node.right, subRoot.right);
    }

   public void findd(Queue<TreeNode> q,TreeNode root, int subRoot)
    {
        if(root==null)
        {
            return;
        }
        if(root.val==subRoot)
        {
            q.add(root);
      
        }
        
       findd(q,root.left, subRoot);
        findd(q,root.right, subRoot);

        
    }
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if(subRoot==null) return true;
        if(root==null)return false;

        Queue<TreeNode>q =new LinkedList<>();
        findd(q,root, subRoot.val);
        

        while(!q.isEmpty())
        {
            TreeNode node=q.peek();
            q.remove();
            if(check(node, subRoot))return true;

        }

        return false;
    }
}