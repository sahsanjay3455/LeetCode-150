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
    ListNode* sortList(ListNode* head) 
    {
        vector<int>st;
        struct ListNode *temp=head;

        while(temp!=NULL)
        {
            st.push_back(temp->val);
            temp=temp->next;

        }
        sort(st.begin(),st.end());

        temp=head;
       
        for(auto it:st)
        {
            temp->val=it;
            temp=temp->next;

        }
        return head;
        
    }
};