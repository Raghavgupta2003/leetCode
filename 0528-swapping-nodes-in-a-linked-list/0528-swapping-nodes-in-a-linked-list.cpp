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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp = head;
        int n = 1;
        ListNode* kth = NULL;
        ListNode* kthEnd = NULL;
        while(temp!=NULL){
            if(n == k) kth = temp;
            temp = temp->next;
            n++;
        }

        temp = head;
        for(int i=1; i<n-k; i++){
            temp = temp->next;
        }
        kthEnd = temp;

        swap(kth->val, kthEnd->val);

        return head;
    }
};