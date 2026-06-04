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
    unordered_map<int,int> indexMap;
    int preorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);

    }

    TreeNode* build(vector<int>& preorder,int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int rootValue = preorder[preorderIndex];
        preorderIndex++;

        TreeNode* root = new TreeNode(rootValue);

        int mid = indexMap[rootValue];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }
};
