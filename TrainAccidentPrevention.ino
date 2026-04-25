const int trigPin = 12;
const int echoPin = 13;
const int LED1 = A0;
const int LED2 = A1;
const int LED3 = A2;
const int LED4 = A3;
const int LED5 = A4;
const int LED6 = A5;
const int LED7 = 2;
const int buzzer = 3;

int duration = 0;
int distance = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;

  // Turn on LEDs progressively as obstacle gets closer
  digitalWrite(LED1, distance <= 7  ? HIGH : LOW);
  digitalWrite(LED2, distance <= 14 ? HIGH : LOW);
  digitalWrite(LED3, distance <= 21 ? HIGH : LOW);
  digitalWrite(LED4, distance <= 28 ? HIGH : LOW);
  digitalWrite(LED5, distance <= 35 ? HIGH : LOW);
  digitalWrite(LED6, distance <= 42 ? HIGH : LOW);
  digitalWrite(LED7, distance <= 49 ? HIGH : LOW);

  // Activate buzzer if obstacle detected within 49cm
  if (distance <= 49) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);
}
