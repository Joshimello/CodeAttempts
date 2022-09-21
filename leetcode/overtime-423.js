/**
 * @param {string} s
 * @return {string}
 */
var originalDigits = function(s) {

    var ar = s.split('')
    var num = ''

    const numbers = {
        '0': ['z','e','r','o'],
        '1': ['o','n','e'],
        '2': ['t','w','o'],
        '3': ['t','h','r','e','e'],
        '4': ['f','o','u','r'],
        '5': ['f','i','v','e'],
        '6': ['s','i','x'],
        '7': ['s','e','v','e','n'],
        '8': ['e','i','g','h','t'],
        '9': ['n','i','n','e']
    }


    while (ar.length > 0) {

        for (var number in numbers) {

            if (numbers[number].every(v => ar.includes(v))) {
                numbers[number].forEach(i => {
                    ar.splice(ar.indexOf(i), 1)
                })

                num = num + number
            }

        }

    }

    return num
    
}

console.log(originalDigits())