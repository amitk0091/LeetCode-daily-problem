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
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*> q1;
        q1.push(root);
        TreeNode* n = NULL;
        while(!q1.empty()){
            n = q1.front();
            q1.pop();
            if(n->right) q1.push(n->right);
            if(n->left) q1.push(n->left);
        }
        return n->val;
    }
};