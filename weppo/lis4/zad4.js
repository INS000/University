var n = 1;

console.log(typeof n);
console.log(typeof Object.getPrototypeOf(n));

n.foo = "foo";
console.log(n.foo);

console.log(n.toFixed(2));

// W JS prototypem liczby jest object.
// Nie można zapisać do liczby pola.
// Ale można wywołać na wartościach metody typu zatem wystepuje niejawna kowersja na objekt wiec ma property
