class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> hash;
        std::vector<std::vector<string>> res;

        for (string s: strs) {
            string original = s;
            std::sort(s.begin(), s.end());
            hash[s].push_back(original);
        }

        for (const auto& [key, value]: hash) {
            res.push_back(value);
        }

        return res;
    }
};
