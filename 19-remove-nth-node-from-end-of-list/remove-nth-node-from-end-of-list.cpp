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
    int count(ListNode* l){
        int c=0;
        while(l){
            c++;
            l=l->next;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* temp1=head;
        int len=count(head);
        
        if (len == n) {
            return head->next;
        }
        n=len-n;
        while(temp){
             n--;
            if(n==0){
                temp->next=temp->next->next;
            }
           
            temp=temp->next;

        }
        return temp1;
    }
};