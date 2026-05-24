class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<pair<int,int>> ref;
        vector<int> res;

        for (int n: nums) {
            hash[n]++;
        }

        for (auto& [key,value]: hash) {
            ref.push_back({key,value});
        }

        sort(ref.begin(),ref.end(),[](auto& f, auto& s) {
            return f.second > s.second;
        });

        for (auto& p: ref) {
            res.push_back(p.first);
            if (res.size() == k) return res;
        }

        return res;
    }
};
