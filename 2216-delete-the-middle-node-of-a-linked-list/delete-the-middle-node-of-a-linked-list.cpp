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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*head1=head;
        ListNode*fast=head;
        ListNode*slow=head;
        int c=0,n=0;
        while(head1!=NULL)
        {
            head1=head1->next;
            c++;
        }
        n=c/2;
        
        if(head == NULL || head->next == NULL)
            return NULL;
       for(int i=0;i<n-1;i++)
        fast=fast->next;
        fast->next=fast->next->next;
        return head;

    }
};