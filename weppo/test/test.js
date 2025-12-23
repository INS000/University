function Singleton() {
    return class Singleton {
    static instance;
    static getInstance() {
    if (!this.instance) this.instance = new this();
return this.instance;
}
}
}
// sic! dziedziczenie z wartości zwracanej z funkcji!
class Car extends Singleton() {
paint(color){
this._color = color;
}
}
// inna klasa dziedziczy swoją "kopię"
class Person extends Singleton() {
print() {
// osoby nie mają koloru
return this._color;
}
}
// car1 i car2 to ten sam obiekt
let car1 = Car.getInstance();
car1.paint('red');
let car2 = Car.getInstance();
console.log( car2._color );
// person to już inny obiekt
let person = Person.getInstance();
console.log( person._color );
