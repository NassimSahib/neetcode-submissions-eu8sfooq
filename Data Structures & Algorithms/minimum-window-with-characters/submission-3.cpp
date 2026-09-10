class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty() || t.size() > s.size()) return "";

        vector<int> need(128, 0);

        for (char c: t) {
            need[c]++;
        }

        int left = 0;
        int missing = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (need[c] > 0) {
                missing--;
            }

            need[c]--;

            while (missing == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                need[leftChar]++;

                if (need[leftChar] > 0) {
                    missing++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "": s.substr(start, minLen);
    }
};
