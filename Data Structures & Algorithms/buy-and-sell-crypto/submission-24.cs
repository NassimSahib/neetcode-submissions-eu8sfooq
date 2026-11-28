public class Solution {
    public int MaxProfit(int[] prices) {
        int globalMin = prices[0];
        int maxProf = 0;

        for (int i = 1; i < prices.Length; i++)
        {
            maxProf = Math.Max(prices[i] - globalMin, maxProf);

            if (prices[i] < globalMin)
            {
                globalMin = prices[i];
            }
        }

        return maxProf;
    }
}
