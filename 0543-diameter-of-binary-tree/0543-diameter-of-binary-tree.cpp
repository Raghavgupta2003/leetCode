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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void Diameter(TreeNode* root, int &maxi){
        if(root == NULL) return;
        int left = height(root->left);
        int right = height(root->right);

        maxi = max(left + right , maxi);
        Diameter(root->left, maxi);
        Diameter(root->right, maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // trick we calculate diameter = left height + right height
        //the maximum value we get of diameter return;

        int maxi = -1;
        Diameter(root, maxi);
        return maxi;
    }
};