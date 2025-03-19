#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define pulsePin A0

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial esp8266(10, 11); // RX, TX

String apiKey = "PH3VEAU4UHL93NZW";
const char* ssid = "CURAJ CAMPUS CONNECT";
const char* password = "011822";

void setup() {
  Serial.begin(9600);
  esp8266.begin(115200);
  dht.begin();
  delay(2000);

  sendCommand("AT", 2000);
  sendCommand("AT+RST", 2000);
  sendCommand("AT+CWMODE=1", 2000);
  sendCommand("AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"", 6000);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int pulseValue = analogRead(pulsePin);
  float heartRate = map(pulseValue, 0, 1023, 60, 120);

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" °C | Humidity: "); Serial.print(hum);
  Serial.print(" % | Heart Rate: "); Serial.print(heartRate); Serial.println(" bpm");

  String data = "GET https://api.thingspeak.com/update?api_key=" + apiKey +
                "&field1=" + String(temp) +
                "&field2=" + String(hum) +
                "&field3=" + String(heartRate);

  sendCommand("AT+CIPMUX=1", 2000);
  sendCommand("AT+CIPSTART=0,\"TCP\",\"api.thingspeak.com\",80", 3000);
  sendCommand("AT+CIPSEND=0," + String(data.length() + 4), 2000);
  esp8266.println(data);
  delay(3000);
  sendCommand("AT+CIPCLOSE=0", 1500);

  delay(20000);
}

void sendCommand(String command, const int timeout) {
  String response = "";
  esp8266.println(command);
  long int time = millis();
  while ((time + timeout) > millis()) {
    while (esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }
  Serial.println(response);
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
