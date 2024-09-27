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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);

        ListNode* oddtemp = odd;
        ListNode* eventemp = even;

        int i=1;
        while(head!=NULL){
            if(i%2==0){
                eventemp->next=head;
                head=head->next;
                eventemp = eventemp->next;
            }
            else{
                oddtemp->next=head;
                head=head->next;
                oddtemp = oddtemp->next;
            }
            i++;
        }
        oddtemp->next = even->next; //connecting both linkedlist
        eventemp->next = NULL;

        return odd->next;
        
    }
};