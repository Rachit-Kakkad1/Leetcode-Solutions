int calculate(char* s) {
    int stack[1000];
    int top = -1;
    int res = 0, num = 0, sign = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            res += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            res += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            if (top < 998) {
                stack[++top] = res;
                stack[++top] = sign;
            }
            res = 0;
            sign = 1;
        } else if (c == ')') {
            res += sign * num;
            num = 0;
            if (top >= 1) {
                res *= stack[top--];
                res += stack[top--];
            }
        }
    }
    res += sign * num;
    return res;
}
