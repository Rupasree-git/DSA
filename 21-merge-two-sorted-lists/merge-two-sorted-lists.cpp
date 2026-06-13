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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*temp=new ListNode(0);
        ListNode*temp1=temp;
        ListNode*head=temp;
        while(list1||list2)
        {
            if(list1==NULL && list2)
            {
                temp1->next = list2;
                return head->next;
            }
            else if(list2==NULL && list1)
            {
                temp1->next = list1;
                return head->next;
            }
            else if(list1==NULL && list2==NULL)
            {
                return NULL;
            }
            else
            {
                if(list1->val<=list2->val)
            {
                temp=new ListNode(list1->val);
                list1=list1->next;
                temp1->next=temp;
                temp1=temp1->next;
            }
            else
            {
                temp=new ListNode(list2->val);
                list2=list2->next;
                temp1->next=temp;
                temp1=temp1->next;
            }
            }
        }
        return head->next;

    }
};