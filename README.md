# node-susiiot

This node.js module supports SUSI IoT Json API function from ADVANTECH platform.

## Installation
``` bash
$ npm install node-susiiot
```

## Usage

This module uses the SUSI IoT API & SUSI driver that requires access to 
/open/mem. Because of this, you will typically run node with admin privileges.

If the initialization succeeds when you can call the getCapability & getData function to obtain the latest readout from the ADVANTECH platform. 
Readout Json values contains all platform SUSI IoT features value. (like: temperature, GPIO...etc)
You also can use setData by Json to control the feature like GPIO, brightness.

### First Example

This sample queries the SUSIIoT platform Capability Json and displays the result on the console. 

``` javascript
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

```

### Reference for building from source

Standard node-gyp commands are used to build the module.

1. Generate the configuration files
``` bash
$ node-gyp configure
```
2. Build the component
``` bash
$ node-gyp build
```

### References

[1]: Node.js latest release - http://nodejs.org/dist/latest/

[2]: SUSI API - http://www2.advantech.tw/products/SUSI-API/sub_7ECC9263-4178-4E8D-A9CF-3397A2128FFA.aspx

[3]: SUSI Driver download (by platform)- http://support.advantech.com.tw/support/SearchResult.aspx?keyword=AIMB-215%20B1&searchtabs=%20Utility,Software%20Utility,Software%20API

[4]: Node.js native addon build tool - https://github.com/TooTallNate/node-gyp

## License
Copyright 2014, 2015 ADVANTECH Corp. under [the Apache 2.0 license](LICENSE).

