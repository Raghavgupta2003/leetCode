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
class FindElements {
public:
    int val;
    set<int> s;
    TreeNode* root;
    void maketree(TreeNode* root, int val){
        if(root == NULL) return;
        root->val = val;
        s.insert(val);
        maketree(root->left, 2 * (root->val) + 1);
        maketree(root->right, 2 * (root->val) + 2);
    }
    
    FindElements(TreeNode* root) {
        val = 0;
        this->root = root;
        maketree(root, val);
    }
    bool find(int target) {
        if(s.find(target) == s.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */