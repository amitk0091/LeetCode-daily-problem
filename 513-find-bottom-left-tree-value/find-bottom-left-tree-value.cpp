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
        int level =-1;
        int ans = -1;
        queue<pair<TreeNode*,int>> q1;
        q1.push({root,0});
        while(!q1.empty()){
            TreeNode* n = q1.front().first;
            int curLevel = q1.front().second;
            q1.pop();
            if(n->left) q1.push({n->left,curLevel+1});
            if(n->right) q1.push({n->right,curLevel+1});
            if(curLevel != level){
                level = curLevel;
                ans = n->val;
            }
        }
        return ans;
    }
};