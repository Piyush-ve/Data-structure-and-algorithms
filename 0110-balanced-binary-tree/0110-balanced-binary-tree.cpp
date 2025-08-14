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
    int height(TreeNode* root)
    {
        if(root==NULL)return 0;

        int leftHt=height(root->left);
        int rightHt=height(root->right);

        return max(leftHt,rightHt)+1;
    }
    bool isBalanced(TreeNode* root) {

        if(root==NULL)return true;

        if(!isBalanced(root->left))
        return false;

        if(!isBalanced(root->right))
        return false;


        int leftHt=height(root->left);
        int rightHt=height(root->right);

        int d=abs(leftHt-rightHt);

        if(d>1)
        return false;
        else
        return true;

    }
};