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
    int sumOfLeftLeaves(TreeNode* root,bool isLeft=false) {
        if(!root) return 0;
        if(root->left==NULL && root->right==NULL && isLeft) return root->val;
        int a = sumOfLeftLeaves(root->left,true);
        int b = sumOfLeftLeaves(root->right,false);
        return (a+b);
    }
};