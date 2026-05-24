class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> dict;

        for (string s: strs) {
            string base = s;
            sort(base.begin(),base.end());
            dict[base].push_back(s);
        }

        for (auto& [base,anagrams]: dict) {
            res.push_back(anagrams);
        }

        return res;
    }
};
