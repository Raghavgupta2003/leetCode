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
    int widthOfBinaryTree(TreeNode* root) {
        // we will try to give index to each node level wise
        //or what i can say i store given indexes in vector of vector
        // 0 based indexing:
        //left child index = 2 * i + 1;
        //right child index = 2 * i + 2;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maximum = INT_MIN;
        while(q.size() > 0){
            int size = q.size();
            
            vector<long long> help;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front().first;
                int idx = q.front().second;
                q.pop();
                
                help.push_back(idx);

                if(cur->left){
                    q.push({cur->left, 1LL* 2 * idx +1});
                }

                if(cur->right){
                    q.push({cur->right, 1LL* 2*idx + 2});
                }
            }
            maximum = max(maximum, help[help.size()-1] - help[0] + 1);
        }

        return maximum;
    }
};