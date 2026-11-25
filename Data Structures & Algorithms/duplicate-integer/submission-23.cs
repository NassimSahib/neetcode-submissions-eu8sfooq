public class Solution {
    public bool hasDuplicate(int[] nums) {
        HashSet<int> unique = new HashSet<int>(nums);
        return nums.Length != unique.Count;
    }
}