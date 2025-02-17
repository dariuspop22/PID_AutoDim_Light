#include <PID_v1.h>

#define LDR_PIN A0    // Pinul ADC unde citim luminozitatea
#define LED_PIN 2     // GPIO2 (D4) - LED PWM

int lightThreshold = 400; // Prag de lumină (ajustează după testare)
double lightLevel, output, setpoint;

// Constante PID optimizate pentru ajustare mai fină
double Kp = 1.2, Ki = 0.4, Kd = 0.2;
PID myPID(&lightLevel, &output, &setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    analogWrite(LED_PIN, 0); // Inițial LED-ul este stins

    setpoint = lightThreshold;
    myPID.SetMode(AUTOMATIC);
    myPID.SetOutputLimits(0, 255); // Limităm output-ul la intervalul PWM
}

void loop() {
    lightLevel = analogRead(LDR_PIN); // Citește senzorul de lumină
    Serial.print("Light Level: ");
    Serial.println(lightLevel);

    myPID.Compute();
    int pwmValue = map(output, 0, 255, 0, 255); // Convertim PID output la PWM
    pwmValue = constrain(pwmValue, 0, 255); // Ne asigurăm că rămâne în interval
    analogWrite(LED_PIN, pwmValue);

    Serial.print("LED Brightness: ");
    Serial.println(pwmValue);

    delay(300); // Delay mai mare pentru reglaj mai stabil
}
