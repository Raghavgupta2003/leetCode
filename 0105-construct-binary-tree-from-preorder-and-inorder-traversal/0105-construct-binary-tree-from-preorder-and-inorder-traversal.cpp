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
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder, int &preIndex, int left, int right){
        if(left > right) return NULL;

        TreeNode* cur = new TreeNode(preorder[preIndex]);
        preIndex++;
        int positionInInorder = -1;
        for(int i=left; i<=right; i++){
            if(inorder[i] == cur->val){
                positionInInorder = i;
                break;
            }
        }

        cur->left = helper(preorder, inorder, preIndex, left, positionInInorder-1);
        cur->right = helper(preorder, inorder, preIndex, positionInInorder + 1, right);
        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return helper(preorder, inorder, preIndex, 0, inorder.size()-1);

    }
};