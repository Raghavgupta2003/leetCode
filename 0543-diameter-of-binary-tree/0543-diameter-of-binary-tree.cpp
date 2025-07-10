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
    //BRUTE FORCE:- travel in tree
    //for each node calculate leftheight + rightheight
    //compare it with maximum
    //return maximum
    int maxDia = INT_MIN;
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }

    void diameter(TreeNode* root){
        if(root == NULL) return;

        int leftheight = height(root->left);
        int rightheight = height(root->right);

        maxDia = max(maxDia, leftheight + rightheight);

        diameter(root->left);
        diameter(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxDia;
    }
};