char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0;
    int len = (i > j ? i : j) + 2;
    char* res = (char*)malloc(len * sizeof(char));
    res[len - 1] = '\0';
    int pos = len - 2;
    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? num1[i--] - '0' : 0;
        int y = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = x + y + carry;
        res[pos--] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (pos >= 0) {
        memmove(res, res + pos + 1, len - pos - 1);
    }
    return res;
}
