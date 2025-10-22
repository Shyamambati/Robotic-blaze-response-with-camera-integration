#define FLAME_SENSOR1 7
#define FLAME_SENSOR2 8
#define RELAY_PIN 9 

int m1a = 10;
int m1b = 11  ;
int m2a = 5;
int m2b = 6;


char val;
int pos = 1;

void setup()  {  
  Serial.begin(9600);
  pinMode(m1a, OUTPUT);   
  pinMode(m1b, OUTPUT);  
  pinMode(m2a, OUTPUT);  
  pinMode(m2b, OUTPUT);  

  pinMode(FLAME_SENSOR1, INPUT);
  pinMode(FLAME_SENSOR2, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

}

void loop() {

  bool flameDetected1 = digitalRead(FLAME_SENSOR1) == LOW; // Flame detection (LOW signal)
  bool flameDetected2 = digitalRead(FLAME_SENSOR2) == LOW; // Flame detection (LOW signal)

  if (flameDetected1 || flameDetected2) {
    digitalWrite(RELAY_PIN, HIGH); // Turn on relay
    Serial.println("Flame detected! Relay ON");
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off relay
    Serial.println("No flame detected. Relay OFF");
  }
  
  while (Serial.available() > 1){
  val = Serial.read();
  Serial.println(val);
  if( val == 'F') {    // Forward
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW); 
    }
  else if(val == 'B'){  // Backward
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
    }
  else if(val == 'L')  { //Left
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
  else if(val == 'R') {  //Right
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
  else if(val == 'S') { //Stop
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    val = " "; 
    }
  else if(val == 'K') { //Backward Right
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
  else if(val == 'X') {//Backward Left
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    }

  else { //Stop
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    val = " ";
    }
}
}
