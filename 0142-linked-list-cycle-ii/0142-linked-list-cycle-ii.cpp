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
        if(head==NULL || head->next==NULL) return NULL;
        unordered_map<ListNode*,int> m;
        
        ListNode* temp = head;
        int pos = 0;
        while(temp!=NULL){
            if(m.find(temp)!=m.end()) return temp;
            else m[temp] = pos;
            temp=temp->next;
            pos++;
        }
        return NULL;
    }
};