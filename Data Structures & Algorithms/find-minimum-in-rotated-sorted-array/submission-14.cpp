class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return nums[l];
        
    }
};
