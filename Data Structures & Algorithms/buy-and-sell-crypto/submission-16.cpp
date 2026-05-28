class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int globalMin = prices[0];
        int maxProf = 0;

        for (int i = 1; i < prices.size(); i++) {
            maxProf = max(prices[i] - globalMin, maxProf);
            globalMin = min(prices[i],globalMin);
        }

        return maxProf;
        
    }
};
