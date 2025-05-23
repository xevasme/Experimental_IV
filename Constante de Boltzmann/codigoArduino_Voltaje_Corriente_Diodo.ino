const int SALIDA = 5;
float VTotal = 0.0f;
float VDiodo = 0.0f;
const float resistencia = 315;

void setup() {
  // put your setup code here, to run once:
  pinMode(SALIDA, OUTPUT);
  Serial.begin(115200);
  Serial.println("PWM,VTotal,VDiodo,CDiodo");
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int pwmVal = 0; pwmVal <= 255; pwmVal += 5) {
      analogWrite(SALIDA, pwmVal);
      delay(50);
      VTotal = ((float)analogRead(A8)) * 5.0 / 1023.0;
      VDiodo = ((float)analogRead(A9)) * 5.0 / 1023.0;
      float corriente = (VTotal - VDiodo) / resistencia;

      Serial.print(pwmVal);
      Serial.print(",");
      Serial.print(VTotal);
      Serial.print(",");
      Serial.print(VDiodo);
      Serial.print(",");
      Serial.println(corriente * 1000);
  }
}
