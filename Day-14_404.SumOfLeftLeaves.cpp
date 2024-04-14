/*
404. Sum of Left Leaves
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
*/
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
    int ans=0;
    void call(TreeNode* &root)
    {
        if(root==NULL) return;
        if(root->left != NULL)
        {
            if(root->left->left == NULL and root->left->right == NULL)
            {
                ans+=root->left->val;
            }
        }
        call(root->left);
        call(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {

        call(root);
        return ans;

    }
};
