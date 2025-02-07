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
    int sumOfLeftLeavesHelper(TreeNode* root, bool isLeft) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL ){
            if(isLeft) return root->val;
            else return 0;
        }
        return sumOfLeftLeavesHelper(root->left, 1) + sumOfLeftLeavesHelper(root->right, 0); 
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesHelper(root, 0);
    }
};


