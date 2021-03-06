/***
 * TESTING U8G2Lib
 * @hpsaturn 
 ***/

#include <Arduino.h>
#include <GUIUtils.hpp>
#include <status.hpp>

unsigned int tcount = 0;
bool toggle;

void testSensorLiveIcon(){
  gui.displaySensorLiveIcon();
}

void testSendDataIcon(){
  gui.displayDataOnIcon();
}

void testSavePrefIcon(){
  gui.displayPreferenceSaveIcon();
}

void (*functionPtr[])() = { 
  testSensorLiveIcon,
  testSendDataIcon,
  testSavePrefIcon
};

void setup(void) {
  Serial.begin(115200);
  Serial.println("\n== INIT SETUP ==\n");
  Serial.println("-->[SETUP] console ready");
  gui.displayInit();
  gui.showWelcome();
  gui.welcomeAddMessage("Sensor ready..");
  gui.welcomeAddMessage("GATT server..");
  gui.welcomeAddMessage("WiFi test..");
  gui.welcomeAddMessage("InfluxDB test..");
  gui.welcomeAddMessage("==SETUP READY==");

  randomSeed(A0);

  delay(4000);
}

void loop(void) {

  long rnd = random(0, 3);

  gui.pageStart();
  gui.displaySensorAverage(150);
  gui.displaySensorData(120, 230, 15, 3.5, 12.3, rnd*10);
  gui.displayStatus(true,true,true);
  functionPtr[rnd]();       // Call a test function in random sequence
  gui.pageEnd();

  delay(500);
}

