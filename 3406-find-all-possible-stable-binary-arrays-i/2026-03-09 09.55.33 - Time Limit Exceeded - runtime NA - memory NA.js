/**
 * @param {number} zero
 * @param {number} one
 * @param {number} limit
 * @return {number}
 */
function numberOfStableArrays(zero, one, limit) {
    const MOD = 1e9 + 7;
    const memo = new Map();

    function dfs(z, o, last, run) {
        if (z === 0 && o === 0) return 1;

        const key = `${z},${o},${last},${run}`;
        if (memo.has(key)) return memo.get(key);

        let res = 0;

        
        if (z > 0) {
            if (last !== 0) {
                res = (res + dfs(z - 1, o, 0, 1)) % MOD;
            } else if (run < limit) {
                res = (res + dfs(z - 1, o, 0, run + 1)) % MOD;
            }
        }

        
        if (o > 0) {
            if (last !== 1) {
                res = (res + dfs(z, o - 1, 1, 1)) % MOD;
            } else if (run < limit) {
                res = (res + dfs(z, o - 1, 1, run + 1)) % MOD;
            }
        }

        memo.set(key, res);
        return res;
    }

    return dfs(zero, one, -1, 0);
}