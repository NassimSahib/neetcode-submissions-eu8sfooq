class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int globMin = prices[0];
        int maxP = 0;

        for (int i = 0; i < n; i++) {
            maxP = std::max((prices[i] - globMin),maxP);
            if (prices[i] < globMin)
                globMin = prices[i];
            
        }
        return maxP;
    }
};
