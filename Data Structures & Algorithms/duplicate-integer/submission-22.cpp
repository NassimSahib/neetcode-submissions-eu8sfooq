class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> uniques(nums.begin(),nums.end());

        return nums.size() != uniques.size();
    }
};