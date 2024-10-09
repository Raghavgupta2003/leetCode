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
    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* revhead = rev(head->next);
        head->next->next = head;
        head->next = NULL;

        return revhead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        // cout<<slow->val;

        ListNode* revhead = rev(slow);

        ListNode*temp = head;
       
       while(revhead!=NULL){
        if(revhead->val != temp->val) return false;
        temp=temp->next;
        revhead = revhead->next;
       }



        return true;
    }
};