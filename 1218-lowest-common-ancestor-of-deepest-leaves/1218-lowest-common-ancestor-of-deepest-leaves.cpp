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
    bool lca(vector<TreeNode*>& v, TreeNode* a, TreeNode*root){
        if(root == NULL) return false;
        if(root->val == a->val){
            v.push_back(root);
            return true;
        }

        if(lca(v, a , root->left) || lca(v, a, root->right)){
            v.push_back(root);
            return true;
        }

        return false;
    }
    void postorder(TreeNode* root, vector<pair<TreeNode*, int>>& v, int l){
        if(root == NULL) return;
        
        v.push_back({root, l});
        postorder(root->left, v, l+1);
        postorder(root->right, v, l+1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL) return root;
        //TO find deepest Nodes
        //Do POSTorderTraversal

        vector<pair<TreeNode*, int>> v;
        int l = 0; //level
        postorder(root, v, l);
        
        // for(int i=0; i<v.size(); i++){
        //     cout<<v[i].first->val<<" "<<v[i].second<<endl;
        // }

        sort(v.begin(), v.end(), [](const pair<TreeNode*, int>& a, const pair<TreeNode*, int>& b) {
            return a.second < b.second;
        });
        
       vector<TreeNode*> NODESinLAST;
       int lastlevel = v[v.size()-1].second;

       for(int i=v.size()-1; i>=0; i--){
        if(v[i].second == lastlevel) NODESinLAST.push_back(v[i].first);
       } 
       
       if(NODESinLAST.size() == 1) return NODESinLAST[0];

       vector<vector<TreeNode*>> ans;
       for(int i=0; i<NODESinLAST.size(); i++){
            vector<TreeNode*> help;
            lca(help, NODESinLAST[i], root);
            reverse(help.begin(), help.end());
            ans.push_back(help);
       }

       //printing
       for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]->val<<" ";
        }
        cout<<endl;
       }

       //comparision

       int minLength = INT_MAX;
        for (const auto& path : ans) {
            minLength = min(minLength, (int)path.size());
        }

        for (int i = 0; i < minLength; i++) {
            TreeNode* current = ans[0][i];
            bool allMatch = true;
            for (int j = 1; j < ans.size(); j++) {
                    // Edge case: mismatch at root level
                    if (ans[j][i] != current) {
                        if (i == 0) return nullptr;
                        else return ans[0][i - 1];
                    }
            }
        }

        // All nodes matched up to the shortest path
        return ans[0][minLength - 1];

        
    }
};