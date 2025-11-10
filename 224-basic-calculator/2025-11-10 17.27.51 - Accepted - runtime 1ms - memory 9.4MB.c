int calculate(char *s) {
    int stack[20000];
    int top = -1;
    int res = 0, num = 0, sign = 1;

    for (char *p = s; *p; p++) {
        char c = *p;
        if (c == ' ') continue;

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            res += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
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

    if (num) res += sign * num;
    return res;
}
