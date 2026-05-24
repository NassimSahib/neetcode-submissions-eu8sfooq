class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) return false;

        std::unordered_map<char,int> s_dict;
        std::unordered_map<char,int> t_dict;

        for (char c: s) {
            s_dict[c] += 1;
        }

        for (char c: t) {
            t_dict[c] += 1;
        }

        for (auto& [key,val]: s_dict) {
            if (s_dict[key] != t_dict[key]) return false;
        }

        return true;


    }
};
