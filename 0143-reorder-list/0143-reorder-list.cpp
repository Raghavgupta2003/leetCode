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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* revhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return revhead;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //--------------right middle------------
        // while(fast!=NULL && fast->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* head1 = reverse(slow->next);
        slow->next = NULL;

        // now we have two linked lists 
        // 1) head 2) head1

        ListNode* dummy = new ListNode(0);
        ListNode* temp1 = head;
        ListNode* temp2 = head1;

        while(temp1!=NULL){
            if(temp1!=NULL){
                dummy->next = temp1;
                temp1=temp1->next;
                dummy = dummy->next;
            }
            if(temp2!=NULL){
                dummy->next = temp2;
                temp2=temp2->next;
                dummy = dummy->next;
            }
            
        }
      
        head = dummy->next;
    }
};