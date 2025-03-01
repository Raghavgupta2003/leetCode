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
class Solution {
public:
    TreeNode* insert(TreeNode* root, int val){
        TreeNode* newnode = new TreeNode(val);
        if(root == NULL){
            return newnode;
        }

        if(val < root->val){
            if(root->left == NULL) root->left = newnode;
            else insert(root->left, val);
        }
        else{
            if(root->right == NULL) root->right = newnode;
            else insert(root->right, val);
        }

        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root, val);
    }
};