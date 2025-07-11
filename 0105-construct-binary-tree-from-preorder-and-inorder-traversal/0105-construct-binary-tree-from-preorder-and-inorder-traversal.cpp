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
    TreeNode* make(vector<int>& inorder, vector<int>& preorder, int& preorderIdx, int leftinorder, int rightinorder, unordered_map<int, int>& m){
        if(leftinorder > rightinorder) return NULL;

        //making root node
        TreeNode* root = new TreeNode(preorder[preorderIdx]);
        preorderIdx++; //increament to get next root in recursion

        //position in inorder of root
        int positionInInorder = m[root->val];

        //connecting leftsubtree and rightsubtree to root

        root->left = make(inorder, preorder, preorderIdx, leftinorder, positionInInorder - 1, m);

        root->right = make(inorder, preorder, preorderIdx, positionInInorder + 1, rightinorder, m);


        //returning root;
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //in this question, we know that starting ele of preorder is rootNode
    //Now, we find this node in order, so that we left part of that is left subtree
    //and right part of that is right subtree

    //But for efficient searching for index of the element(root) inorder array,  we store inorder traversal in hasmap
        
        //hashing inorder
        unordered_map<int, int> m;
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        
        int preorderIdx = 0; //root element
        int leftinorder = 0;
        int rightinorder = inorder.size()-1;
        return make(inorder, preorder, preorderIdx, leftinorder, rightinorder, m);

    }
};