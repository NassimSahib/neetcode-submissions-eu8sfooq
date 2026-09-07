class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxA = 0;

        while (l < r ) {
            int minB = std::min(heights[l], heights[r]);

            int area = minB * (r - l);

            maxA = std::max(area, maxA);

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxA;
    }
};
