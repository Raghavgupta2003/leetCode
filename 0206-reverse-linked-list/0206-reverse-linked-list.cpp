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
    ListNode* getNodeAt(int idx,ListNode* head){
        ListNode* temp = head;
        // 1 2 3 4 5;
        for(int i=0;i<idx;i++){
            temp=temp->next;
        }
        return temp;

    }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        int n=0;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int i = 0;
        int j = n-1;

        while(i<j){
            ListNode* left = getNodeAt(i,head);
            ListNode* right = getNodeAt(j,head);
            int t = left->val;
            left->val = right->val;
            right->val = t;
            i++;
            j--;
        }

        return head;
     }
};