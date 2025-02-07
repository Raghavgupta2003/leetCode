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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int &postIdx, int left,int right){
        if(left > right) return NULL;
        
        TreeNode* cur = new TreeNode(postorder[postIdx]);
        postIdx--;

        //Searching in inorder
        int idxInInorder = -1;
        for(int i = left; i <= right; i++){
            if(inorder[i] == cur->val) idxInInorder = i;
        }
        cur->right = helper(inorder, postorder, postIdx, idxInInorder+1, right);
        cur->left = helper(inorder, postorder, postIdx, left, idxInInorder-1);

        return cur;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size()-1;
        return helper(inorder, postorder, postIdx, 0, inorder.size()-1);
    }
};