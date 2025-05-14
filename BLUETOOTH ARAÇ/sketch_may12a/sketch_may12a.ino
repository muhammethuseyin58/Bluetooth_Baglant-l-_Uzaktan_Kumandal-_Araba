// Motor pinleri
int motor1_IN1 = 3;  
int motor1_IN2 = 4;  
int motor2_IN3 = 5;  
int motor2_IN4 = 6;  
int emA=9;
int emB=10;
char gelenVeri;  

void setup() {
 
  pinMode(motor1_IN1, OUTPUT);
  pinMode(motor1_IN2, OUTPUT);
  pinMode(motor2_IN3, OUTPUT);
  pinMode(motor2_IN4, OUTPUT);
  pinMode(emA, OUTPUT);
  pinMode(emB, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    gelenVeri = Serial.read();
    Serial.println(gelenVeri);  

    switch (gelenVeri) {
      case 'F': 
        ileriGit();
        break;
      case 'B':  
        geriGit();
        break;
      case 'L': 
        solaDon();
        break;
      case 'R':  
        sagaDon();
        break;
      case 'y': 
        dur();
        break;
    }
  }
}

// Fonksiyonlar

void ileriGit() {
   digitalWrite(emA, HIGH);
    digitalWrite(emB, HIGH);
  digitalWrite(motor1_IN1, HIGH);
  digitalWrite(motor1_IN2, LOW);
  digitalWrite(motor2_IN3, HIGH);
  digitalWrite(motor2_IN4, LOW);
}

void geriGit() {
  digitalWrite(emA, HIGH);
    digitalWrite(emB, HIGH);
  digitalWrite(motor1_IN1, LOW);
  digitalWrite(motor1_IN2, HIGH);
  digitalWrite(motor2_IN3, LOW);
  digitalWrite(motor2_IN4, HIGH);
}

void solaDon() {
  digitalWrite(emA, HIGH);
    digitalWrite(emB, HIGH);
  digitalWrite(motor1_IN1, LOW);
  digitalWrite(motor1_IN2, HIGH);
  digitalWrite(motor2_IN3, HIGH);
  digitalWrite(motor2_IN4, LOW);
}

void sagaDon() {
  digitalWrite(emA, HIGH);
    digitalWrite(emB, HIGH);
  digitalWrite(motor1_IN1, HIGH);
  digitalWrite(motor1_IN2, LOW);
  digitalWrite(motor2_IN3, LOW);
  digitalWrite(motor2_IN4, HIGH);
}

void dur() {
  digitalWrite(emA, LOW);
    digitalWrite(emB, LOW);
  digitalWrite(motor1_IN1, LOW);
  digitalWrite(motor1_IN2, LOW);
  digitalWrite(motor2_IN3, LOW);
  digitalWrite(motor2_IN4, LOW);
}
