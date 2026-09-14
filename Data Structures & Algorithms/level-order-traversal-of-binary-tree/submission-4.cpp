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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q_;
        q_.push(root);
        vector<vector<int>> res;

        while (!q_.empty()) {
            int size = q_.size();
            vector<int> temp;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q_.front();
                q_.pop();
                temp.push_back(node->val);
                if (node->left) q_.push(node->left);
                if (node->right) q_.push(node->right);
            }
            res.push_back(temp);
        }

        return res;
    }
};
