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
    
    ListNode* rev(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* revhead = rev(head->next);
        head->next->next = head;
        head->next = NULL;

        return revhead;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {

       if(head==NULL || head->next==NULL) return head;

        ListNode *temp = head;
        ListNode* left_ = NULL;
        for(int i=1;i<left;i++){
            if(i==left-1)  left_ = temp;
            temp=temp->next;
        }
        ListNode *dup = new ListNode(0);
        ListNode* duptemp = dup;

        for(int i=left;i<=right;i++){
            ListNode* newnode = new ListNode(temp->val);
            duptemp->next = newnode;

            duptemp = duptemp->next;
            temp=temp->next;
        }
        
        ListNode* right_ = temp;
        dup = dup->next;

        ListNode* reverse = rev(dup);

        ListNode* revtemp = reverse;
        while(revtemp->next!=NULL){
            revtemp=revtemp->next;
        }
        revtemp->next = right_;

        if(left_!=NULL){
            left_->next = NULL;
            left_ -> next = reverse;
        }
        else{
            return reverse;
        }
        return head;

        
    }
};