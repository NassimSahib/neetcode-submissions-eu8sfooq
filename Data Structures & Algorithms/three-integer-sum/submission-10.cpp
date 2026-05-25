class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i-1] == nums[i]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    r--;
                    l++;

                    while (l < r && nums[l-1] == nums[l]) l++;
                    while (l < r && nums[r+1] == nums[r]) r--;
                }
                
                else if (sum > 0) {
                    r--;
                } 
                else {
                    l++;
                }
            }
        }
        return res;
    }
};
