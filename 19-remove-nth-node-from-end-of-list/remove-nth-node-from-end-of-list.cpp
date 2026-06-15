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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=new ListNode(0);
        ListNode*head1=head;
        ListNode*head2=head;  
        int c=0,pos=0;
        
        while(head1!=NULL)
        {
            c++;
            head1=head1->next;
        }
        if(c==1)
        {
            head=head->next;
            return head;
        }
        pos=c-n;
        int a=1;
        while(head2!=NULL)
        {
            if(pos==0){

                head2=head2->next;
                return head2;
                
            }
            if(a==pos)
            {
                head2->next=head2->next->next;
                break;
            }    
            head2=head2->next;
            a++;
        }
        return head;


    }
};