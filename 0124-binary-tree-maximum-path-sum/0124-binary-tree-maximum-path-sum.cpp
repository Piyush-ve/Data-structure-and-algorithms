/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum=INT_MIN;
    int val(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        int leftVal=max(val(root->left),0);
        int rightVal=max(val(root->right),0);

        int currentPathSum=root->val+leftVal+rightVal;

        maxSum=max(maxSum, currentPathSum);

        return root->val+max(leftVal,rightVal);
         
    }
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL)return 0;
        val(root);
        return maxSum;
    }
};