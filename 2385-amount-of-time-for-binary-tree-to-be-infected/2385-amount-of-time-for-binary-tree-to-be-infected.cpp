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
    void assignPar(TreeNode* root, TreeNode* par, unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if(root==NULL)
        return;

        mp[root]=par;

        assignPar(root->left,root,mp);
        assignPar(root->right, root, mp);
    }
  
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*>mp;
        assignPar(root,nullptr,mp);

        unordered_map<TreeNode*, bool>vis;

        TreeNode* startNode=NULL;
        for(auto it: mp)
        {
            if(it.first->val==start)
            {
                startNode=it.first;
            }
           vis[it.first]=false;
        }

        queue<TreeNode*>q;
        int ans=-1;

        q.push(startNode);
        vis[startNode]=true;

        while(!q.empty())
        {

            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* curr=q.front();
                   // cout<<curr->val<<" ";
                q.pop();

                if(curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                     vis[curr->right]=true;
                }
                if(mp[curr] && !vis[mp[curr]])
                {
                    q.push(mp[curr]);
                     vis[mp[curr]]=true;
                }
            }
           //
            cout<<endl;
            ans++;
        }
        return ans;

    }
};