class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> vec1(nums.begin() + 1, nums.end());
        vector<int> vec2(nums.begin(), nums.end() - 1);
        return max(helper(vec1), helper(vec2));
    }

    int helper(vector<int>& numeros) {
        int rob1 = 0;
        int rob2 = 0;

        for (int n: numeros) {
            int new1 = max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = new1;
        }
        return rob2;
    }
};
