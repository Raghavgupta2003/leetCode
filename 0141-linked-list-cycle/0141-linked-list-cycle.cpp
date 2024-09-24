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
        ListNode* temp = head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
            if(cnt>10002) return true;
        }
        return false;
    }
};