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
    void height(TreeNode* root,int h,vector<pair<int,TreeNode*>>&back)
    {
        if(root==NULL)return;
        if(root->left==nullptr&&root->right==nullptr)
        {
            back.push_back({h,root});
        }
        

        height(root->left,h+1,back);
        height(root->right,h+1,back);
    }

    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==nullptr)
        return NULL;

        if(root==p||root==q)return root;

        TreeNode* leftlca=lca(root->left,p,q);
        TreeNode* rightlca=lca(root->right,p,q);


        if(leftlca!=NULL&&rightlca!=NULL)
        return root;

        return leftlca==NULL?rightlca:leftlca;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
 
        if(root==NULL||(root->left==nullptr && root->right== nullptr))
        {
            return root;
        }
        vector<pair<int,TreeNode*>>back;
        height(root,0,back);

        

        int maxDepth=0;

        for(auto p:back)
        {
            maxDepth=max(p.first,maxDepth);
        }

        vector<TreeNode*>deepestleaves;

        for(auto p:back)
        {
            if(p.first==maxDepth)
            {
                deepestleaves.push_back(p.second);
            }
        }

        TreeNode* res=deepestleaves[0];
        int n=deepestleaves.size();
        for(int i=1;i<n;i++)
        {
            
            res = lca(root, res, deepestleaves[i]);
        }

        return res;

        
    }
};