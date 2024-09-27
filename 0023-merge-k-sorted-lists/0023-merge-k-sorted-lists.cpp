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
    ListNode* mergetwo(ListNode* a,ListNode* b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* ans = new ListNode(100);  //beginning node
        ListNode* temp = ans;
        while(a!=NULL && b!=NULL){
            if(a->val  <=   b->val){
                temp->next = a;
                a=a->next;
                temp = temp->next;
            }
            else{
                temp->next = b;
                b=b->next;
                temp = temp->next;
            }

            if(a!=NULL){
                temp->next = a;
            }
            if(b!=NULL){
                temp->next = b;
            }
            
        }
        
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return  NULL;
        while(lists.size()>1){
            ListNode* a = lists[0];
            ListNode* b = lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            ListNode* add = mergetwo(a,b);
            lists.push_back(add);
        }
        return lists[0];
    }
};