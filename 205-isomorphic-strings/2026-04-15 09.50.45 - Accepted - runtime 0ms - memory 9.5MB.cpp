class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            if (mp.count(a)) {
                if (mp[a] != b) {
                    return false;
                };
            } else {
                for (auto it : mp) {
                    if (it.second == b) {
                        return false;
                    };
                }
                mp[a] = b;
            }
        }

        return true;
    }
};