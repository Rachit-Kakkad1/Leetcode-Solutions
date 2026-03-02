/**
 * @param {number[][]} grid
 * @return {number}
 */
function minSwaps(grid) {

    let n = grid.length
    let zeros = []

    for (let i = 0; i < n; i++) {

        let count = 0

        for (let j = n - 1; j >= 0; j--) {
            if (grid[i][j] === 0) {
                count++
            } else {
                break
            }
        }

        zeros.push(count)
    }

    let swaps = 0

    for (let i = 0; i < n; i++) {

        let need = n - 1 - i

        let j = i

        while (j < n && zeros[j] < need) {
            j++
        }

        if (j === n){ 
            return -1
        }

        while (j > i) {
            let temp = zeros[j]
            zeros[j] = zeros[j - 1]
            zeros[j - 1] = temp

            swaps++
            j--
        }
    }

    return swaps
}