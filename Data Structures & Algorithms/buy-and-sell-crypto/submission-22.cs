public class Solution {
    public int MaxProfit(int[] prices) {
        if (prices.Length == 0) return 0;

        int globalMin = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.Length; i++) 
        {
            int currProfit = prices[i] - globalMin;
            maxProfit = Math.Max(maxProfit, currProfit);

            if (prices[i] < globalMin)
            {
                globalMin = prices[i];
            }
        }

        return maxProfit;

    }
}
