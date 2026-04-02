/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var selfDividingNumbers = function(left, right) {
    const result = [];
    
    for (let num = left; num <= right; num++) {
        let temp = num;
        let isValid = true;
        
        while (temp > 0) {
            let digit = temp % 10;
            
            if (digit === 0) {
                isValid = false;
                break;
            }
            
            if (num % digit !== 0) {
                isValid = false;
                break;
            }
            
            temp = Math.floor(temp / 10);
        }
        
        if (isValid) {
            result.push(num);
        }
    }
    
    return result;
};