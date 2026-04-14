class Solution {
public:
    int getValue(char ch) {
        if (ch == 'I') return 1;
        if (ch == 'V') return 5;
        if (ch == 'X') return 10;
        if (ch == 'L') return 50;
        if (ch == 'C') return 100;
        if (ch == 'D') return 500;
        return 1000;
    };

    int romanToInt(string s) {
        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            int curr = getValue(s[i]);
            int next = (i + 1 < s.length()) ? getValue(s[i + 1]) : 0;

            if (curr < next) {
                result -= curr;
            } else {
                result += curr;
            }
        }

        return result;
    }
};