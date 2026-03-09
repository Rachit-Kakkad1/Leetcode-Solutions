class Solution {
public:
    string largestEven(string r) {
        int lt = -1;

        for (int i = 0; i < r.size(); i++) {
            if (r[i] == '2')
                lt = i;
        }

        if (lt == -1)
            return "";

        return r.substr(0, lt + 1);
    }
};