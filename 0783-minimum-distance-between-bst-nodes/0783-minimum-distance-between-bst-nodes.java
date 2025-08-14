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
    public void inorder(ArrayList<Integer> arr,TreeNode root)
    {
        if(root==null)
        {
            return ;
        }

        inorder(arr,root.left);
        arr.add(root.val);
        inorder(arr,root.right);

    }
    public int minDiffInBST(TreeNode root) {
         ArrayList<Integer>arr = new ArrayList<>();
        inorder(arr,root);

        int Min=Integer.MAX_VALUE;
        int pre=arr.get(0);

        for(int i=1;i<arr.size();i++)
        {
            Min=Math.min(arr.get(i)-pre,Min);
            pre=arr.get(i);

        }
        return Min;
    }
}