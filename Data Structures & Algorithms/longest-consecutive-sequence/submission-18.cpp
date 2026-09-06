class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::set<int> uniques(nums.begin(), nums.end());
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            int count = 1;
            int temp = nums[i];

            if (!uniques.contains(temp - 1)) {
                while (uniques.contains(temp + 1)) {
                    count++;
                    temp++;
                }
                
            }

            maxCount = std::max(count,maxCount);
        }

        return maxCount;
    }
};
