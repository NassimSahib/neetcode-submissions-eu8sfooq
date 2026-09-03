class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;

        for (string s: strs) {
            string original = s;
            sort(s.begin(),s.end());
            hash[s].push_back(original);
        }

        for (auto [key, value]: hash) {
            res.push_back(value);
        }

        return res;
        
        
    }
};
