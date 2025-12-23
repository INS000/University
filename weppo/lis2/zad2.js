//zad1
var p = {}
p.a = 'haha'
p['b'] = 'hoho'

console.log(p.a)
console.log(p.b)


//zad2
var o = {}
o[1] = 50
o[2] = 20

console.log(o[1])
console.log(o[2])

const os = {
    name: 'Ania'
}

const key = {
    kl: 'name'
}

console.log(os[key.kl])


//zad3
const auta = ['BMW', 'Mercedes', 'Audi']
console.log(auta['1'])

const key2 = {
    kl: 2
}

console.log(auta[key2.kl])

auta['2'] = 'Skoda'

console.log(auta)

console.log(auta.length)

auta.length = 7
console.log(auta.length)
console.log(auta)

auta.length = 2
console.log(auta.length)
console.log(auta)

auta.length = 3
console.log(auta.length)
console.log(auta)
