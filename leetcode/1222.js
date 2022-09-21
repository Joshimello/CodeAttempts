/**
 * @param {number[][]} queens
 * @param {number[]} king
 * @return {number[][]}
 */
var queensAttacktheKing = (queens, king) => {
    
    let top = []
    for (let i = king[0] - 1; i >= 0; i--) {
        top.push([i, king[1]])
    }
    
    let right = []
    for (let i = king[1] + 1; i < 8; i++) {
        right.push([king[0], i])
    }
    
    let bottom = []
    for (let i = king[0] + 1; i < 8; i++) {
        bottom.push([i, king[1]])
    }
    
    let left = []
    for (let i = king[1] - 1; i >= 0; i--) {
        left.push([king[0], i])
    }
    
    let topright = []
    for (let i = 0; i <= (top.length <= right.length ? top.length : right.length) - 1; i++) {
        topright.push([top[i][0], right[i][1]])
    }

    let bottomright = []
    for (let i = 0; i <= (bottom.length <= right.length ? bottom.length : right.length) - 1; i++) {
        bottomright.push([bottom[i][0], right[i][1]])
    }

    let bottomleft = []
    for (let i = 0; i <= (bottom.length <= left.length ? bottom.length : left.length) - 1; i++) {
        bottomleft.push([bottom[i][0], left[i][1]])
    }

    let topleft = []
    for (let i = 0; i <= (top.length <= left.length ? top.length : left.length) - 1; i++) {
        topleft.push([top[i][0], left[i][1]])
    }

    let queensString = []
    for (let i = 0; i < queens.length; i++) {
        queensString.push(String(queens[i]))
    }

    const directions = [topleft, top, topright, right, bottomright, bottom, bottomleft, left]
    let canAttack = []

    loop1:
    for (let i = 0; i < directions.length; i++) {
        loop2:
        for (let j = 0; j < directions[i].length; j++) {
            if (queensString.includes(String(directions[i][j]))) {
                canAttack.push(directions[i][j])
                break loop2
            }
        }
    }

    return canAttack
}

// console.log(queensAttacktheKing([[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], [3,4]))