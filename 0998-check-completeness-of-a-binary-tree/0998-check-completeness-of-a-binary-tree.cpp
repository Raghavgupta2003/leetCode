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
    //since we know indexes concept
    //root->left = 2*i + 1;
    //root->right = 2*i + 2;
    //we count Number of nodes
    //then store nodes at their indexes in vector
    //at last check is their empty val in vector b/w two non empty
    int Nodes(TreeNode* root){
        if(root == NULL) return 0;

        int left = 1 + Nodes(root->left);
        int right = 1 + Nodes(root->right);

        return  left + right;
    }
    void traversl(int i, vector<int>& ans, TreeNode* root){
        if(root == NULL) return;
        if(i > ans.size()) return; //runtime
        ans[i] = root->val;
        
         traversl(2*i + 1, ans, root->left);
          traversl(2*i + 2, ans, root->right);

    }
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return root;
        int totalNodes = Nodes(root);

        vector<int> ans(totalNodes, -1);

        traversl(0, ans, root);

        for(int i=0; i<ans.size()-1; i++){
            if(ans[i]==-1 && ans[i+1]!=-1) return false;
        }
        return true;
    }
};