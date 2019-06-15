#define motor 3
#define motor2 2
void setup() {
  // put your setup code here, to run once:
  pinMode(motor, OUTPUT);
  pinMode(motor2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor2, HIGH);
  digitalWrite(motor,LOW);
  delay(5000);
  delay(0500);
  digitalWrite(motor, HIGH);
  digitalWrite(motor2,LOW);
  delay(5000);
  delay(0500);
}
