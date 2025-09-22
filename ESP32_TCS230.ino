// Módulo Sensor De Color Tcs230 Tcs3200


// Pines conectados al ESP32
#define S0 26
#define S1 25
#define S2 32
#define S3 35
#define OUT_PIN 33

void setup() {
Serial.begin(115200);

pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
pinMode(OUT_PIN, INPUT);

// Configurar escala de frecuencia (ej: 20%)
digitalWrite(S0, HIGH);
digitalWrite(S1, LOW);
}

unsigned long readColorFrequency(int s2State, int s3State) {
digitalWrite(S2, s2State);
digitalWrite(S3, s3State);
delay(50); // tiempo de estabilización

// Medir duración del pulso (en microsegundos)
unsigned long duration = pulseIn(OUT_PIN, LOW);
if (duration == 0) return 0;

return 1000000UL / duration; // convertir a frecuencia aproximada
}

void loop() {
unsigned long red = readColorFrequency(LOW, LOW); // filtro rojo
unsigned long blue = readColorFrequency(LOW, HIGH); // filtro azul
unsigned long green = readColorFrequency(HIGH, HIGH); // filtro verde

Serial.print("Rojo: ");
Serial.print(red);
Serial.print(" Verde: ");
Serial.print(green);
Serial.print(" Azul: ");
Serial.println(blue);

delay(500);
}
