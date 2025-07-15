/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* sub = NULL;
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p == NULL && q == NULL) return true;
//         if(p == NULL && q != NULL) return false;
//         if(p != NULL && q == NULL) return false;
        
//         if(p->val != q->val) return false;
        
//         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//     }
//     bool ans = false;
//     void check(TreeNode* root, TreeNode* subRoot){
//         if(root == NULL) return;

//         if(root->val == subRoot->val){ 
//             sub = root;
//             if(isSameTree(sub, subRoot)){
//                 ans = true;
//                 return;
//             };
//         }
//         check(root->left, subRoot);
//         check(root->right, subRoot);
//     }
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         check(root, subRoot);

//         return ans;
//     }
// };


//---------------------------------------------------


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;
        
        if(p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
   
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(subRoot == NULL) return true;
       if(root == NULL) return false;

       if(root->val == subRoot->val){
        if(isSameTree(root, subRoot)) return true;
       }

       bool left = isSubtree(root->left, subRoot); 
       bool right = isSubtree(root->right, subRoot); 

       return left || right;

    }
};