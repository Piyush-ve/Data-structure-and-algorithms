/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        if(head==nullptr)
        return 0;

        if(head->next->next==nullptr)
        return head->val+head->next->val;

        vector<int>pair;

        
        ListNode* curr=head;
       


        while(curr!=nullptr)
        {
           pair.push_back(curr->val); 
           curr=curr->next;
        }

        int Max=INT_MIN;
        int i=0;
        int j=pair.size()-1;

        while(i<j)
        {
            int currSum=pair[i]+pair[j];
            Max=max(Max,currSum);
            i++;
            j--;
        }

        return Max;
        
    }
};