/*Author: Kevin Ryan on 11/19/2014
**Credit to Ken Shirriff for IRremote Library*/



// declare button pin
const int button = 2;
int ledPins[] ={
4,5,6,7,8,9,10};
int pinCount = 7;


void setup()
{
for (int thisPin = 0; thisPin < pinCount; thisPin++) {
pinMode(ledPins[thisPin], OUTPUT);
}
Serial.begin(9600);
//Starts the IR receiver
}

void loop() {



//Triggers Launch Sequence Automatically
delay(1000);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
delay(300);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
//Simulates Perfect Launch
digitalWrite(9, HIGH);
}



delay(1000);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
delay(300);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
//Simulates a False Start
digitalWrite(10, HIGH);
}


//Resets Last Two LED’s
digitalWrite(9, LOW);
digitalWrite(10, LOW);
}
//Receive’s the next value
}


 
