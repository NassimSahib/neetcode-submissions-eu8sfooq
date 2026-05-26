class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> hash = {{'(',')'},{'{','}'},{'[',']'}};
        stack<int> s_;

        for (char c: s) {
            if (hash.contains(c)) {
                s_.push(c);
            }
            else {
                if (s_.empty()) return false;
                char t = s_.top();
                s_.pop();
                if ((t == '(' && c != ')' ||
                    t == '{' && c != '}' ||
                    t == '[' && c != ']' )) return false;
            }
        }
        return s_.empty();
        
    }
};
