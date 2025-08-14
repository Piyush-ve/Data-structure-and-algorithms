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
    vector<TreeNode*>in;
    void inorder(TreeNode* root)
    {
        if(root== NULL)
        {
            return;
        }

       
        in.push_back(root);
         inorder(root->left);
        inorder(root->right);
    }

   void flatten(TreeNode* root) {

        inorder(root);
        int n=in.size();
        TreeNode* curr=root;
        if(in.size()>0)
        cout<<in[0]->val<<" ";

        for(int i=1;i<n;i++)
        {
            cout<<in[i]->val<<" ";
            curr->left=NULL;
            curr->right=in[i];

            curr=curr->right;
        }
        

        return ;
    }
};