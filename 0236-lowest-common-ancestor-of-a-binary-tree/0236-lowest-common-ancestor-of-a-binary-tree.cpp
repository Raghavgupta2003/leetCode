/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   // Applications -> Distance of two nodes
    bool path(vector<TreeNode*>& v, TreeNode* root, TreeNode* n){
        if(root == NULL) return false;

        if(root->val == n->val){
            v.push_back(root);
            return true;
        }

        if(path(v,root->left,n) || path(v,root->right,n)){
            v.push_back(root);
            return true;
        }

        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        path(v1, root, p);
        vector<TreeNode*> v2;
        path(v2, root, q);
        
        int i = v1.size()-1;
        int j = v2.size()-1;
        
        while(i>=0 && j>=0){
            if(v1[i] == v2[j]){
                i--;
                j--;
            }
            else{
                return v1[i+1];
            }
        }
        if(i<v1.size()) return v1[i+1];
        if(j<v2.size()) return v2[j+1];

        return NULL;
    }
};