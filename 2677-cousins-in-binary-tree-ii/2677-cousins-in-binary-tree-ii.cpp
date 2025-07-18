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
    //we make array for levelSum
    void levelSumFxn(TreeNode* root, vector<int>& levelSum){
        queue<TreeNode*> q;
        q.push(root);

        while(q.size() > 0){
            int size = q.size();
            int sum = 0;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();

                sum += cur->val;

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            levelSum.push_back(sum);
        }
    }

    void replace(TreeNode* root, vector<int>& levelSum){
          // we will do our work before a level to target level(where we have to change)
        queue<TreeNode*> q;
        root->val = 0; //cousion of root = 0
        q.push(root);
        int level = 0;

        while(q.size() > 0){
            int size = q.size();
            
            level++;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();

                int leftChild = (cur->left) ? cur->left->val : 0;
                int rightChild = (cur->right) ? cur->right->val : 0;

                //sibling sum
                int siblingSum = leftChild + rightChild;

                if(cur->left){
                    cur->left->val = levelSum[level] - siblingSum;
                    q.push(cur->left);
                }

                 if(cur->right){
                    cur->right->val = levelSum[level] - siblingSum;
                    q.push(cur->right);
                }

            }
        }

    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum;
        levelSumFxn(root, levelSum);

        // for(int i=0; i<levelSum.size(); i++){
        //     cout<<levelSum[i]<<" ";
        // }

        replace(root, levelSum);

        return root;
    }
};