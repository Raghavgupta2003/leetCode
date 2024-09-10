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
    int gcd(int a,int b){
        if(a<b) return gcd(b,a);
        if(a%b==0) return b;
        return gcd(a-b,b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* cur) {
        ListNode* head= cur;
        while(head->next != NULL){
            int a = head->val;
            int b = head->next->val;
            int hcf = gcd(a,b);
            ListNode* mid = new ListNode(hcf);
            mid->next = head->next;
            head->next =  mid;
            
            head=head->next->next;
        
        }
        return cur;
    }
};