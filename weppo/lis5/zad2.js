console.log("Podaj swoje imie")

process.stdin.on('readable', () => {
    let chunk;
    chunk = process.stdin.read()
    process.stdout.write(`Witaj ${chunk}`);
});


