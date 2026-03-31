class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string word(n + m - 1, '?');

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool allFixed = true, match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?') allFixed = false;
                    if (word[i + j] != str2[j]) match = false;
                }
                if (allFixed && match) return "";
            }
        }

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    bool ok = true;

                    for (int start = max(0, i - m + 1); start <= min(i, n - 1); start++) {
                        bool match = true;
                        for (int j = 0; j < m; j++) {
                            if (word[start + j] != str2[j]) {
                                match = false;
                                break;
                            }
                        }
                        if (str1[start] == 'T' && !match) ok = false;
                        if (str1[start] == 'F' && match) ok = false;
                        if (!ok) break;
                    }

                    if (ok) break;
                }
                if (word[i] == '?') return "";
            }
        }

        return word;
    }
};