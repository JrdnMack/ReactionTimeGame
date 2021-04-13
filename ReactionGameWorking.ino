int ledPin = 5;
int ledPin2 = 6;
int ledPin3 = 7;
int ledPin4 = 8;
int ledPin5 = 9;
int ledPin6 = 10;
int sensorPin1 = 2;
int long ranDelay = 0;
int sensorValue = 0;
float realTime;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(sensorPin1, INPUT);
}

void loop(){
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("Push the button to start game");
  
  while (digitalRead(sensorPin1)== 0) {
  }
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("Get Ready!");
  delay(1000);
  Serial.println("Get Set!");
  delay(1000);
  ranDelay = random(5000);
  delay(ranDelay);
  Serial.println("Go!");
  

  // Turns on the blue light.
  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin2, LOW);
  delay(500);
  digitalWrite(ledPin3, LOW);
  delay(500);
  digitalWrite(ledPin4, LOW);
  delay(500);
  digitalWrite(ledPin5, LOW);
  realTime = millis();
  
  
  while (digitalRead(sensorPin1)== 1) {
    
  }
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
 //Turns all the lights off.
  
  Serial.println("Your time was");
  realTime = millis()-realTime;
  Serial.print(realTime/1000,3);
  Serial.println(" seconds");
 delay(2000); 
}
