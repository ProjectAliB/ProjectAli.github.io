int x;
int y;
#define pot A0
#define mot1 9

void setup(){
  pinMode(pot, INPUT);
  pinMode(mot1, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  delay(50);
  x = analogRead(pot);
  y = map(x, 0, 1023, 0, 255);  // Use the map function for better scaling
  analogWrite(mot1, y);
  Serial.println(y);
  delay(250);  // Add a small delay to avoid rapid serial prints
}