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
    bool isBST(TreeNode* root, long min, long max){
        if(root == NULL) return true;

        if(root->val <= min || root->val >= max) return false;

        bool leftBST = isBST(root->left, min, root->val);
        bool rightBST = isBST(root->right, root->val, max);

        return leftBST && rightBST;
    }
    bool isValidBST(TreeNode* root) {
        long min = LONG_MIN;
        long max = LONG_MAX;

        return isBST(root, min, max);
    }
};