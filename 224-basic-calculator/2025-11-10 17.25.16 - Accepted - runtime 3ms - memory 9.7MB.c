int calculate(char* s) {
    int stack[100000];
    int top = -1;
    int res = 0, num = 0, sign = 1;

    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == ' ') continue;

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
            stack[++top] = res;
            stack[++top] = sign;
            res = 0;
            sign = 1;
        } else if (c == ')') {
            res += sign * num;
            num = 0;
            int prevSign = stack[top--];
            int prevRes = stack[top--];
            res = prevRes + prevSign * res;
        }
    }

    res += sign * num;
    return res;
}
