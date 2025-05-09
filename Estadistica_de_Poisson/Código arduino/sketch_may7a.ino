
int contador = 0;
int pin = 8;

long t = 0;

long t0 = 0;


void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);

  t0 = 0;

}

void loop() {
  if (digitalRead(pin)==1){
    contador++;
    //Serial.println(contador);
    //delay(10);

  }

if (contador == 3) {

  t = millis()-t0;
  // Serial.print(t0);
  // Serial.print(',');
  // Serial.print(millis());
  // Serial.print(',');
  Serial.println(t);
  contador = 0;
  t0 = millis();
}




}
