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
    //IMPORTANT POINTS
    //In POST ORDER => last Index is root
    //lastIndex-1 is root->right
    //lastIndex-2 is root->left

    //so, our goal to find root node is done
    //if we found same root node inorder traversal then we also get information about left and right

    TreeNode* make(vector<int>& inorder, vector<int>& postorder, int& postorderIdx, int inorderleft, int inorderright, unordered_map<int, int>& m){
        if(inorderleft > inorderright) return NULL;

        TreeNode* root = new TreeNode(postorder[postorderIdx]);
        postorderIdx--;

        int positionInOrder = m[root->val]; //we cannot access by postorderIdx as we decrement it

        //now first we create right tree as postorder given

        root->right = make(inorder, postorder, postorderIdx, positionInOrder + 1, inorderright, m);

        root->left = make(inorder, postorder, postorderIdx, inorderleft ,positionInOrder - 1, m);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //for effective Search in inorder,
        //we hashmap it
        //want to find index by element

        unordered_map<int, int> m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        
        int postorderIdx = postorder.size()-1;
        return make(inorder, postorder, postorderIdx, 0, inorder.size()-1, m);
    }
};