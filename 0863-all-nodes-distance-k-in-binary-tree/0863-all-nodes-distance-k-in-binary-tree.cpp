/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     void assignPar(TreeNode* root, TreeNode* par, unordered_map<TreeNode*,TreeNode*>&mp)
     {
        if(root==NULL)
        return ;

        mp[root]=par;

      //  mp[root->left]=root;
     //   mp[root->right]=root;

        assignPar(root->left, root, mp);
        assignPar(root->right, root, mp);
     }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
        {
            return {target->val};
        }
        unordered_map<TreeNode*,TreeNode*>mp;//stores par

        assignPar(root,nullptr,mp);

       unordered_map<TreeNode*,bool>vis;
       for(auto it: mp)
       {
            vis[it.first]=false;
       }

       vector<int>ans;

       queue<pair<TreeNode*, int>>q; //dist

       q.push({target, 0});
       vis[target]=true;

       while(!q.empty())
       {
            pair<TreeNode*, int>curr=q.front();
            q.pop();

            int d=curr.second;

            TreeNode* node=curr.first;

         //   cout<<node->val<<"  "<<d<<endl;

            if(node->left!=NULL && !vis[node->left])
            {
               int newD =d+1;
                if(newD==k)
                {
                    ans.push_back(node->left->val);
                }
                q.push({node->left, newD});
                vis[node->left]=true;
            }
            if(node->right!=NULL && !vis[node->right])
            {
                int newD =d+1;
                if(newD ==k)
                {
                    ans.push_back(node->right->val);
                }
                q.push({node->right, newD });
                vis[node->right]=true;
            }
            if(mp[node]!=NULL && !vis[mp[node]])
            {
                int newD =d+1;
                if(newD ==k)
                {
                    ans.push_back(mp[node]->val);
                }
                q.push({mp[node],newD });
                vis[mp[node]]=true;
            }
       }


       
        return ans;
    }
    
};