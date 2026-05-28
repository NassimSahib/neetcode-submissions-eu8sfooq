class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        string res = "";

        vector<int> counts(128,0);

        for (char c: t) {
            counts[c]++;
        }

        int l = 0;
        int bestLen = INT_MAX;

        int bestStart = 0;
        int missing = t.size();

        for (int r = 0; r < s.size(); r++) {
            if (counts[s[r]] > 0) {
                missing--;
            }

            counts[s[r]]--;

            while (missing == 0) {
                int len = r - l + 1;

                if (len < bestLen) {
                    bestLen = len;
                    bestStart = l;
                }

                counts[s[l]]++;
                if (counts[s[l]] > 0) {
                    missing++;
                }
                l++;
            }

            
        }
        if (bestLen == INT_MAX) return "";
        return s.substr(bestStart,bestLen);
        
    }
};
