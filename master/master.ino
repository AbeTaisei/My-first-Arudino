/* ステップ1：入力テスト用コード */
// このコードは配線確認用です。本番用ではありません。

const int PIN_BUTTON = 2;
const int PIN_CDS = A0;
const int PIN_TEMP = A1;

void setup() {
  Serial.begin(9600); // パソコンと通信開始
  pinMode(PIN_BUTTON, INPUT_PULLUP); // 内部抵抗を有効化
  Serial.println("--- SENSOR TEST START ---");
}

void loop() {
  // 1. ボタンの状態を読む (0=押されている, 1=離している)
  int btnState = digitalRead(PIN_BUTTON);
  
  // 2. センサーの値を見る (0〜1023)
  int cdsValue = analogRead(PIN_CDS);
  int tempValue = analogRead(PIN_TEMP);

  // 3. 画面に表示
  Serial.print("Button: ");
  if (btnState == LOW) {
    Serial.print("ON! "); // 押した時
  } else {
    Serial.print("--- "); // 離した時
  }

  Serial.print(" | Light: ");
  Serial.print(cdsValue);
  
  Serial.print(" | Temp(Analog): ");
  Serial.println(tempValue);

  delay(500); // 0.5秒ごとに更新
}