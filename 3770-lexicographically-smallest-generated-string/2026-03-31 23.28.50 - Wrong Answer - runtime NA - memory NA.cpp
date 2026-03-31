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

       
        for (char &c : word) {
            if (c == '?') c = 'a';
        }

       
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool changed = false;

                    for (int j = m - 1; j >= 0; j--) {
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != str2[j]) {
                                word[i + j] = c;
                                changed = true;
                                break;
                            }
                        }
                        if (changed) break;
                    }

                    if (!changed) return "";
                }
            }
        }

        
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        return "";
                    }
                }
            }
        }

        return word;
    }
};