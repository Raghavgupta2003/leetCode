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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while(q.size() >  0){
            int size = q.size();
            level++;

            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();

                if(level == depth-1){

                    TreeNode* oldleft = cur->left;
                    TreeNode* oldright = cur->right;

                    TreeNode* a = new TreeNode(val);
                    TreeNode* b = new TreeNode(val);

                    cur->left = a;
                    cur->right = b;

                    a->left = oldleft;
                    b->right = oldright;

                }

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);

            }
            
        }
        
        return root;
    }
};