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
        if(head==NULL || head->next==NULL) return head;
        int length = 0;
        ListNode* temp = head;
        ListNode* first = NULL;
        ListNode* second = NULL;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        cout<<length;

        // k = length;

        temp=head;
        for(int i=1;i<=length;i++){
            if(i==k) first = temp;
            if(i==length-k+1) second = temp;
            temp=temp->next;
        }

        //swapping

        int t = first->val;
        first->val = second->val;
        second->val = t;

        return head;     
    }
};