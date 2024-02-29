/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q1;
        q1.push(root);
        int level = 0;
        while (!q1.empty()) {
            int sz = q1.size();
            int pre = (level % 2 == 0 ? -1 : INT_MAX);
            for (int i = 0; i < sz; i++) {
                TreeNode* n = q1.front();
                if (level % 2 == 0 && n->val % 2 == 1) {
                    if (pre >= n->val)
                        return false;
                    pre = n->val;
                } 
                else if(level%2 ==0 ) return false;
                else if (level % 2 == 1 && n->val % 2 == 0) {
                    if (pre <= n->val)
                        return false;
                    pre = n->val;
                }
                else return false;
                if (n->left)
                    q1.push(n->left);
                if (n->right)
                    q1.push(n->right);
                q1.pop();
            }
            level++;
        }
        return true;
    }
};