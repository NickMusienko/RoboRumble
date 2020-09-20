var express = require('express')
var app = express()
const port = 30500
app.listen(port, () => {
        console.log(`Example app listening at http://localhost:${port}`)
    })
    // respond with "hello world" when a GET request is made to the homepage
app.get('/', function(req, res) {
    res.send('hello world')
    console.log("got a get")
})


app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`)
})