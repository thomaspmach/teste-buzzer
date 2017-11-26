(function() {
  'use strict';

  class BleDevice {

    /**********************************************************************
    * The BleDevice class is a object used to represent the BLE peripheral.
    **********************************************************************/
    
    constructor() {
      this.eddystoneServiceUuid = 0xFEAA;
      this.buzzerServiceUuid = '917649a3-d98e-11e5-9eec-0002a5d5c51b';
      this.buzzerCharacteristicUuid = '917649a4-d98e-11e5-9eec-0002a5d5c51b';
      this.buzzerCharacteristic = null;
    }

    connect(){
      return navigator.bluetooth.requestDevice({
        filters:[{name: "Buzzer",}],
        optionalServices: [this.buzzerServiceUuid]
      }).then(device => {
        this.device = device
        console.log(device)
        return device.gatt.connect()
      })
      .then(server => {
        this.server = server
        console.log(server)
        return server.getPrimaryService(this.buzzerServiceUuid)
      })
      .then(service => {
        console.log(service)
        return service.getCharacteristic(this.buzzerCharacteristicUuid)
      })
      .then(characteristic => {
        console.log(characteristic)
        this.buzzerCharacteristic = characteristic
      })
      .catch(error => {
        console.log('Argh! ' + error);
      });
    }

    writeBuzzerCharacteristic(value){
      this.buzzerCharacteristic.writeValue(value)
        .then(() => console.log('wrote ' + value[0]))
        .catch(error => {console.log('write error');
        });
    }
  }

  // makes the buzzer object available to therest of the program
  window.bleDevice = new BleDevice();

})();
