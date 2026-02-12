/**
 * @param {string} s
 * @return {string[][]}
 */
function partition(s) {
    const result = [];
    const path = [];

    function backtrack(start) {
        if (start === s.length) {
            result.push([...path]);
            return;
        }

        for (let end = start; end < s.length; end++) {
            if (isPalindrome(s, start, end)) {
                path.push(s.substring(start, end + 1));
                backtrack(end + 1);
                path.pop(); 
            }
        }
    }

    backtrack(0);
    return result;
}

function isPalindrome(str, left, right) {
    while (left < right) {
        if (str[left] !== str[right]) return false;
        left++;
        right--;
    }
    return true;
}
