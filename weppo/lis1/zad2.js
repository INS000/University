function isDivisible(num) {
    const digits = num.toString().split('').map(Number);
    let sumOfDigits = 0;

    for (let digit of digits){
        sumOfDigits += digit;
    }

    for (let digit of digits) {
        if (digit === 0 || num % digit !== 0) {
            return false;
        }
    }

    if (num % sumOfDigits !== 0) {
        return false;
    }

    return true;
}

function setofDivisible() {
    let result = [];
    for (let num = 1; num <= 100000; num++) {
        if (isDivisible(num)) {
            result.push(num);
        }
    }
    return result;
}

const n = setofDivisible();
console.log(n);
