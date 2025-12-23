function getLastProto(o) {
    var p = o;
    do {
        o = p;
        p = Object.getPrototypeOf(o);
    } while (p);
    return o;
}


var o = {
    foo: null
}

var p = {
    name : 'jan',
say : function() {
    return this.name;
    }
};

var proto = {
    foo1: 1,
    bar: 2
}

console.log(getLastProto(p))

if (getLastProto(o) === getLastProto(proto) && getLastProto(proto) === getLastProto(p)){
    console.log('1')
} else {
    console.log('2')
}
