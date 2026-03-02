/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
function exist(board, word) {

    let rows = board.length
    let cols = board[0].length

    function search(r, c, index) {

        if (index === word.length) {
            return true
        }

        if (
            r < 0 ||
            c < 0 ||
            r >= rows ||
            c >= cols ||
            board[r][c] !== word[index]
        ) {
            return false
        }

        let temp = board[r][c]
        board[r][c] = "*"

        let found =
            search(r + 1, c, index + 1) ||
            search(r - 1, c, index + 1) ||
            search(r, c + 1, index + 1) ||
            search(r, c - 1, index + 1)

        board[r][c] = temp

        return found
    }

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {

            if (search(i, j, 0)) {
                return true
            }

        }
    }

    return false
}