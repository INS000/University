function fibonacciIterative(n) {
    if (n <= 1) {
        return n;
    }
    let prev = 0;
    let current = 1;
    for (let i = 2; i <= n; i++) {
        let temp = current;
        current = prev + current;
        prev = temp;
    }
    return current;
}

function fibonacciRecursive(n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

function measureTime(func, n) {
    console.time(`n = ${n}`);
    func(n);
    console.timeEnd(`n = ${n}`);
}

for (let n = 10; n <= 40; n += 5) {
    measureTime(fibonacciIterative, n);
    measureTime(fibonacciRecursive, n);
}
