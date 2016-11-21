const ports = require('./build/Release/ports');

var gpio = ports.gpio(69);
var spi = ports.spi(1);

gpio.write(false);
gpio.write(true);
gpio.write(false);
gpio.write(true);
gpio.write(false);
