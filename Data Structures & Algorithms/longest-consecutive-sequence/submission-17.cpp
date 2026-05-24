class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> uniq(nums.begin(), nums.end());

        int maxSeq = 0;

        for (int x: nums) {
            if (!uniq.contains(x - 1)) {
                int current = x;
                int seq = 1;

                while (uniq.contains(current + 1)) {
                    current++;
                    seq++;
                }
                maxSeq = max(seq,maxSeq);
            }
        }

        return maxSeq;
        
    }
};
