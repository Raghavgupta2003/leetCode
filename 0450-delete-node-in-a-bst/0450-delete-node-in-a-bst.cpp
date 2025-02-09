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
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root == NULL) return NULL;

    if(val < root->val){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->val){
        root->right = deleteNode(root->right, val);
    }
    else{// val == root->val
        if(root->left == NULL && root->right == NULL){  //deleting leave node;
            delete root;
            return NULL;
        }
        else if(root->left != NULL  && root->right == NULL){//having only leftchild
            return root->left;
        }
        else if(root->right != NULL  && root->left == NULL){//having only rightchild
            return root->right;
        }
        else{
            //both left and right are not NULL
            //Two child Parent
            TreeNode* left_sub = root->left;
            TreeNode* right_sub = root->right;
            TreeNode* temp = root->left;

            while(temp->right){
                temp = temp->right; 
            }  // Temp is rightmost node of left SubTree
            temp->right = right_sub;
            return left_sub;
        }
    }
    return root;
    }
};