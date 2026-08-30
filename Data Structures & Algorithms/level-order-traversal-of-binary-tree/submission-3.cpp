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
        vector<vector<int>> result;

        std::queue<TreeNode*> q_;
        q_.push(root);

        while (!q_.empty()) {
            int n = q_.size();
            std::vector<int> temp;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q_.front();
                if (node->left ) q_.push(node->left);
                if (node->right) q_.push(node->right);
                q_.pop();
            
                temp.push_back(node->val);
            }
            
            result.push_back(temp);
        }

        return result;
    }
};