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
    ListNode* middleNode(ListNode* head) {
        // ListNode*temp = head;
        // int cnt=0;
        // while(temp!=NULL){
        //     temp=temp->next;
        //     cnt++;
        // }
        // int middle=(cnt/2);
        // ListNode* mid= head;
        // int pos=0;
        // while(pos!=middle){
        //     mid=mid->next;
        //     pos++;
        // }
        // return mid;

        //---------interviewer want to do in one pass-----------

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};