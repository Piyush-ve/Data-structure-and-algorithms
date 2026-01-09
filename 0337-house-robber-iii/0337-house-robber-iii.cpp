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
void initialize(unordered_map<TreeNode*, vector<int>>&mp, TreeNode* root)
{
    if(root==NULL)
    return;

    mp[root].push_back(-1);
    mp[root].push_back(-1);
 
    initialize(mp,root->left);
    initialize(mp,root->right);
}
int helper(TreeNode* root, bool taken, unordered_map<TreeNode*, vector<int>>&mp)
{
    
    if(root==nullptr)
    return 0;

    if(mp[root][taken]!=-1)
    {
        return mp[root][taken];
    }
    int take=-1;
    if(!taken)
    {
        take= root->val+ helper(root->left,true,mp) + helper(root->right,true,mp);
    }
     int notTake= helper(root->left,false,mp) + helper(root->right,false,mp);
     return mp[root][taken]=max(take,notTake);
}
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>>mp;
        initialize(mp,root);
        return helper(root,false,mp);
    }
};