class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int globalMin = prices[0];
        int maxProf = 0;

        for (int i = 1; i < prices.size(); i++) {
            maxProf = std::max(prices[i] - globalMin, maxProf);

            if (prices[i] < globalMin) {
                globalMin = prices[i];
            }
        }

        return maxProf;
    }
};
