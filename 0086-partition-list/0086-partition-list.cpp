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
    ListNode* partition(ListNode* head, int x) {
        ListNode* part1 = new ListNode(0);
        ListNode* part2 = new ListNode(0);

        ListNode* low = part1;
        ListNode* high = part2;

        while(head!=NULL){
            if(head-> val < x){
                low->next = head;
                head=head->next;
                low=low->next;
            }
            else{
                high->next = head;
                head=head->next;
                high=high->next;
            }
        }

        part1=part1->next;
        part2=part2->next;

        if(part1==NULL) return part2;
        if(part2==NULL) return part1;

        low->next = part2;
        high->next=NULL;
        return part1;
    }
};