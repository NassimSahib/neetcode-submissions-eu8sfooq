class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> dict;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (dict.contains(complement)) {
                return {dict[complement], i};
            }

            dict[nums[i]] = i;
        }

        return {0,0}; 
        
    }
};
