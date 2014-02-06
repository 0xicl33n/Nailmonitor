#include <EasyTransfer.h>

//create object
EasyTransfer ET; 

struct SEND_DATA_STRUCTURE{
  int progressLED;
  int badLED;
  int goodLED;
  int prettyDry;
  int moisture_level;
};
SEND_DATA_STRUCTURE mydata;

void setup(){
  Serial.begin(9600);
  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc. 
  ET.begin(details(mydata), &Serial);
  
}

void loop(){
  //check and see if a data packet has come in. 
  if(ET.receiveData()){
    //this is how you access the variables. [name of the group].[variable name]
    //since we have data, we will blink it out. 
    for(int i = mydata.moisture_level; i>0; i--){
      Serial.print("Soil moisture: ");
      Serial.print(mydata.moisture_level);

    }
  }
  }
}
