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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        ListNode* temp = head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        //cout<<size<<endl;
        int nodeToremove = size-n+1;
        //cout<<nodeToremove<<endl;
        int nodeToremoveIDX= nodeToremove-1; //0 based indexing

        if(nodeToremoveIDX==0){
            head=head->next;
            return head;
        }

        temp = head; //at position 1;
        for(int i=0;i<nodeToremoveIDX-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;

        return head;
    }
};