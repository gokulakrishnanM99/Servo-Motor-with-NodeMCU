#define BLYNK_PRINT Serial
#define BLYNK_DEBUG
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
Servo servo1;
Servo servo2;
int a;
int b;
int servopin1=D1;
int servopin2=D2;
BLYNK_WRITE(V1){
  a=param.asInt();
}
BLYNK_WRITE(V2){
  b=param.asInt();
}
char auth[] = ""; /*Authentication token*/
char ssid[] = ""; /*WiFi name*/
char pass[] = ""; /*WiFi password*/
void setup()
{
  servo1.attach(servopin1,500,2400);
  servo2.attach(servopin2,500,2400);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  Blynk.run();
  servo1.write(a);
  delay(100);
  servo2.write(b);
  delay(100);
}
