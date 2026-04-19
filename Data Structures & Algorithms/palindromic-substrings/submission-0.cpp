class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            // odd part
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res += 1;
                l -= 1;
                r += 1;
            }

            // even part
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res += 1;
                l -= 1;
                r += 1;
            }
            
        }

        return res;
    }
};
