const ports = require('./build/Release/ports');

var gpio = ports.gpio(69);
var spi = ports.spi(1);

var counter = 1;

console.log(gpio.configure());
console.log(spi.configure());
console.log(gpio.interrupt(
	function (msg) {
		console.log("#" + counter, msg);
		counter++;
	}));