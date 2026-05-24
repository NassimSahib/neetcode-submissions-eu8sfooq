class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for (string s: strs) {
            res += to_string(s.size());
            res += "#";
            res += s;
        }

        return res;

    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res ;

        while (i < s.size()) {
            string t = "";
            while (s[i] != '#') {
                t += s[i];
                i++;
            }
            int adv = stoi(t);
            i++;
            string subs = s.substr(i,adv);
            res.push_back(subs);

            i += adv;

        }

        return res;

    }
};
