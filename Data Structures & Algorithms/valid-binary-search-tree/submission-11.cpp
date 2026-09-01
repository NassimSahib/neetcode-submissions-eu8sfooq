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
    bool helperBST(TreeNode* root, long long int min_val , long long int max_val) {

        if (!root) return true;
        if (!(root->val > min_val && root->val < max_val)) {
            return false;
        }

        return (helperBST(root->left, min_val, root->val) && 
               helperBST(root->right, root->val, max_val));
    }
    bool isValidBST(TreeNode* root) {
        return helperBST(root, INT_MIN, INT_MAX);
    }
};

