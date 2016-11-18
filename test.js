const ports = require('./build/Release/ports');

var gpio = new ports.gpio(69);
console.log(gpio.setValue(true));
setTimeout(function () {
    console.log(gpio.setValue(false));
}, 500);
