class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int maxA = 0;

        while (l < r) {
            int minH = min(heights[l],heights[r]);
            int newArea = (r - l) * minH;
            maxA = max(newArea, maxA);

            if (heights[l] < heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return maxA;
        
    }
};
