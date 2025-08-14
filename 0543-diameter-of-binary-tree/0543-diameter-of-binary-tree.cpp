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

    pair<int,int>helper(TreeNode* root)
    {
        if(root==nullptr)return make_pair(0,0);
        //(diameter,height)
        pair<int,int>leftInfo=helper(root->left);
        pair<int,int>rightInfo=helper(root->right);

        int currDiam=leftInfo.second+rightInfo.second;
        int leftDiam=leftInfo.first;
        int rightDiam=rightInfo.first;

        int finalDiam=max(currDiam,max(leftDiam,rightDiam));

        int finalHt=max(leftInfo.second,rightInfo.second)+1;

        return make_pair(finalDiam,finalHt);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>finalVal=helper(root);
        return finalVal.first;
    }

 
};