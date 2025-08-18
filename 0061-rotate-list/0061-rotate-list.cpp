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
    int get_size(ListNode* head)
    {
        int sz=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            sz++;
            temp=temp->next;
        }
        return sz;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==nullptr||head->next==nullptr)
        return head;

        ListNode* prev=head;
        ListNode* curr=head->next;

        k=k%get_size(head);

        while(k!=0)
        {
            while(curr->next!=nullptr)
            {
                prev=curr;
                curr=curr->next;
            }
            prev->next=nullptr;
            curr->next=head;
            head=curr;
            k--;
        }

        return head;

    }
};