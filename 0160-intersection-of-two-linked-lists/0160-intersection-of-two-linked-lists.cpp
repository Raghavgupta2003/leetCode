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

        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int A = 0; 
        int B = 0;
        while(tempA!=NULL){
            tempA = tempA->next;
            A++;
        }
        while(tempB!=NULL){
            tempB = tempB->next;
            B++;
        }

        tempA = headA;
        tempB = headB;
        if(A>B){
            for(int i=1; i<= A-B; i++){
                //  if(tempA==NULL) return NULL;
                tempA=tempA->next;
            }
        }else{
            for(int i=1; i<= B-A; i++){
                // if(tempB==NULL) return NULL;
                tempB=tempB->next;
            }
        }

        while(tempA!=NULL){
            if(tempA==tempB) return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }

        return NULL;

        
    }
};