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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr)
        return -1;
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        int curr_level=1;
        int level=1;
        int max_val=INT_MIN;
        int sum=0;

      //  priority_queue<pair<int,int>>pq;

        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();

            if(curr==nullptr)
            {
                if(max_val<sum)
                {
                    max_val=sum;
                    level=curr_level;
                }
                curr_level++;
                sum=0;
                if(q.empty())
                break;

                q.push(nullptr);
            }
            else
            {
                sum+=curr->val;
                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
            }
        }

        

        return level;
        
    }
};