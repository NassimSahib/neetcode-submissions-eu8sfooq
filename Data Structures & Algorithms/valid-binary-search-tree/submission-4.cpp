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
    bool isValidNode(TreeNode* node, int left, int right) {
        if (!node) return true;
        if (!(left < node->val && right > node->val)) return false;
        return isValidNode(node->left,left,node->val) &&
               isValidNode(node->right, node->val, right);
    }
    bool isValidBST(TreeNode* root) {
        return isValidNode(root, INT_MIN,INT_MAX); 
    }
};
