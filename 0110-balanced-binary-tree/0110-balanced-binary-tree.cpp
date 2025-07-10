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
//     int height(TreeNode* root){
//         if(root == NULL) return 0;

//         int left = height(root->left);
//         int right = height(root->right);

//         return 1 + max(left, right);
//     }
//     bool isBalanced(TreeNode* root) {
//         //balance means abs(rightheight - leftheeight) <= 1
//         if(root == NULL) return true; 

//         int leftheight = 0;
//         int rightheight = 0;

//         if(root->left) leftheight = height(root->left);
//         if(root->right) rightheight = height(root->right);

//         if(abs(leftheight - rightheight) > 1) return false;

//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);

//         if(left == false || right == false) return false;

//         return true;

//         //it means any one of abs(leftheight - rightheight <= 1) && isBalanced(root->left) && isBalanced(root->right)
//         //if anyone false return false;
//         //if all true then return true
//     }
// };


//----------------------OPTIMAL-------------------------------
//by using height code, and whenever we found false condition return -1
// if height == -1 means unbalanced

class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        if(left == -1 || right == -1) return -1;
        if(abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
       int h = height(root);

       if(h == -1) return false;
       return true;
    }
};