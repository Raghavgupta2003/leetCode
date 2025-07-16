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
    // when v = |a-b| will be max
    //case 1: a=max & b=min
    //case 2: a=min & c=max
    //what we store maximum from a ancsestor

    //we will do preorder and keep trak of max and min both
    int Maxi = 0;
    void traversal(TreeNode* root, int maximum, int minimum){
        if(root == NULL) return;

        maximum = max(maximum, root->val);
        minimum = min(minimum, root->val);

        Maxi = max(Maxi, abs(maximum - minimum));
        traversal(root->left, maximum, minimum);
        traversal(root->right, maximum, minimum);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maximum = root->val;
        int minimum = root->val;

        traversal(root, maximum, minimum);
        return Maxi;
    }
};