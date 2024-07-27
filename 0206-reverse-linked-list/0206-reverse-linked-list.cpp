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
    ListNode* reverseList(ListNode* head)
     {

        if(head == NULL || head->next==NULL)
        {
            return head;
        }

        struct ListNode *temp=head;
        struct ListNode *left=nullptr;
        struct ListNode *right=head;
        while(temp!=NULL)
        {
            right=right->next;
            temp->next=left;
            left=temp;
            temp=right;
            
        }
        
        return left;


        
    }
};