function isOwn(obj, prop) {
    return obj.hasOwnProperty(prop); //hasOwn lepsze ale w nodzie nie ma =C
}

var p = {
    name: 'jan'
}

var q = {
    surname: 'kowalski'
}

Object.setPrototypeOf( p, q );

console.log( p.name );
console.log( p.surname );

console.log( isOwn(p, 'name') );
console.log( isOwn(p, 'surname') );

console.log("\nPola/funkcje w obiekcie p: ")
for (var key in p){
    if(isOwn(p, key))
        console.log(key)
}

console.log("\nPola/funkcje w obiekcie i prototypach p: ")
for (var key in p){
    if(isOwn(p, key))
        console.log(key)

    var prototype = Object.getPrototypeOf(p)
    while (prototype) {
        if (isOwn(prototype, key)) {
            console.log(prototype, key);
        }
        prototype = Object.getPrototypeOf(prototype)
    }
}
