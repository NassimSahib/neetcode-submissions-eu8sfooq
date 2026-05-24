class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> s_(nums.begin(),nums.end());

        return nums.size() != s_.size();
    }
};