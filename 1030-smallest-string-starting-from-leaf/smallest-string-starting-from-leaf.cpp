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
    string reverseString( string st){
        for(int i=0;i<st.length()/2;i++){
            swap(st[i],st[st.length()-1-i]);
        }
        return st;
    }
    string smallestFromLeaf(TreeNode* root,string st="") {
        if(root==NULL) return "";
        if(root->left==NULL && root->right==NULL){
           st+=('a'+root->val);
            return reverseString(st);
        }
        string str = st;
        str += ('a'+root->val);
        string st1 = smallestFromLeaf(root->left,str);
        string st2 = smallestFromLeaf(root->right,str);
        if(root->left==NULL) return st2;
        else if(root->right==NULL) return st1;
        return (st1 <= st2 ? st1:st2);
    }
};