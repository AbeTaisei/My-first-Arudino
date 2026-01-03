/* ステップ2：出力テスト用コード (Arduino B) */
#include <LiquidCrystal.h>

// ピン設定 (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 13, 4, 5, 6, 7);

// LEDとスピーカー
const int PIN_R = 9;
const int PIN_G = 10;
const int PIN_B = 11;
const int PIN_SPK = 3;

void setup() {
  // 1. LCDテスト
  lcd.begin(16, 2);
  lcd.print("TEST START");
  
  // 2. LED/スピーカー設定
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_SPK, OUTPUT);
  
  delay(1000);
}

void loop() {
  // 赤
  lcd.setCursor(0, 1);
  lcd.print("Red   ");
  digitalWrite(PIN_R, HIGH); digitalWrite(PIN_G, LOW); digitalWrite(PIN_B, LOW);
  tone(PIN_SPK, 262, 100); // ド
  delay(500);

  // 緑
  lcd.setCursor(0, 1);
  lcd.print("Green ");
  digitalWrite(PIN_R, LOW); digitalWrite(PIN_G, HIGH); digitalWrite(PIN_B, LOW);
  tone(PIN_SPK, 330, 100); // ミ
  delay(500);

  // 青
  lcd.setCursor(0, 1);
  lcd.print("Blue  ");
  digitalWrite(PIN_R, LOW); digitalWrite(PIN_G, LOW); digitalWrite(PIN_B, HIGH);
  tone(PIN_SPK, 392, 100); // ソ
  delay(500);
}