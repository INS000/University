function fib(n: number): number {
    if (n == 0){
        return 0
    }
    if (n == 1){
        return 1
    }
    else{
        return fib(n-1)+fib(n-2)
    }
}

function memoize(fn: Function): Function {

    var cache: { [key: number]: any} = {};

    return function(n: number){
        if (n in cache){
            return cache[n]
        }
        else{
            var result = fn(n)
            cache[n] = result
            return result
        }
    }
}

const memofib = memoize(fib)

console.time("memofib")
memofib(40)
console.timeEnd("memofib")

console.time("fib")
memofib(40)
console.timeEnd("fib")
