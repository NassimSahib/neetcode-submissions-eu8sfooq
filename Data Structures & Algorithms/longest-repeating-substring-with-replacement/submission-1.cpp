class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26,0);

        int l = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            counts[s[r] - 'A']++;
            maxFreq = max(counts[s[r] - 'A'],maxFreq);

            while ((r - l + 1 ) - maxFreq > k) {
                counts[s[l] - 'A']--;
                l++;
            }
            ans = max(r - l + 1, ans);
        }

        return ans;
        
    }
};
