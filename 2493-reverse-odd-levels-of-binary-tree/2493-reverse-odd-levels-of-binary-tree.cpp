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
    TreeNode* createTree(int i ,vector<int> &arr){
        if(i>=arr.size()) return NULL;

        TreeNode* root = new TreeNode(arr[i]);
        root->left = createTree(2*i + 1 ,arr);
        root->right = createTree(2*i + 2 ,arr);

        return root;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while(q.size() >0){
            int size = q.size();
            vector<int> help;
            cnt++;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();

                help.push_back(cur->val);

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(cnt % 2 == 0) reverse(help.begin(), help.end());
            ans.push_back(help);
        }
        
        vector<int> arr;
        for(int i=0; i<ans.size(); i++){
            for(int j=0; j<ans[i].size(); j++){
                arr.push_back(ans[i][j]);
                cout<<ans[i][j]<<" ";
            }
        }

        return createTree(0 ,arr);
    }
};