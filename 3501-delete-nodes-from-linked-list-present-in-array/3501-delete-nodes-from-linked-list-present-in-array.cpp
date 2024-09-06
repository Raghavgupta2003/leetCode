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
        // set<int>s;
        // for(int i=0;i<nums.size();i++){
        //     s.insert(nums[i]);
        // }
        // ListNode* cur = head;
        // if(s.find(head->val)!=s.end()){
        //     head=head->next;
        // }
        // while(cur->next->next!=NULL){
        //     int v = cur->next->val;
        //     if(s.find(v)!=s.end()){
        //         ListNode* temp = cur->next;
        //         cur->next=cur->next->next;
        //         free(temp);
        //     }
        //     cur->next;
        // }
        unordered_map<int,int>mp;
        for(auto i:nums)    mp[i]++;
        ListNode* curr=head;
        ListNode* prev=head;

        while(curr!=nullptr){
            if(mp[curr->val]>0){

                if(prev==curr){
                    if(head==curr) head=head->next;

                    curr=curr->next;
                    prev=curr;
                }else {
                    curr=curr->next;
                    prev->next=curr;
                }
            }
            else {
                prev=curr;
                curr=curr->next;

            }
        }

        return head;
    }
};