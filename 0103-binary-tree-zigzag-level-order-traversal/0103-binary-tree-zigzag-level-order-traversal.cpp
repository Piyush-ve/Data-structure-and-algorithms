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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==nullptr)return ans;

        queue<TreeNode*>Q;
        Q.push(root);
        int counter=0;//it reverse alternate level
 
        while(!Q.empty())
        {
            int level_size=Q.size();
            vector<int>a;
           
            for(int i=0;i<level_size;i++)
            {
                TreeNode* curr=Q.front();
                Q.pop();
                a.push_back(curr->val);

                if(curr->left)
                Q.push(curr->left);

                if(curr->right)
                Q.push(curr->right);
            }
            if(counter==0)
            {
                ans.push_back(a);
                counter=1;
            }
            else
            {
                reverse(a.begin(),a.end());
                ans.push_back(a);
                counter=0;
            }
            
        }
        return ans;
        
    }
};