/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
function findTheDifference(s, t) {
    const count = {};

    for (let ch of t) {
        count[ch] = (count[ch] || 0) + 1;
    }

    for (let ch of s) {
        count[ch]--;
    }

    for (let ch in count) {
        if (count[ch] > 0) return ch;
    }
}
