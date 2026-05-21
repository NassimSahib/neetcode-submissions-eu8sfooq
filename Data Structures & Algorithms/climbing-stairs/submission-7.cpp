class Solution {
public:
    std::map<int, int> dict;
    int climbStairs(int n) {
        
        dict[0] = 0;
        dict[1] = 1;

        return f(n);

    }

    int f(int x) {
        if (x == 0 || x == 1) return 1;

        if (dict.contains(x)) {
            return dict[x];
        } else {
            dict[x] = f(x - 1) + f(x - 2);
            return dict[x];
        }
        
    }


};
