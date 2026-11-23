public class Solution {
    public int[] TwoSum(int[] nums, int target) {
    Dictionary<int,int> hashMap = new Dictionary<int,int>();

    for (int i = 0; i < nums.Length; i++) 
    {
        int complement = target - nums[i];

        if (hashMap.ContainsKey(complement))
        {
            return new int[] { hashMap[complement], i };
        }

        hashMap[nums[i]] = i;
    }

    return Array.Empty<int>();
    }
}
