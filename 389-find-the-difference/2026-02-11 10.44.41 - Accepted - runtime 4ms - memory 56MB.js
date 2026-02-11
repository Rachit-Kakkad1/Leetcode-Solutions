/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
function findTheDifference(s, t) {
    let xor = 0;

    for (let ch of s + t) {
        xor ^= ch.charCodeAt(0);
    }

    return String.fromCharCode(xor);
}

