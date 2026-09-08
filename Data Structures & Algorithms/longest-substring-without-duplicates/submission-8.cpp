class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> hash;
        int maxLength = 0;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            hash[s[r]]++;

            while (hash[s[r]] > 1) {
                hash[s[l]]--;
                l++;
            }

            maxLength = std::max(r - l + 1, maxLength);
        }

        return maxLength;
    }
};
