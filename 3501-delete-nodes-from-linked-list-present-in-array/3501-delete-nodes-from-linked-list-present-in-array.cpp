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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        while(head->next!=NULL){
            int a= head->val;
            if(s.find(a)!=s.end()){
                head=head->next;
            }
            else break;
        }
        ListNode* cur = head;
        while(cur->next!=NULL && cur->next->next!=NULL){
            int a= cur->next->val;
            if(s.find(a)!=s.end()){
                cur->next=cur->next->next;
                continue;
            }
            cur=cur->next;
        }
        if(cur->next!=NULL && s.find(cur->next->val)!=s.end()){
            cur->next=NULL;
        }
        

        cout<<cur->val;
        
        return head;
    }
};