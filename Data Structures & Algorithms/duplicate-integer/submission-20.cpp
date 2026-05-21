class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> s_(nums.begin(), nums.end());

        return s_.size() != nums.size();
        
    }
};