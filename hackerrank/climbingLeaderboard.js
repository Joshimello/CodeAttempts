function climbingLeaderboard(ranked, player) {

    let ans = []
    let sb = [...new Set(ranked)]

    for (const score of player) {

        if (score >= sb[0]) {
            ans.push(1)
        } 

        else if (score < sb[sb.length - 1]) {
            ans.push(sb.length + 1)
        } 

        else {
        	ans.push(check(score, sb))
        }
    }

    return ans
}

const check = (score, sb) => {
    let start = 0
    let end = sb.length - 1

    while (true) {

        let mid = Math.floor((start + end) / 2)

        if (sb[mid] === score) {
            return mid + 1
        } 

        else if (sb[mid] > score && sb[mid + 1] < score) {
            return mid + 2
        } 

        else if (sb[mid] < score && sb[mid - 1 > score]) {
            return mid - 1
        }

        score < sb[mid] ? start = mid + 1 : end = mid - 1
    }
}


console.log(climbingLeaderboard([100, 100, 50, 40, 40, 20, 10], [5, 25, 50, 120]).join('\n'))