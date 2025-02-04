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
    void reverse(ListNode* &head){
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* Next = NULL;
        while(cur!=NULL){
            Next = cur->next;
            cur->next = pre;
            pre = cur;
            cur= Next; 
        }
        head = pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* rev = new ListNode(10); //fake node
        ListNode* temp = head;
        ListNode* revtemp = rev;
        while(temp!=NULL){
            ListNode* newnode = new ListNode(temp->val);
            revtemp->next = newnode;
            temp = temp->next;
            revtemp=revtemp->next;    
        }
        revtemp->next = NULL;
        
        rev = rev->next; //it start from fake node that we made initially;

        reverse(rev);
        ListNode* t = rev;
        while(t!=NULL){
            cout<<t->val<<" ";
            t=t->next;
        }

        // traversing in both head and rev;
        while(head!=NULL && rev!=NULL){
            if(head->val != rev->val) return false;
            head=head->next;
            rev=rev->next;
        }

        return true;
        
    }
};