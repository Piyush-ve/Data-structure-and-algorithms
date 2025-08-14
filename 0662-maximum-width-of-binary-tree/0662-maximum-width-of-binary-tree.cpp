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
    int levelOrder(TreeNode* root)
    {
        if(root==NULL)
        return 0;

       // vector<vector<int>> ans;
        queue<pair<TreeNode*,int>>Q;

        Q.push({root,0});
        int width =0;
        while(Q.size()!=0)
        {
            int n=Q.size();
            vector<int>a;
            for(int i=0;i<n; i++)
            {
                pair<TreeNode*,int> Curr=Q.front();
                Q.pop();

                TreeNode* currNode=Curr.first;
                unsigned int idx=Curr.second;

                a.push_back(idx);

                if(currNode->left)
                {
                   unsigned int j=(2*idx)+1;
                    Q.push({currNode->left,j});
                }
                if(currNode->right)
                {
                   unsigned int j=(2*idx)+2;
                    Q.push({currNode->right,j});
                }
            }
            int s=a.size();
            width=max((a[s-1]-a[0]+1),width);
        }

        return width;

    }
    int widthOfBinaryTree(TreeNode* root) {
        return levelOrder(root);
    }
};