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
    // ListNode* getNodeAt(int idx,ListNode* head){
    //     ListNode* temp = head;
    //     // 1 2 3 4 5;
    //     for(int i=0;i<idx;i++){
    //         temp=temp->next;
    //     }
    //     return temp;

    // }
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* temp = head;
    //     int n=0;
    //     while(temp!=NULL){
    //         n++;
    //         temp=temp->next;
    //     }
    //     int i = 0;
    //     int j = n-1;

    //     while(i<j){
    //         ListNode* left = getNodeAt(i,head);
    //         ListNode* right = getNodeAt(j,head);
    //         int t = left->val;
    //         left->val = right->val;
    //         right->val = t;
    //         i++;
    //         j--;
    //     }

    //     return head;
    //  }

    //-------------------Approach 2 (iteratively way)-------------------------------

    // ListNode* reverseList(ListNode* head) {
    //     ListNode* pre = NULL;
    //     ListNode* cur = head;
    //     ListNode* Next = NULL;
    //     while(cur!=NULL){
    //         Next = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = Next;
    //     }
    //     return pre;
    // }

    //------------------------Recursive-------------------

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;

        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};