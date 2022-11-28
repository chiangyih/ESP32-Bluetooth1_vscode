#include <Arduino.h>
#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  Serial.begin(115200);
  BT.begin("tsengBT");   //藍芽顯示名稱,請修改為自訂名稱  //修改第二次
}

void loop() {
  
  while (Serial.available()) {   //檢查序列內是否有資料
    String Sdata = Serial.readString();   //讀取序列資料
    BT.println(Sdata);   //傳輸給藍芽
  }
  
  while (BT.available()) {   //檢查藍芽內是否有資料
    String BTdata = BT.readString();    //讀取藍芽資料
    Serial.println(BTdata);   //顯示在序列視窗
  }
  delay(1);
}