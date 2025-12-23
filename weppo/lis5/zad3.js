const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const r = Math.floor(Math.random() * 101)

function Gra() {
    rl.question('Podaj liczbę od 0 do 100: ', (ans) => {
        const l = parseInt(ans)

        if (l === r) {
            console.log('Brawo trafiles!!')
            rl.close()
        }
        else if (l < r) {
            console.log('Liczba jest wieksza')
            Gra()
        }
        else {
            console.log('Liczba jest mniejsza')
            Gra()
        }
    })
}

Gra()
