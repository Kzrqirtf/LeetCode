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
    ListNode* middleNode(ListNode* head)
    {
        
        // int i=1;
        // ListNode* temp=head;
        // while(temp->next!=NULL){i++;temp=temp->next;}
        // temp=head;
        // i=i/2;
        // for(int a=0;a<i;a++)
        //     head=head->next;
        // return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast)
        {
            if(fast->next==NULL)fast=NULL;
            else
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;

 
    }
};