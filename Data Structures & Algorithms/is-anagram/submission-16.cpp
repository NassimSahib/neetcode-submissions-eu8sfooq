class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> hashS;
        std::unordered_map<char, int> hashT;

        for (char c: s) {
            hashS[c]++;
        }

        for (char c: t) {
            hashT[c]++;
        }

        for (const auto [c, v]: hashS) {
            if (v != hashT[c]) return false;
        }
        
        return true;
    }
};
