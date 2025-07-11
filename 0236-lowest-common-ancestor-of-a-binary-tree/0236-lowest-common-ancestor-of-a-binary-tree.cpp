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
    // BRUTE FORCE : In this question, we find path to a node 
    //and travel backward in it

    bool pathToNode(TreeNode* root, TreeNode* node, vector<TreeNode*>& arr){
        if(root == NULL) return false;
        arr.push_back(root);
        if(root == node) return true;
   
        bool found = pathToNode(root->left, node, arr) || pathToNode(root->right, node, arr);

        if(found == false) arr.pop_back();

        return found;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1;
        pathToNode(root, p, arr1);

        vector<TreeNode*> arr2;
        pathToNode(root, q, arr2);

        for(int i=arr1.size()-1; i>=0; i--){
            for(int j=arr2.size()-1; j>=0; j--){
                if(arr1[i] == arr2[j]) return arr1[i];
            }
        }

        return NULL;
    }
};