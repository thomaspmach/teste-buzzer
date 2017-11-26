#include <CurieBLE.h>
/**
 * Example demonstrating blinking LEDs with Web Bluetooth
 * There is nothing specific in this sketch for the Web Bluetooth API.
 * The Web Bluetooth specific portion is contained on the web site
 * for this "Physical Web" device. After constructing the circuit and
 * uploading the sketch to your arduino/genuio101, log onto this website 
 * with your Chrome browser:
 * 
 *    https://lachendekatze.github.io/wb-blink101/
 *    
 *      and click away!   
 */

// pins for each LED specified here
#define BLECONNECT 3
#define BUZZER 11


/* establish BLE service & characteristics */
BLEPeripheral blePeripheral;
BLEService buzzerService("917649a3-d98e-11e5-9eec-0002a5d5c51b");
BLEUnsignedCharCharacteristic buzzerCharacteristic("917649a4-d98e-11e5-9eec-0002a5d5c51b", BLEWrite);

int buzzerData = 0;

void setup() 
{
  // initiate serial communications for debugging
  Serial.begin(9600);
  Serial.println("web bluetooth-arduino101 buzzer example");
  
 /** 
   *  BLE initilizations
   */

  blePeripheral.setLocalName("buzzer");
  blePeripheral.setAdvertisedServiceUuid(buzzerService.uuid());
  blePeripheral.addAttribute(buzzerService);
  blePeripheral.addAttribute(buzzerCharacteristic);
  blePeripheral.setEventHandler(BLEConnected, blePeripheralConnectHandler);
  blePeripheral.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);
  buzzerCharacteristic.setEventHandler(BLEWritten, buzzerCharacteristicWritten);

  //setup the BLE Conect LED
  pinMode(BLECONNECT, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  buzzerCharacteristic.setValue(0);
  blePeripheral.begin();  
}

void loop() 
{
  if (buzzerData) {
    buzzerMusic();
  }
  else {
    digitalWrite(BUZZER, LOW);
  }
}

void blePeripheralConnectHandler(BLECentral& central) 
{
  // central connected event handler
  Serial.print("Connected event, central: ");
  Serial.println(central.address());
  //may notice slight lag/latency between connect and LED on
  digitalWrite(BLECONNECT, HIGH);
}

void blePeripheralDisconnectHandler(BLECentral& central) 
{
  // central disconnected event handler
  Serial.print("Disconnected event, central: ");
  Serial.println(central.address());
  digitalWrite(BLECONNECT, LOW);
}

void buzzerCharacteristicWritten(BLECentral& central, BLECharacteristic& characteristic)
{
  /**
   * toggle LEDs based on selection
   */
  buzzerData = buzzerCharacteristic.value();
}  

void buzzerMusic()
{
  if(buzzerData) {
    delay(100);
    tone(BUZZER,262,200); //DO
  }  
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,294,300); //RE
  }  
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,330,300); //MI
  }  
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,349,300); //FA
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,349,300); //FA
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,349,300); //FA
  }
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,262,100); //DO
  }
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,294,300); //RE
  }  
  if(buzzerData) {  
    delay(200);   
    tone(BUZZER,262,100); //DO
  }  
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,294,300); //RE
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,294,300); //RE
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,294,300); //RE
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,262,200); //DO
  }  
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,392,200); //SOL
  }  
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,349,200); //FA
  }  
  if(buzzerData) {
    delay(200);
    tone(BUZZER,330,300); //MI
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,330,300); //MI
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,330,300); //MI
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,262,200); //DO
  }  
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,294,300); //RE
  }  
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,330,300); //MI
  }  
  if(buzzerData) {  
    delay(200);
    tone(BUZZER,349,300); //FA
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,349,300); //FA
  }  
  if(buzzerData) {  
    delay(300);
    tone(BUZZER,349,300); //FA
    delay(300);  
  }  
}

