// Motor pinleri
int motor1_IN1 = 3;  // Sol motor ileri
int motor1_IN2 = 4;  // Sol motor geri
int motor2_IN3 = 5;  // Sağ motor ileri
int motor2_IN4 = 6;  // Sağ motor geri
int emA=9;
int emB=10;
char gelenVeri;  // Bluetooth'tan gelen karakter

void setup() {
  // Motor pinleri çıkış olarak ayarlanıyor
  pinMode(motor1_IN1, OUTPUT);
  pinMode(motor1_IN2, OUTPUT);
  pinMode(motor2_IN3, OUTPUT);
  pinMode(motor2_IN4, OUTPUT);
  pinMode(emA, OUTPUT);
  pinMode(emB, OUTPUT);
  // Seri haberleşme başlatılıyor (Bluetooth ile)
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    gelenVeri = Serial.read();
    Serial.println(gelenVeri);  // Debug için

    switch (gelenVeri) {
      case 'F':  // İleri
        ileriGit();
        break;
      case 'B':  // Geri
        geriGit();
        break;
      case 'L':  // Sola dön
        solaDon();
        break;
      case 'R':  // Sağa dön
        sagaDon();
        break;
      case 'y':  // Dur
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
