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
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int x = 1;
        while(q.size()>0){
            int size = q.size();
            vector<int> v;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left){
                   q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
                v.push_back(cur->val);
             }
             if(x%2 == 0) reverse(v.begin(), v.end());
             x++;
             ans.push_back(v);
        }
        return ans;
    }
};