class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int i,vector<int>& curr, int total, int target) {
        if (total == target) {
            res.push_back(curr);
            return;
        }
        if (total > target) return;
        if (i >= nums.size()) return;

        curr.push_back(nums[i]);
        dfs(nums, i, curr, total + nums[i], target);
        curr.pop_back();
        dfs(nums, i + 1, curr, total, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        dfs(nums, 0, curr, 0, target);

        return res;

    }
};
