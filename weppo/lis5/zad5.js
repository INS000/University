const http = require('http');

function readPagecon(url) {
    return new Promise((resolve, reject) => {
        http.get(url, (res) => {
            let content = ''

            res
                .on('data', (data) => {
                    content += data
                })

                .on('end', () => {
                    resolve(content)
                })

                .on('error', (error) => {
                    reject(error)
                });
        })
    })
}

let url = "http://google.com"

readPagecon(url)
    .then((content) => {
        console.log(content)
    })
