class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> hash;
        int maxFrequency = 0;
        int maxLength = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            hash[s[r]]++;

            maxFrequency = std::max(hash[s[r]], maxFrequency);
            while ((r - l + 1) - maxFrequency > k) {
                hash[s[l]]--;
                l++;
            }

            maxLength = std::max(r - l + 1, maxLength);
        }

        return maxLength;
        
    }
};
