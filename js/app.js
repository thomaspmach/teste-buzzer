var buzzerON = false;

var buzzerButton = function()
{
  buzzerON = !buzzerON;
  if (buzzerON) {
    $("#buzzer-button-text").html("OFF");
    bleDevice.writeBuzzerCharacteristic(new Uint8Array([1]))
  }
  else {
    $("#buzzer-button-text").html("ON");
    bleDevice.writeBuzzerCharacteristic(new Uint8Array([0]))
  }
  console.log(buzzerON);
};

/**
  * The Web Bluetooth API specifies that a user action like a click is needed to
  * initiate a connection.
  */
function bleConnect() {
  bleDevice.connect()
};


