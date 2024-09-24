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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;

        ListNode* tail = NULL;
        ListNode* temp = head;

        int n=0; //size of linked list
        while(temp!=NULL){
            if(temp->next==NULL) tail = temp;
            temp=temp->next;
            n++;
        }

        k = k%n; //if k > n
        if(k==0) return head; //no need to rotate

        temp = head;
       for(int i=1;i<n-k;i++){
        temp=temp->next;
       }
        
        tail->next = head;
        head=temp->next;
        temp->next=NULL;

        return head;
    }
};