#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <LiquidCrystal_I2C.h>

// WiFi credentials
const char* ssid = "HI";
const char* password = "00000000";

// Telegram credentials
#define BOT_TOKEN "8786612082:AAHKV_wKKqC-4QD2l2mu-ThMU_fKxWF5qYA"
#define CHAT_ID "6286745482"

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
#define VOLTAGE_PIN 34
#define LDR_PIN 25
#define LED_LDR 26
#define LED_VOLT 27

// Variables
float voltage = 0.0;
unsigned long lastTelegramTime = 0;
unsigned long previousMillisLED = 0;
const int ledBlinkInterval = 400;  // Blink interval in ms

void setup() {
  Serial.begin(115200);

  pinMode(LDR_PIN, INPUT);
  pinMode(LED_LDR, OUTPUT);
  pinMode(LED_VOLT, OUTPUT);

  lcd.begin();
  lcd.backlight();

  // Improve ADC accuracy for low voltages
  analogSetAttenuation(ADC_11db);       // 0-3.3V full range
  analogReadResolution(12);             // 12-bit ADC (0-4095)

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi");
  client.setInsecure();

  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {

  // ---------------- Voltage Reading ----------------
  int total = 0;
  for (int i = 0; i < 50; i++) {   // Average 50 samples for stability
    total += analogRead(VOLTAGE_PIN);
  }
  int sensorValue = total / 50;

  // Adjust factor based on your voltage sensor module
  voltage = (sensorValue / 4095.0) * 3.3 * 2;  

  Serial.print("Raw: ");
  Serial.print(sensorValue);
  Serial.print("  Voltage: ");
  Serial.println(voltage);

  // ---------------- LCD Display ----------------
  lcd.setCursor(0, 0);
  lcd.print("Voltage:");
  lcd.setCursor(0, 1);
  lcd.print(voltage, 2);   // show 2 decimals
  lcd.print(" V   ");

  // ---------------- Voltage LED Blink ----------------
  unsigned long currentMillis = millis();
  if (voltage > 0.05) {   // detect low voltage threshold
    if (currentMillis - previousMillisLED >= ledBlinkInterval) {
      previousMillisLED = currentMillis;
      digitalWrite(LED_VOLT, !digitalRead(LED_VOLT)); // toggle
    }
  } else {
    digitalWrite(LED_VOLT, LOW);
  }

  // ---------------- LDR Logic ----------------
  int ldrState = digitalRead(LDR_PIN);
  digitalWrite(LED_LDR, ldrState == HIGH ? HIGH : LOW);

  // ---------------- Telegram Update ----------------
  if (currentMillis - lastTelegramTime > 5000) { // every 5 sec

    String message = "Status Update:\n";
    message += "Voltage: " + String(voltage, 2) + " V\n";
    message += "LDR: " + String(ldrState == LOW ? "Dark" : "Light") + "\n";
    message += "LED: " + String(digitalRead(LED_LDR) ? "ON" : "OFF");

    bot.sendMessage(CHAT_ID, message, "");
    lastTelegramTime = currentMillis;
  }

  delay(200);  // Small delay for loop stability
}
