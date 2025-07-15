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
    // vector<int> ans;
    // void preorder(TreeNode* root){
    //     if(root == NULL) return;

    //     ans.push_back(root->val);
    //     preorder(root->left);
    //     preorder(root->right);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // preorder(root);

        // return ans;
        
        if(root == NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while(st.size() > 0){
            TreeNode* cur = st.top();
            ans.push_back(cur->val);

            st.pop();

            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return ans;
    }
};