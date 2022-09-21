/**
 * @param {string} s
 * @return {number}
 */
var numSteps = function(s) {
    let n = BigInt('0b' + s)
    let steps = 0
    while (n != 1n) {
        if (n % 2n == 1n) {
            n += 1n
        } else {
            n /= 2n
        }

        steps++
    }
    return steps
}