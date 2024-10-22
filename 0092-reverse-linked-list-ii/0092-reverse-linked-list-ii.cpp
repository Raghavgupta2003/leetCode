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

        ListNode* newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return newhead;

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* temp = head;
        int n = 1;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;

        while(temp!=NULL){
            if(n==left-1) a = temp;
            if(n==left)  b = temp;
            if(n==right) c = temp;
            if(n==right+1) d = temp;
            temp=temp->next;
            n++;
        }
        if(a!=NULL) a->next = NULL;
        c->next = NULL;

        c = reverse(b);

        if(a!=NULL) a->next = c;
        ListNode* t = c;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next = d;

        if(a!=NULL) return head;
        
        return c;
        
    }
};