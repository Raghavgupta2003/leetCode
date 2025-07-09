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
    // void preorder(TreeNode* root, vector<int>& ans){
    //     if(root == NULL) return;

    //     ans.push_back(root->val);
    //     preorder(root->left, ans);
    //     preorder(root->right, ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // preorder(root, ans);
        // return ans;

        if(root == NULL) return {};
        stack<TreeNode*> st;
        st.push(root);
        
        vector<int> ans;
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