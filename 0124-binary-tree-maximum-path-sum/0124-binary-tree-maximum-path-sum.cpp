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
    int maxPath = INT_MIN;

    //this pathSum fxn is basically to calculate maximum path of root node to any leaf Node.
    int pathSum(TreeNode* root){
        if(root == NULL) return 0;

        // int leftSum = pathSum(root->left);
        // int rightSum = pathSum(root->right);
        // with above lines we are getting error in testcases like [2, -1], which reduce path with negative
        //no, we will not consider negative

        int leftSum = max(0, pathSum(root->left));
        int rightSum = max(0, pathSum(root->right));

        maxPath = max(maxPath, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        pathSum(root);

        return maxPath;
    }
};