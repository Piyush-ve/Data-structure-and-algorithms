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
    int Max=Integer.MIN_VALUE;
    int val(TreeNode root)
    {
        if(root==null)
        {
            return 0;
        }

        int leftVal= Math.max(val(root.left), 0);
        int rightVal= Math.max(val(root.right),0);

        int currVal=root.val+leftVal+rightVal;
        Max=Math.max(currVal,Max);


        return root.val+Math.max(leftVal,rightVal);
    }
    public int maxPathSum(TreeNode root) {
        val(root);

        return Max;
    }
}