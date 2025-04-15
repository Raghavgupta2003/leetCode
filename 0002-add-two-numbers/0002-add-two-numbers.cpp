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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carry = 0;
//         ListNode* farzi = new ListNode(-1);
//         ListNode* temp = farzi;
//         while(l1!=NULL || l2!=NULL || carry!=0){
//             int digit1 = 0;
//             int digit2 = 0;
//             if(l1) digit1 = l1->val;
//             if(l2) digit2 = l2->val;

//             int sum = digit1 + digit2 + carry;

//             int digit = sum % 10; //unit place digit;
//             carry = sum/10;

//             ListNode* newnode = new ListNode(digit);
//             temp->next = newnode;
//             temp = temp->next; 

//             if(l1) l1 = l1->next;
//             if(l2) l2 = l2->next;           

//         }
//         return farzi->next;
//     }
// };

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carry = 0;
//         ListNode* farzi = new ListNode(-1);
//         ListNode* temp = farzi;
//         while(l1!=NULL || l2!=NULL){
//             int digit1 = 0;
//             int digit2 = 0;
//             if(l1) digit1 = l1->val;
//             if(l2) digit2 = l2->val;

//             int sum = digit1 + digit2 + carry;

//             int digit = sum % 10; //unit place digit;
//             carry = sum/10;

//             ListNode* newnode = new ListNode(digit);
//             temp->next = newnode;
//             temp = temp->next; 

//             if(l1) l1 = l1->next;
//             if(l2) l2 = l2->next;           

//         }
//         if(carry!=0){
//             int sum = carry;
//             int digit = sum % 10; //unit place digit;
//             carry = sum/10;
//             ListNode* newnode = new ListNode(digit);
//             temp->next = newnode;
//             temp = temp->next; 
//         }

//         return farzi->next;
//     }
// };



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum =0;
        int digit = 0;
        ListNode* farzi = new ListNode(-1);
        ListNode* temp = farzi;
        while(l1!=NULL && l2!=NULL){
            sum = l1->val + l2->val + carry;

            digit = sum % 10; //unit place digit;
            carry = sum/10;

            ListNode* newnode = new ListNode(digit);
            temp->next = newnode;
            temp = temp->next; 

            l1 = l1->next;
            l2 = l2->next;           

        }
        while(l1!=NULL){
            int sum = l1->val + carry;

            int digit = sum % 10; //unit place digit;
            carry = sum/10;

            ListNode* newnode = new ListNode(digit);
            temp->next = newnode;
            temp = temp->next; 

            l1 = l1->next;
        }
        while(l2!=NULL){
            int sum = l2->val + carry;

            int digit = sum % 10; //unit place digit;
            carry = sum/10;

            ListNode* newnode = new ListNode(digit);
            temp->next = newnode;
            temp = temp->next; 

            l2 = l2->next;
        }
        if(carry!=0){
            ListNode* newnode = new ListNode(carry);
            temp->next = newnode;
        }

        return farzi->next;
    }
};