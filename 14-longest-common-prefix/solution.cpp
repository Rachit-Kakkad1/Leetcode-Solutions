class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string px = strs[0];
        for (i = 1; i < strs.size(); i++) {
            while (strs[i].find(px) != 0) {
                px.pop_back();
                if (px.empty()) return "";
            }
        }

        return px;

        
    }
};