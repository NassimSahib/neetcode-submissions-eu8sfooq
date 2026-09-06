class Solution {
public:

    string encode(vector<string>& strs) {
        std:string s = "";

        for (string str: strs) {
            int len = str.size();
            s = s + std::to_string(len) + "#" + str;
        }

        return s;
    }

    vector<string> decode(string s) {
        std::vector<string> res;
        int i = 0;

        while (i < s.size()) {
            int l = i;

            while (s[l] != '#') {
                l++;
            }

            std::string strLen = s.substr(i, l-i);
            int len = std::stoi(strLen);
            res.push_back(s.substr(l + 1, len));

            i = l + 1 + len;
            
        }

        return res;
    }
};
