class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        if (n == 1) return 1;

        int longestSub = 0;
        unordered_map<char,int> hash;
        hash[s[0]]++;
        int l = 0;

        for (int r = 1; r < n; r++) {
            while (hash[s[r]] > 0) {
                hash[s[l++]]--;
            }
            hash[s[r]]++;
            longestSub  = max(r - l + 1, longestSub);
        }

        return longestSub;
        
    }
};
