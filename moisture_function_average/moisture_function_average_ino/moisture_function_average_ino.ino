//analog inputs
#define moisture_input 0
#define divider_top 2
#define divider_bottom 3
//analog settings
const int VAL_PROBE = 0; // Analog pin 0
//leds
int progressLED = 13;
int badLED = 9;
int goodLED = 10;
// reply #7 is where this code comes from
//http://forum.arduino.cc/index.php/topic,37975.0.html
/*



           digital 2---*
                 |
                 \
                 /
                 \ R1
                 /
                 |
                 |
         analog 0----*
                 |
                 |
                 *----> nail 1
                 
                 *----> nail 2
                 |
                 |
                 |
           digital 3---*
*/

//moisture levels
const int air = 0;
const int damp = 250;
const int wet = 300;
//
int moisture; // analogical value obtained from the experiment

int SoilMoisture(int top,int bottom, int probe){
  int i;
  int reading = 0;
  for (i = 0; i < 5 ; i++){ //take 5 readings
    
    digitalWrite(progressLED, HIGH);
    digitalWrite(goodLED, LOW);// clear leds
    digitalWrite(badLED, LOW);
  
  // set driver pins to outputs
    pinMode(top,OUTPUT);
    pinMode(bottom,OUTPUT);

  // drive a current through the divider in one direction
    digitalWrite(top,LOW);
    digitalWrite(bottom,HIGH);

  // wait a moment for capacitance effects to settle
    delay(1000);
    digitalWrite(progressLED, LOW);

  // take a reading
    reading=analogRead(probe) + reading;

  // reverse the current
  digitalWrite(top,HIGH);
  digitalWrite(bottom,LOW);

  // give as much time in 'reverse' as in 'forward'
  
    delay(1000);
    digitalWrite(progressLED, HIGH);
  // stop the current
    digitalWrite(divider_bottom,LOW);
    delay(1000);
    digitalWrite(progressLED, LOW);
    delay(1000);
    digitalWrite(progressLED,HIGH);
    delay(1000);
    digitalWrite(progressLED, LOW);
    //final delay before next reading
    delay(1000);
  }
  reading = reading / 5; //get average
  return reading;
}


void setup () {
  Serial.begin(9600);
  pinMode(progressLED, OUTPUT);
  pinMode(goodLED, OUTPUT);
  pinMode(badLED,OUTPUT);
}

void loop (void) {
  moisture=SoilMoisture(divider_top,divider_bottom,moisture_input); // assign the result of SoilMoisture() to the global variable 'moisture'
  Serial.print("[*] Soil moisture: ");
  Serial.print(moisture); // print the analogical measurement of the experiment
  Serial.println();
  if (moisture >= 300)
  {
    digitalWrite(goodLED, HIGH);
    digitalWrite(badLED, LOW);
    Serial.println("Moisture levels are good.");
    delay(300000);
  }
  else if (moisture = 0)
  {
    digitalWrite(badLED, LOW);
    digitalWrite(goodLED, LOW);
    Serial.println("We arent even in the dirt.. Test not valid.");
    delay(300000);
  }
  else
  {
    digitalWrite(badLED, HIGH);
    digitalWrite(goodLED, LOW);
    Serial.println("Its very dry. Please water me :(");
    delay(300000);
  }
    
}

