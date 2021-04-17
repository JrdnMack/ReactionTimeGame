// ARDUINO REACTION TIMER
// include the library code:
// Adding LCD screen

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// declare button pin
const int button = 2;
const int button2 = 3;

// declare varible
double reaction = 0;
unsigned long time = 0;

// declare output LED's
const int stage = 5;
const int amber1 = 6;
const int amber2 = 7;
const int amber3 = 8;
const int green = 9;
const int red = 10;
const int stage2 = 4;
const int green2 = 11;
const int red2 = 12;

// declare fuctions
void Start();

void setup()
{
  // for a random wait before start
  // set up the lcd's number of columns and rows: 
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Hold Button to"); // Display message on LCD screen
  lcd.setCursor(0, 1); // Move to second line
  lcd.print("start.");
  // Print a message to the lcd.
  Serial.println("Drag Racing Tree!"); 
  // button pin
  pinMode(button, INPUT);
  // light pins
  pinMode(stage, OUTPUT);
  pinMode(amber1, OUTPUT);
  pinMode(amber2, OUTPUT);
  pinMode(amber3, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(stage2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red2, OUTPUT);
}

void loop() 
{

  if(digitalRead(button)==HIGH)
  {
    Serial.println("Burn Out");
    lcd.clear();
    lcd.print("Get Ready!");
    digitalWrite(stage, LOW);
    digitalWrite(amber1, HIGH);
    digitalWrite(amber2, HIGH);
    digitalWrite(amber3, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
  }
  

  
  if(digitalRead(button)== HIGH)
    {
      delay(random(500,2000));
      Serial.println("               ");
      Start();
    }
}

void Start()
{              
  digitalWrite(stage, HIGH);
  digitalWrite(amber1, LOW);
  digitalWrite(amber2, HIGH);
  digitalWrite(amber3, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(stage, HIGH);
  digitalWrite(amber1, HIGH);
  digitalWrite(amber2, LOW);
  digitalWrite(amber3, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(stage, HIGH);
  digitalWrite(amber1, HIGH);
  digitalWrite(amber2, HIGH);
  digitalWrite(amber3, LOW); time = millis(); // start timing on the third amber
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  
  // with while loop for the delay
  while( ((millis() - time)<499.9)&&(digitalRead(button) == HIGH))
  {// purposly left blank // used for an active delay
  }
  if(digitalRead(button) == LOW )
  {
    digitalWrite(stage, HIGH);
    digitalWrite(amber1, HIGH);
    digitalWrite(amber2, HIGH);
    digitalWrite(amber3, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    reaction = ((millis() - time));
    reaction = reaction * .001;
    Serial.println(reaction,4);
    Serial.println(" sec. FAIL");
    lcd.print(reaction,3);
    lcd.print(" sec. FAIL");
    delay(2000);
  }
  
  if(digitalRead(button) == HIGH )
  {
    digitalWrite(stage, HIGH);
    digitalWrite(amber1, HIGH);
    digitalWrite(amber2, HIGH);
    digitalWrite(amber3, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    while(digitalRead(button) == HIGH )
    {
      if(digitalRead(button) == LOW )
      {
      reaction = ((millis() - time));
      reaction = reaction * .001;
      Serial.println(reaction,3);
      Serial.println(" sec.");
      lcd.print(reaction,3);
      lcd.print(" sec.");
      }
     }
    delay(5000);
   
  }
}
