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
    ListNode *detectCycle(ListNode *head) {
        // if(head==NULL || head->next==NULL) return NULL;
        // unordered_map<ListNode*,int> m;
        
        // ListNode* temp = head;
        // int pos = 0;
        // while(temp!=NULL){
        //     if(m.find(temp)!=m.end()) return temp;
        //     else m[temp] = pos;
        //     temp=temp->next;
        //     pos++;
        // }
        // return NULL;

        //----------------------slow fast pointer-----------------

        ListNode* slow = head;
        ListNode* fast = head;
        bool flag=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag = true;
                break;
            }
        }
        if(flag==false) return NULL;
        ListNode* temp = head;
        while(slow!=temp){
            slow=slow->next;
            temp=temp->next;
        }

        return temp;


    }
};