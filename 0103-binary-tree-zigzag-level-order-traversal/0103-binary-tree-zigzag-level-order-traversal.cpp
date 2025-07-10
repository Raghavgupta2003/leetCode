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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        while(q.size() > 0){
            int size = q.size();

            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur->val);

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(ans.size() % 2 != 0){
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
        }
        return ans;      
    }
};