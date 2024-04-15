/*
129. Sum Root to Leaf Numbers
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

    For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
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
    void call(TreeNode* root, int c)
    {
        if(!root)
        {
            return;
        }
        c=c*10+root->val;
        if(root->left==NULL and root->right==NULL)
        {
            ans+=c;
            return;
        }
        call(root->left, c);
        call(root->right, c);
    }
    int sumNumbers(TreeNode* root) {
        call(root, 0);
        return ans;
        
    }
};
