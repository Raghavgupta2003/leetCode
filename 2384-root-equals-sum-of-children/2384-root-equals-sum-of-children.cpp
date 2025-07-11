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
    bool checkTree(TreeNode* root) {
        if(root == NULL) return true; //its left + right == NULL
        if(root->left == NULL && root->right == NULL) return true; //leave nodes

        int l=0;
        int r=0;
        if(root->left) l=root->left->val;
        if(root->right) r=root->right->val;

        return (root->val == l+r) && checkTree(root->left) && checkTree(root->right);
    }
};