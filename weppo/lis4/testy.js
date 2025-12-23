function Foo() {
    this.prop = 1;
}

Foo.prototype.say = function() {
    return this.prop;
}

var foo1 = new Foo();
var foo2 = new Foo();
console.log( foo1.say() );
