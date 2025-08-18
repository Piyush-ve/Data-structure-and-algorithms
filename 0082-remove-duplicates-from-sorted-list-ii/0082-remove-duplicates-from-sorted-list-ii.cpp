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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==nullptr||head->next==nullptr)
        return head;

        ListNode* dummynode=new ListNode(0);
        dummynode->next=head;

        ListNode* prev=dummynode;
        ListNode* curr=head;
        ListNode* Next=head->next;

        int data=INT_MIN;

        while(curr!=nullptr&&Next!=nullptr)
        {
            if(curr->val==Next->val)
            {   data=curr->val;
                while(curr->val==data&& Next!=nullptr)
                {
                    prev->next=curr->next;
                    delete curr;
                    curr=Next;
                    Next=Next->next;
                }

                if(curr->val==data)
                {
                    delete curr;
                    prev->next=nullptr;
                    break;
                }
            }
            else
            {
                prev=curr;
                curr=Next;
                Next=Next->next;
            }
            

        }

        return dummynode->next;



        
    }
};