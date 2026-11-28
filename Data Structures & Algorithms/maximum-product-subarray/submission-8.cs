public class Solution {
    public int MaxProduct(int[] nums) {
        int res = nums.Max();
        int currMin = 1;
        int currMax = 1;

        foreach (int n in nums)
        {
            int tmp = currMax * n;
            currMax = Math.Max(currMax * n, currMin * n);
            currMax = Math.Max(currMax, n);

            currMin = Math.Min(tmp, currMin * n);
            currMin = Math.Min(currMin, n);

            res = Math.Max(currMax, res);
        }

        return res;
    }
}
