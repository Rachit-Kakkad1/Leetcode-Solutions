/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let i = num1.length - 1;
    let j = num2.length - 1;
    let carry = 0;
    let res = '';

    while (i >= 0 || j >= 0 || carry) {
        let x = i >= 0 ? num1.charCodeAt(i) - 48 : 0;
        let y = j >= 0 ? num2.charCodeAt(j) - 48 : 0;
        let sum = x + y + carry;
        res = (sum % 10) + res;
        carry = Math.floor(sum / 10);
        i--;
        j--;
    }

    return res;
};
