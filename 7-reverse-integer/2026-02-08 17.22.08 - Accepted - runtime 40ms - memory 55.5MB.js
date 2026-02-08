/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const INT_MIN = -2147483648;
    const INT_MAX = 2147483647;

    let rev = 0;

    while (x !== 0) {
        let digit = x % 10;

      
        x = (x / 10) | 0;

        
        if (rev > Math.floor(INT_MAX / 10) || 
           (rev === Math.floor(INT_MAX / 10) && digit > 7)) return 0;

        if (rev < Math.ceil(INT_MIN / 10) || 
           (rev === Math.ceil(INT_MIN / 10) && digit < -8)) return 0;

        rev = rev * 10 + digit;
    }

    return rev;
};
