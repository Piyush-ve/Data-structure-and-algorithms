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
    vector<int>v;
    int Sum=0;

    void inorder(TreeNode* root)
    {
        if(root==NULL)
        return ;

        inorder(root->left);
        v.push_back(root->val);
        Sum+=root->val;
        inorder(root->right);

    }

    void update(unordered_map<int,int>&mp , TreeNode* root)
    {
        if(root==NULL)
        return ;

        update(mp,root->left);

        int Val=mp[root->val];
        root->val=Val;

        update(mp,root->right);
    }


    TreeNode* bstToGst(TreeNode* root) {

        inorder(root);

        int n=v.size();

        vector<int>updatedVal(n);

        updatedVal[0]=Sum;

        for(int i=1;i<n;i++)
        {
            Sum-=v[i-1];
            updatedVal[i]=Sum;
        }

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[v[i]]=updatedVal[i];
        }

        update(mp,root);

        return root;

    }
};