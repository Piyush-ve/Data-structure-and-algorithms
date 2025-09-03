/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      //  vector<vector<Node*>>levelOrder;

      if(root==NULL)return root;


        queue<Node*>Q;
        Q.push(root);

        while(!Q.empty())
        {
            int s=Q.size();
            vector<Node*>v;
            for(int i=0;i<s;i++)
            {
                Node* curr=Q.front();
                
                Q.pop();

                if(curr->left)
                {
                    v.push_back(curr->left);
                    Q.push(curr->left);
                }
                if(curr->right)
                {
                    v.push_back(curr->right);
                     Q.push(curr->right);
                }
            }

            int i=0;
            int j=i+1;

            while(j<v.size())
            {
                v[i]->next=v[j];
                i++;
                j++;
            }

        }

        return root;
    }
};