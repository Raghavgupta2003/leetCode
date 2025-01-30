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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        temp = head;
        // cout<<size<<" ";

        vector<ListNode*> ans;
        int n = size/k;   // size of parts of ll
        int rem = size%k; //Initial list which have one size greater.

            while(temp!=NULL){
                ListNode* t = new ListNode(100);
                t->next = temp;
                ListNode* tc = t;
                for(int i=1; i<=n; i++){
                    temp = temp->next;
                    tc = tc->next;
                }
                if(rem>0){
                    temp = temp->next;
                    tc = tc->next;
                    rem--;
                }
                tc->next = NULL;

                ans.push_back(t->next);
            }
        if(ans.size()!=k){
            while(ans.size()!=k){
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};