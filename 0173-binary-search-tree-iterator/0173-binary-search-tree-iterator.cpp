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
class BSTIterator {
public:
  
    vector<int>r;
    int i=0;
    void inorder(TreeNode* curr)
    {
        if(curr==NULL)
        return ;

        inorder(curr->left);
        r.push_back(curr->val);
        inorder(curr->right);
    }


    BSTIterator(TreeNode* root) {
       
        inorder(root);
    }
    
    int next() {
        int val=r[i];
        i++;
        return val;
    }
    
    bool hasNext() {

        if(i<r.size())return true;

        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */