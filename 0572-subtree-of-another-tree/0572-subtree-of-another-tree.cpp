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
    bool check(TreeNode* node, TreeNode* subRoot)
    {
        if(node==nullptr && subRoot==nullptr)return true;
        if(node==nullptr || subRoot==nullptr)return false;

        if(node->val!=subRoot->val)return false;

        return check(node->left, subRoot->left) && check(node->right, subRoot->right);
    }

   void findd(queue<TreeNode*> &q,TreeNode* root, int subRoot)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val==subRoot)
        {
            q.push(root);
      
        }
        
       findd(q,root->left, subRoot);
        findd(q,root->right, subRoot);

        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot==nullptr) return true;
        if(root==nullptr)return false;

        queue<TreeNode*>q;
        findd(q,root, subRoot->val);
        

        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(check(node, subRoot))return true;

        }

        return false;
     
    }
};