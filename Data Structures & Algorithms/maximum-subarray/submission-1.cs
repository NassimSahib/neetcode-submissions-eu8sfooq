public class Solution {
    public int MaxSubArray(int[] nums) {
        int maxSub = nums[0];
        int currSum = 0;

        foreach (int n in nums)
        {
            if (currSum < 0)
            {
                currSum = 0; 
            }
            currSum += n;
            maxSub = Math.Max(maxSub, currSum);
        }

        return maxSub;

    }
}
