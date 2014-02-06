//analog inputs
#define moisture_input 0
#define divider_top 2
#define divider_bottom 3
#include <EasyTransfer.h>

//create object
EasyTransfer ET; 


//analog settings
const int VAL_PROBE = 0; // Analog pin 0
//leds
int progressLED = 13;
int badLED = 9;
int goodLED = 8;

//moisture levels
const int air = 0;
const int prettyDry = 250;
const int wet = 300;
//


int moisture; // analogical value obtained from the experiment

//data to send to arduino2
struct SEND_DATA_STRUCTURE{
  int progressLED;
  int badLED;
  int goodLED;
  int prettyDry;
  int moisture_level;
};
SEND_DATA_STRUCTURE mydata;
//

/*
exerpimental percentage calculator
doesnt work. lol.
*/
int int2percent(int x){
  char* y;
  if (x >= 300){
    y = "80%. Moderately damp.";
  }
  if (x <= 10){
    y = "10%. Very dry";
  }
  if (x >= 500){
    y = "This is way too wet 100%+";
  }
  return y;
}

int SoilMoisture(){
  int reading;
  digitalWrite(progressLED, HIGH);
  // set driver pins to outputs
  pinMode(divider_top,OUTPUT);
  pinMode(divider_bottom,OUTPUT);

  // drive a current through the divider in one direction
  digitalWrite(divider_top,LOW);
  digitalWrite(divider_bottom,HIGH);

  // wait a moment for capacitance effects to settle
  delay(1000);
  digitalWrite(progressLED, LOW);

  // take a reading
  reading=analogRead(moisture_input);

  // reverse the current
  digitalWrite(divider_top,HIGH);
  digitalWrite(divider_bottom,LOW);

  // give as much time in 'reverse' as in 'forward'
  
  delay(1000);
  digitalWrite(progressLED, HIGH);
  // stop the current
  digitalWrite(divider_bottom,LOW);
  delay(1000);
  digitalWrite(progressLED, LOW);
  delay(1000);
  digitalWrite(progressLED, HIGH);
  delay(1000);
  digitalWrite(progressLED, LOW);

  return reading;
}


void setup () {
  Serial.begin(9600);
  pinMode(progressLED, OUTPUT);
  //arduino2arduino communication 
  ET.begin(details(mydata), &Serial);
  randomSeed(analogRead(0));
}

void loop (void) {
  moisture=SoilMoisture(); // assign the result of SoilMoisture() to the global variable 'moisture'
  Serial.print("Soil moisture: ");
  Serial.print(moisture); // print the analogical measurement of the experiment
  Serial.println();
  //prepare to send data
  mydata.moisture_level = random(moisture);
  //send to other arduino
  ET.sendData();
  delay(15000);
}
