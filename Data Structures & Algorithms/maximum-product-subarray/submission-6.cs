public class Solution {
    public int MaxProduct(int[] nums) {
        int max = nums.Max();
        int currMin = 1;
        int currMax = 1;
        
        foreach (int n in nums)
        {
            int tmp = n * currMax;
            currMax = Math.Max(n * currMax, n * currMin);
            currMax = Math.Max(currMax, n);
            currMin = Math.Min(tmp, n * currMin);
            currMin = Math.Min(currMin, n);
            max = Math.Max(currMax, max);
        }
    

        return max;
    }
}
