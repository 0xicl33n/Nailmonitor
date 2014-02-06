//analog settings
#define p1_input 0
#define p1_div_top 2
#define p1_div_bottom 3
#define p2_input 1
#define p2_div_top 4
#define p2_div_bottom 5
#define p3_input 2
#define p3_div_top 6
#define p3_div_bottom 7
//leds
int progressLED = 13;
int badLED = 9;
int goodLED = 10;
//analog pins
const int probe1 = 0; // Analog pin 0
const int probe2 = 1; // an. pin 2
const int probe3 = 2; // an. pin 3
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

int SoilMoisture(int top, int bottom,int probe){
  int reading;
  digitalWrite(progressLED, HIGH);
  //digitalWrite(goodLED, LOW);// clear leds
  //digitalWrite(badLED, LOW);
  
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
  reading=analogRead(probe);

  // reverse the current
  digitalWrite(top,HIGH);
  digitalWrite(bottom,LOW);

  // give as much time in 'reverse' as in 'forward'
  
  delay(1000);
  digitalWrite(progressLED, HIGH);
  // stop the current
  //digitalWrite(top, LOW);
  digitalWrite(bottom,LOW);
  delay(1000);
  digitalWrite(progressLED, LOW);
  delay(1000);
  digitalWrite(progressLED,HIGH);
  delay(1000);
  digitalWrite(progressLED, LOW);

  return reading;
}

void setup() {
  Serial.begin(9600);
  pinMode(progressLED, OUTPUT);
  pinMode(goodLED, OUTPUT);
  pinMode(badLED,OUTPUT);
}

void loop (void) {
  delay(30000);
  moisture=SoilMoisture(p1_div_top, p1_div_bottom, p1_input); // assign the result of SoilMoisture() to the global variable 'moisture'
  Serial.print("[*] Probe 1 moisture: ");
  Serial.print(moisture); // print the analogical measurement of the experiment
  Serial.println();
  delay(30000);
  moisture=0;
  moisture=SoilMoisture(p2_div_top, p2_div_bottom, p2_input);
  Serial.print("[*] Probe 2 mositure: ");
  Serial.print(moisture);
  Serial.println();
  delay(30000);
  moisture=0;
  moisture=SoilMoisture(p3_div_top, p3_div_bottom, p3_input);
  Serial.print("[*] Probe 3 mositure: ");
  Serial.print(moisture);
  Serial.println();
  delay(2000);
  /*if (moisture >= 300)
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
  }*/    
}
