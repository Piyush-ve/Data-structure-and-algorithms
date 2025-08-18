/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr)
        return false;
        
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
            
            if(fast!=nullptr)
            fast=fast->next;

            if((slow==fast))
            {
                break;
            }
        }

        if(slow==fast)
        return true;
       
        return false;

        
        
        
    }
};