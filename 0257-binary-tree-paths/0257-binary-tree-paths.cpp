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
    // In this question, i will traverse in tree
    //if i found leaf node then return string or store in ans vector
    vector<string> ans;
    void path(TreeNode* root, string str){
        if(root == NULL) return;

        //if leaf node then insert str
        if(root->left == NULL && root->right == NULL){
            ans.push_back(str + to_string(root->val));
        }

        path(root->left, str + to_string(root->val)+"->");
        path(root->right, str + to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return {};

        string str="";

        path(root, str);

        return ans;
    }
};