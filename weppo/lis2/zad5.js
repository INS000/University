let object = {
    pole: 'aaa',

    metoda: function(){
        return `Metoda, ${object}`
    },

    get getter(){
        return this.pole
    },

    set setter(n){
        this.pole = n
    }
}


console.log(object.getter())
