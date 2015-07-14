// Module node-susiiot demo
// Reads Capability Json from ADVANTECH platform

var sensorLib = require('node-susiiot');

var sensor = {
    read: function () {
        var readout = sensorLib.getCapability();
        console.log('Capability Json: ' + readout );
        setTimeout(function () {
            sensor.read();
        }, 2000);
    }
};

sensor.read();

