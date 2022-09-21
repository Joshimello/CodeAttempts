/**
 * @param {string} s
 * @param {number[]} shifts
 * @return {string}
 */
var shiftingLetters = function(s, shifts) {
    let numberArray = []
    for (let i = 0; i < s.split('').length; i++) {
        numberArray.push(s.split('')[i].charCodeAt(0) - 97)
    }

    var shiftList = shifts
    for (let i = 0; i < numberArray.length; i++) {
        numberArray[i] = (numberArray[i] + shiftList.reduce((a, b) => a + b, 0)) % 26
        shiftList.shift()
    }

    for (let i = 0; i < numberArray.length; i++) {
        numberArray[i] = String.fromCharCode(97 + numberArray[i])
    }

    return numberArray.join('')
};

// console.log(shiftingLetters("bad", [10,20,30]))