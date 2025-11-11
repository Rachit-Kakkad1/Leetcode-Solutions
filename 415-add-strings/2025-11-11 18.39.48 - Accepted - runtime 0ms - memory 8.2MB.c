char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0;
    int maxlen = (i > j ? i : j) + 1;
    char* res = (char*)malloc(maxlen + 2);
    res[maxlen + 1] = '\0';
    int pos = maxlen;
    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? num1[i--] - '0' : 0;
        int y = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = x + y + carry;
        res[pos--] = (sum % 10) + '0';
        carry = sum / 10;
    }
    return res + pos + 1;
}

