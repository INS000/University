function createFs(n) { // tworzy tablicę n funkcji
    var fs = []; // i-ta funkcja z tablicy ma zwrócić i
    for ( var i=0; i<n; i++ ) {
        fs[i] =
            (function (j) {
                return function () {
                    return j;
                };
            })(i);
        };
        return fs;
    }
    var myfs = createFs(10);
    console.log( myfs[0]() ); // zerowa funkcja miała zwrócić 0
    console.log( myfs[2]() ); // druga miała zwrócić 2
    console.log( myfs[7]() );


// 1) let działa tak jakbyśmy mieli tworzone do kazdego przypisania nową zmienna (tak jak dziala w babel)
// 2) działa, bo do funkcji ktora przyjmuje inna zmienna podstawia i wiec rzeczywiscie jest to nowa zmienna z przypisanym i
