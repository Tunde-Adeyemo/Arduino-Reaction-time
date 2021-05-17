/*
 Reactm1  
O Adeyemo April 01 2021
 
 This code is designed to function with a microswitch reaction time circuit.
 it may be distributed under GNU general licence.

 */
 
int ledPin = 5;
int buttonApin = 11;
unsigned long sc,t,pt;
float rtn;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);    

  digitalWrite(ledPin, LOW);
  Serial.begin(9600);  
}

void loop() 
{   
  randomSeed(millis());
  t=random(10*1000);
  delay(t);
  digitalWrite(ledPin, HIGH);
  sc=millis();
  while(digitalRead(buttonApin) == HIGH)
  {
    continue;
  }
  digitalWrite(ledPin, LOW);
  pt=millis();  
  rtn = (pt-sc)/1000.0;
  Serial.print("time ");  
  Serial.print(rtn,2);
  Serial.println(" s");
  delay(2*1000);   
}
/*// constants won't change. Used here to set a pin number:
const int ledPin =  LED_BUILTIN;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}*/
