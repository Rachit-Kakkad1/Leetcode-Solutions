/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let i = num1.length - 1;
    let j = num2.length - 1;
    let carry = 0;
    const res = [];

    // Core loop — O(n), no string concatenation
    while (i >= 0 || j >= 0 || carry) {
        const x = i >= 0 ? num1.charCodeAt(i) - 48 : 0;
        const y = j >= 0 ? num2.charCodeAt(j) - 48 : 0;
        const sum = x + y + carry;

        res.push(sum % 10);
        carry = (sum / 10) | 0; // Bitwise floor — faster than Math.floor
        i--;
        j--;
    }

    res.reverse();
    return res.join('');
};
