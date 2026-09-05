class Solution {
public:
    int maxC = 0;
    string longestP = "";
    
    void dfs(string s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }

        int length = r - l - 1;
        if (length> longestP.size()) {
            maxC= count;
            longestP = s.substr(l+1, length);
        }
    }
    
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            dfs(s, i, i);
            dfs(s, i, i + 1);
        }

        return longestP;
    }
};
