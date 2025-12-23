function Prime(n) {
    const notprime = [];
    const prime = [];

    for (let i = 2; i <= n; ++i) {
        if (!notprime[i]) {
            prime.push(i);
            for (let j = i << 1; j <= n; j += i) {
                notprime[j] = true;
            }
        }
    }

    return prime;
}

const p = Prime(100000);
console.log(p);
