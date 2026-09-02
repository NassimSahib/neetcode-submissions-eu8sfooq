class Solution {
public:
    bool isValid(string s) {
        std::stack<char> s_;
        std::unordered_map<char, char> map_ =
                                       {{')','('},
                                        {'}','{'},
                                        {']','['}};

        for (char c: s) {
            if (!map_.contains(c)) {
                s_.push(c);
            } else {
                if (s_.empty()) return false;
                char t = s_.top();
                s_.pop();

                if (c == ')' && map_[c] != t ||
                    c == ']' && map_[c] != t ||
                    c == '}' && map_[c] != t) return false;
            }
        }

        return s_.empty();
    }
};
