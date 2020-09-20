//Express setup
const express = require('express')
const bodyParser = require('body-parser');
const fs = require('fs');
const app = express()
const port = 8080

var color = 0;
//SerialPort setup
const SerialPort = require('serialport')
const uart = new SerialPort('/dev/ttyUSB0')

/* Middlewares */
app.use(express.static('src'));
app.use(bodyParser.urlencoded({ extended: false }));

app.get('/', (req, res) => {
  console.log(req.param.value_1)
  res.sendFile(index.html)

})

app.post('/', function (req, res) {
  const body = req.body; // your request body
  console.log(body)

  if(body.direction == undefined){
    if(body.bot == 'blue'){
      uart.write('1', function(err) {
        if (err) {
          return console.log('Error on write: ', err.message)
        }
        console.log('message written')
      })
    }else{
      uart.write('2', function(err) {
        if (err) {
          return console.log('Error on write: ', err.message)
        }
        console.log('message written')
      })
    }
  }else{
    switch(body.direction){
      case  "up":
      uart.write('f', function(err) {
        if (err) {
          return console.log('Error on write: ', err.message)
        }
        console.log('message written')
      })
      break;
      case  "down":
      uart.write('b', function(err) {
        if (err) {
          return console.log('Error on write: ', err.message)
        }
        console.log('message written')
      })
      break;
      case  "left":
      uart.write('l', function(err) {
        if (err) {
          return console.log('Error on write: ', err.message)
        }
        console.log('message written')
      })
      break;
      case  "right":
      uart.write('r', function(err) {
        if (err) {
          return console.log('Error on write: ', err.message)
        }
        console.log('message written')
      })
      break;
    }
  }
  res.redirect('back');
  // your "magical" code

});

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`)
})