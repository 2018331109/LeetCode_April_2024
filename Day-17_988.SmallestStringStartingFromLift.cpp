/*
988. Smallest String Starting From Leaf
You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

    For example, "ab" is lexicographically smaller than "aba".

A leaf of a node is a node that has no children.
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
class Solution
{
public:
    string ans="|";
    void call(TreeNode* root, string c)
    {
        if(!root) return;
        c=string(1, root->val+'a')+c;
        if(!root->left and !root->right)
        {
            ans=min(ans, c);
            return;
        }
        call(root->left, c);
        call(root->right, c);
    }
    string smallestFromLeaf(TreeNode* root)
    {
        call(root, "");
        return ans;
    }
};

