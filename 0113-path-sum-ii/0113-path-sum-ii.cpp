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
    vector<vector<int>> arr;
    void path(TreeNode* root, int targetSum, vector<int>& ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            targetSum -= root->val;
            if(targetSum == 0){
                ans.push_back(root->val);
                arr.push_back(ans);
                ans.pop_back();
            }
            return;
        }

        ans.push_back(root->val);
        path(root->left, targetSum - root->val, ans);
        path(root->right, targetSum - root->val, ans);

        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;

        path(root, targetSum, ans);

        return arr;
    }
};