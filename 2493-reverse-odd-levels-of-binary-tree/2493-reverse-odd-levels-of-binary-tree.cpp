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
   // we will store odd level nodes in vector
   // and revere its values by while loop.
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return {};

        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while(q.size() >0){
            int size = q.size();
            vector<TreeNode*> help;
            cnt++;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();

                if(cnt % 2 == 0) help.push_back(cur); //only odd level

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(cnt % 2 == 0){
                int i=0;
                int j=help.size()-1;
                while(i<=j){
                    swap(help[i]->val, help[j]->val);
                    i++;
                    j--;
                }
            }
        }
        

        return root;
    }
};