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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,c=0,s=0;
        ListNode*temp=new ListNode(0);
        ListNode*head=temp;
        ListNode*temp1=temp;
        while(l1||l2){
            if(l1 && l2==NULL)
            {
                sum=l1->val +c;
                 l1=l1->next;
            }
            else if(l1==NULL && l2)
            {
                sum=l2->val +c;
                l2=l2->next;
            }
            else
            {
            sum=l1->val+l2->val+c;
             l1=l1->next;
            l2=l2->next;
            }
            s=sum%10;
            c=sum/10;
           
            temp=new ListNode(s);
            temp1->next=temp;
            temp1=temp1->next;
            
        }
        if(c)
        {
            temp1->next=new ListNode(c);

        }
        return head->next;
        
    }
};