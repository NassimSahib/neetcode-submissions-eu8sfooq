class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> hash = {{')','('},
                                               {']','['},
                                               {'}','{'}};
        std::stack<int> s_;

        for (char c: s) {
            if (!hash.contains(c)) {
                s_.push(c);
            } else {
                if (s_.empty()) return false;
                char t = s_.top();
                s_.pop();

                if ((hash[c] != t)) return false;
            }
        }

        return s_.empty();
    }
};
