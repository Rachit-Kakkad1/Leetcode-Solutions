/**
 * @param {string} s
 * @return {number}
 */
function getValue(ch) {
    if (ch === 'I') return 1;
    if (ch === 'V') return 5;
    if (ch === 'X') return 10;
    if (ch === 'L') return 50;
    if (ch === 'C') return 100;
    if (ch === 'D') return 500;
    if (ch === 'M') return 1000;
}
var romanToInt = function(s) {
    let result = 0;

    for (let i = 0; i < s.length; i++) {
        let curr = getValue(s[i]);
        let next = getValue(s[i + 1]);

        if (next > curr) {
            result -= curr;
        } else {
            result += curr;
        }
    }

    return result;
};