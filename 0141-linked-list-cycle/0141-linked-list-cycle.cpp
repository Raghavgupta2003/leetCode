/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // set<ListNode*> s;
        // ListNode* temp = head;
        // int cnt=0;
        // while(temp!=NULL){
        //     if(s.find(temp)!=s.end()) return true;
        //     else s.insert(temp);
        //     temp=temp->next;
           
        // }
        // return false;

        //------------slow Fast ---------------------

        if(head==NULL || head->next==NULL) return false;
        ListNode* temp = head;
        ListNode*slow = temp;
        ListNode*fast = temp->next->next;
        while(true){
            if(slow==fast) return true;
            if(fast==NULL || fast->next==NULL) return false;
            slow=slow->next;
            fast=fast->next->next;
        }
       
    }
};