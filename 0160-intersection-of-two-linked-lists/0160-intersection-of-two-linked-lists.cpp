/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int size1=0;
        while(temp1!=NULL){
            temp1=temp1->next;
            size1++;
        }
        int size2=0;
        while(temp2!=NULL){
            temp2=temp2->next;
            size2++;
        }

        temp1=headA;
        temp2=headB;
        if(size1>size2){
            int n=size1-size2;
            for(int i=1;i<=n;i++){
                temp1=temp1->next;
            }
        }
        else{
            int n=size2-size1;
             for(int i=1;i<=n;i++){
                temp2=temp2->next;
            }
        }
       
       while(temp1!= temp2){
        temp1=temp1->next;
        temp2=temp2->next;
       }
       return temp1;
    }
};