public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> hash = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++)
        {
            int complement = target - nums[i];

            if (hash.ContainsKey(complement))
            {
                return new int[] {hash[complement], i};
            }
            hash[nums[i]] = i;
        }

        return new int[] {0, 0};
    }
}
