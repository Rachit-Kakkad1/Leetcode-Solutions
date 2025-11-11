char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0;
    int k = (i > j ? i : j) + 2; 
    char* res = (char*)malloc(k * sizeof(char));
    res[--k] = '\0'; 

    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? num1[i--] - '0' : 0;
        int y = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = x + y + carry;
        res[--k] = (sum % 10) + '0';
        carry = sum / 10;
    }

    return res + k; 
