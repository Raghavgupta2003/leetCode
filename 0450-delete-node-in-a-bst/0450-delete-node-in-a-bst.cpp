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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{ //root->val == key

        if(root->left == NULL && root->right == NULL) return NULL; //leafNode;
        else if(root->left!=NULL && root->right == NULL) return root->left; //having only left child;
        else if(root->left==NULL && root->right!=NULL) return root->right; //having only right child;
        else{//having both child;

        TreeNode* subtree = root->right;
        TreeNode* subtreetemp = subtree;
        while(subtreetemp->left!=NULL){
            subtreetemp = subtreetemp->left;
        }
        subtreetemp->left = root->left;

        return subtree;



        }

        }
        return root;
    }
};