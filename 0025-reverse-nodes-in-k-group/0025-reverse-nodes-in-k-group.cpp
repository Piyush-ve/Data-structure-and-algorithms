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
ListNode *reverseKGroup(ListNode *head, int k){
   if (head == nullptr||k==1)
            return head;

//CHeck whether the k nodes exist
        int count = 0;
        ListNode *temp = head;
        while (count<k)
        {
            if (temp == nullptr)
                return head;
            temp = temp->next;
            count++;
        }

        //recursively call for rest of ll

        ListNode *prevNode=reverseKGroup(temp,k);

        temp = head;
        count=0;

        //reverse current group
        while (count<k)
        {
            ListNode *Next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp= Next;

            count++;
        }
        return prevNode;
}
};