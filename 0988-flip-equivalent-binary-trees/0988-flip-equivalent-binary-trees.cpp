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
    bool ans = true;
    bool isSame(TreeNode* root1, TreeNode*root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 != NULL && root2 == NULL) return false;
        if(root1 == NULL && root2 != NULL) return false;
       

        if(root1->val != root2->val) return false; //when root not equal then swapping left right not work

        bool rootNotflipped = isSame(root1->left, root2->left) && isSame(root1->right, root2->right);

        bool rootflipped = isSame(root1->left, root2->right) && isSame(root1->right, root2->left);

        return rootNotflipped || rootflipped;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return isSame(root1, root2);
    }
};