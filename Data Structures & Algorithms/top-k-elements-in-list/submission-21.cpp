class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> hash;
        std::vector<std::pair<int,int>> items;
        vector<int> result;

        for (int n: nums) {
            hash[n]++;
        }

        for (const auto& [key, freq]: hash) {
            items.push_back({key, freq});
        }

        std::sort(items.begin(), items.end(), [](auto& a,auto& b) {
            return a.second > b.second;
        });

        for (int i = 0; i < k; i++) {
            result.push_back(items[i].first);
        }

        return result;

    }
};
